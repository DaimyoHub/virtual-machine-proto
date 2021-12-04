#ifndef VM_SYSTEM_CALL_HPP
#define VM_SYSTEM_CALL_HPP

#include <memory>
#include <string_view>
#include <vm/system/kind.hpp>
#include <vm/system/parameters.hpp>

namespace vm {

class Syscall {
 private:
  SyscallKind kind_;
  std::unique_ptr<SyscallParameters> parameters_;

 public:
  Syscall(SyscallKind kind);

  Syscall(Syscall const& other) = delete;
  Syscall& operator=(Syscall const& other) = delete;

  Syscall(Syscall&& other);
  Syscall& operator=(Syscall&& other);

  ~Syscall() = default;

 public:
  /// Stores parameters in the parameters register of the syscall
  void store_parameters(std::unique_ptr<SyscallParameters> parameters);

  /// Gets the name of the syscall
  std::string_view get_name() const;

  /// Gets the category of the syscall
  SyscallKind get_category() const;

  /// Gets the kind of the syscall
  SyscallKind get_kind() const;

  /// Gets the code of the syscall
  unsigned int get_code() const;

  /// Gets the parameters for the syscall
  SyscallParameters& get_parameters();
};

}  // namespace vm

#endif  // VM_SYSTEM_CALL_HPP