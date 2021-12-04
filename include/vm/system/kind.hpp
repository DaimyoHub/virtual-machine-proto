#ifndef VM_SYSTEM_KIND_HPP
#define VM_SYSTEM_KIND_HPP

namespace vm {

enum class SyscallKind {
  MEMORY = 0x10,
  MEM_ALLOC = 0x11,
  MEM_DEALLOC = 0x12,
};

}  // namespace vm

#endif  // VM_SYSTEM_KIND_HPP