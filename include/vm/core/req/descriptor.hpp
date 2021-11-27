#ifndef VM_UTILITIES_REQUEST_DESCRIPTOR_HPP
#define VM_UTILITIES_REQUEST_DESCRIPTOR_HPP

#include <vm/core/req/kind.hpp>

namespace vm {

template <RequestKind kind_v>
class RequestDescriptor {
 public:
  int value{0};
};

}  // namespace vm

#endif  // VM_UTILITIES_REQUEST_DESCRIPTOR_HPP