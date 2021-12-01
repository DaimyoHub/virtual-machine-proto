#ifndef VM_CORE_REQ_DESCRIPTOR_HPP
#define VM_CORE_REQ_DESCRIPTOR_HPP

#include <vm/core/req/kind.hpp>

namespace vm {

class RequestDescriptor {
 private:
  RequestKind kind_;

 public:
  int value = 0;

 public:
  RequestKind get_request_kind() const { return kind_; }
};

}  // namespace vm

#endif  // VM_CORE_REQ_DESCRIPTOR_HPP