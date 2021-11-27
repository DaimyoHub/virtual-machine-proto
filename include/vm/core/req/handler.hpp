#ifndef VM_CORE_REQ_HANDLER_HPP
#define VM_CORE_REQ_HANDLER_HPP

#include <stdexcept>
#include <vm/core/req/descriptor.hpp>
#include <vm/core/req/kind.hpp>
#include <vm/core/req/queue.hpp>

namespace vm {

/**
 * Represents a generic request handler.
 *
 * @tparam kind_v, the kind of request to be handled.
 */
template <RequestKind kind_v>
class RequestHandler {
 private:
  RequestQueue<kind_v> queue_;

 public:
  RequestHandler() : queue_{} {}

  RequestHandler(RequestHandler const&) = delete;
  RequestHandler& operator=(RequestHandler const&) = delete;

  virtual ~RequestHandler() = default;

 public:
  virtual void handle_request(RequestDescriptor<kind_v> descriptor) {
    throw std::runtime_error(
        "vm::RequestHandler<...>::handle_request(...) in "
        "'/include/vm/utilities/request_handler.hpp' not overriden.");
  }

  RequestKind get_request_kind() const { return kind_v; }

  void enqueue_request(RequestDescriptor<kind_v> descriptor) {
    queue_.enqueue(descriptor);
  }

  RequestDescriptor<kind_v> dequeue_request() { return queue_.dequeue(); }
};

}  // namespace vm

#endif  // VM_CORE_REQ_HANDLER_HPP
