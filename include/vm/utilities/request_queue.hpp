#ifndef VM_UTILITIES_REQUEST_QUEUE_HPP
#define VM_UTILITIES_REQUEST_QUEUE_HPP

#include <vm/utilities/request_kind.hpp>

namespace vm {

template <RequestKind kind_v>
class RequestQueue {};

}  // namespace vm

#endif  // VM_UTILITIES_REQUEST_QUEUE_HPP