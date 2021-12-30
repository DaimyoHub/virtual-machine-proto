#ifndef VM_REQUEST_DESCRIPTOR_HPP
#define VM_REQUEST_DESCRIPTOR_HPP

#include <vm/request/kind.hpp>

namespace vm {

class RequestDescriptor {
 private:
  RequestKind kind_ = RequestKind::MEMORY;

 public:
  int value = 0;

 public:
  RequestKind get_request_kind() const { return kind_; }
};

}  // namespace vm

#endif  // VM_REQUEST_DESCRIPTOR_HPP