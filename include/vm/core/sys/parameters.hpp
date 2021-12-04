#ifndef VM_CORE_SYS_PARAMETERS_HPP
#define VM_CORE_SYS_PARAMETERS_HPP

namespace vm {

class SyscallParameters {
 public:
  SyscallParameters() = delete;

  SyscallParameters(SyscallParameters const& other) = delete;
  SyscallParameters& operator=(SyscallParameters const& other) = delete;

  SyscallParameters(SyscallParameters&& other) = default;
  SyscallParameters& operator=(SyscallParameters&& other) = default;

  virtual ~SyscallParameters() = default;

 public:
  /// Gets the count of parameters
  virtual int get_count() const;
};

}  // namespace vm

#endif  // VM_CORE_SYS_PARAMETERS_HPP