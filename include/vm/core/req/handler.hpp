#ifndef VM_CORE_REQ_HANDLER_HPP
#define VM_CORE_REQ_HANDLER_HPP

#include <iostream>
#include <stdexcept>
#include <vm/core/req/descriptor.hpp>
#include <vm/core/req/kind.hpp>
#include <vm/core/req/result.hpp>

namespace vm {

namespace detail {

RequestResult handle_memory_request(RequestDescriptor descriptor) {
  std::cout << "Handling memory request..." << std::endl;
  return RequestResult{};
}

}  // namespace detail

RequestResult handle_request(RequestKind kind, RequestDescriptor descriptor) {
  switch (kind) {
    case RequestKind::MEMORY:
      return detail::handle_memory_request(descriptor);

    case RequestKind::__UNUSED:
    default:
      throw std::runtime_error(
          "Request handler not implemented for a request of kind "
          "'RequestKind::__UNUSED'.");
  }
}

}  // namespace vm

#endif  // VM_CORE_REQ_HANDLER_HPP
