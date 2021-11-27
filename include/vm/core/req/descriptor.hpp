#ifndef VM_CORE_REQ_DESCRIPTOR_HPP
#define VM_CORE_REQ_DESCRIPTOR_HPP

#include <vm/core/req/kind.hpp>

namespace vm {

template <RequestKind kind_v>
class RequestDescriptor {
 public:
  int value{0};
};

}  // namespace vm

#endif  // VM_CORE_REQ_DESCRIPTOR_HPP