#include <iostream>
#include <vm/core/req/descriptor.hpp>
#include <vm/core/req/handler.hpp>
#include <vm/core/req/result.hpp>

namespace vm {

namespace detail {

RequestResult handle_memory_request(RequestDescriptor descriptor) {
  std::cout << "Handling memory request..." << std::endl;
  return RequestResult{};
}

}  // namespace detail

RequestResult handle_request(RequestDescriptor descriptor) {
  switch (descriptor.get_request_kind()) {
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