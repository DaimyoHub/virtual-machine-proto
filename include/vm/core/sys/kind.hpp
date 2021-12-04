#ifndef VM_CORE_SYS_KIND_HPP
#define VM_CORE_SYS_KIND_HPP

namespace vm {

enum class SyscallKind {
  MEMORY = 0x10,
  MEM_ALLOC = 0x11,
  MEM_DEALLOC = 0x12,
};

}  // namespace vm

#endif  // VM_CORE_SYS_KIND_HPP