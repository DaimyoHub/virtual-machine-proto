#ifndef VM_CORE_REQ_MANAGER_HPP
#define VM_CORE_REQ_MANAGER_HPP

#include <vm/core/req/descriptor.hpp>
#include <vm/core/req/queue.hpp>
#include <vm/core/req/result.hpp>

namespace vm {

class RequestManager {
 private:
  detail::RequestQueue queue_;

 public:
  RequestManager() = default;

  RequestManager(RequestManager&& other);
  RequestManager& operator=(RequestManager&& other);

  RequestManager(RequestManager const&) = delete;
  RequestManager& operator=(RequestManager const&) = delete;

  virtual ~RequestManager() = default;

 public:
  /// Handles the last request in the queue.
  ///
  /// @pre The queue must not be empty.
  void handle_last_request();

  /// Adds a request to the request queue.
  void enqueue_request(RequestDescriptor descriptor);

  /// Pops the last request in the queue.
  ///
  /// @pre The queue must not be empty.
  RequestDescriptor dequeue_request();

  /// Checks if the request queue has available requests to handle.
  bool has_available_requests() const;
};

}  // namespace vm

#endif  // VM_CORE_REQ_MANAGER_HPP