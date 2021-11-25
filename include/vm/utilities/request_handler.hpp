#ifndef VM_UTILITIES_REQUEST_HANDLER_HPP
#define VM_UTILITIES_REQUEST_HANDLER_HPP

#include <vm/utilities/request_kind.hpp>
#include <vm/utilities/request_queue.hpp>

namespace vm {

template <RequestKind kind_v>
class RequestHandler {
 private:
  RequestQueue<kind_v> queue_;

 public:
  RequestHandler(RequestHandler const&) = delete;
  RequestHandler& operator=(RequestHandler const&) = delete;

  virtual ~RequestHandler() = default;

 public:
  RequestKind get_request_kind() const { return kind_v; }
};

}  // namespace vm

#endif  // VM_UTILITIES_REQUEST_HANDLER_HPP
