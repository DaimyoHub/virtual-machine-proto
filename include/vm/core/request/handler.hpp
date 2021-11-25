#ifndef VM_UTILITIES_REQUEST_HANDLER_HPP
#define VM_UTILITIES_REQUEST_HANDLER_HPP

#include <stdexcept>
#include <vm/core/request/descriptor.hpp>
#include <vm/core/request/kind.hpp>
#include <vm/core/request/queue.hpp>

namespace vm {

/**
 * Represents a generic request handler.
 *
 * @tparam kind_v, the kind of request to be handled.
 */
template <RequestKind kind_v>
class RequestHandler {
 private:
  RequestQueue<RequestDescriptor<kind_v>> queue_;

 public:
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

#endif  // VM_UTILITIES_REQUEST_HANDLER_HPP
