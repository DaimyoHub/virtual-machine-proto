#ifndef VM_CORE_REQ_MANAGER_HPP
#define VM_CORE_REQ_MANAGER_HPP

#include <stdexcept>
#include <type_traits>
#include <vm/core/req/descriptor.hpp>
#include <vm/core/req/handler.hpp>
#include <vm/core/req/kind.hpp>
#include <vm/core/req/queue.hpp>
#include <vm/core/req/result.hpp>

namespace vm {

class RequestManager {
 private:
  RequestQueue queue_;

 public:
  RequestManager() : queue_{} {}

  RequestManager(RequestManager const&) = delete;
  RequestManager& operator=(RequestManager const&) = delete;

  virtual ~RequestManager() = default;

 public:
  void handle_last_request() {
    auto request = queue_.dequeue();
    auto result = vm::handle_request(request.get_request_kind(), request);

    // send_back_request_handling_result(result, descriptor.get_sender());
  }

  template <class sender_t>
  void send_back_request_handling_result(RequestResult const& result,
                                         sender_t& sender) {
    sender.push_request_handling_result(result);
  }

  void enqueue_request(RequestDescriptor descriptor) {
    queue_.enqueue(descriptor);
  }

  RequestDescriptor dequeue_request() { return queue_.dequeue(); }

  bool has_available_requests() const { return not queue_.is_empty(); }
};

}  // namespace vm

#endif  // VM_CORE_REQ_MANAGER_HPP
