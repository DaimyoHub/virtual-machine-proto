#include <cassert>
#include <iostream>
#include <string_view>
#include <vm/core/sys/call.hpp>
#include <vm/core/sys/kind.hpp>
#include <vm/core/sys/parameters.hpp>

namespace vm {

Syscall::Syscall(SyscallKind kind) : kind_{kind}, parameters_{nullptr} {}

Syscall::Syscall(Syscall&& other)
    : kind_{other.kind_}, parameters_{std::move(other.parameters_)} {}

Syscall& Syscall::operator=(Syscall&& other) {
  parameters_ = std::move(other.parameters_);

  return *this;
}

std::string_view Syscall::get_name() const {
  // GET THE NAME
  return "";
}

SyscallKind Syscall::get_category() const {
  auto category = static_cast<unsigned char>(kind_) & 0x10;
  return static_cast<SyscallKind>(category);
}

unsigned int Syscall::get_code() const {
  return static_cast<unsigned char>(kind_);
}

SyscallParameters& Syscall::get_parameters() { return *parameters_; }

void Syscall::store_parameters(std::unique_ptr<SyscallParameters> parameters) {
  assert(parameters != nullptr);
  assert(parameters_ != nullptr);

  parameters_ = std::move(parameters);
}

SyscallKind Syscall::get_kind() const { return kind_; }

}  // namespace vm