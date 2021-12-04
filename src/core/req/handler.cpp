#include <iostream>
#include <vm/core/req/descriptor.hpp>
#include <vm/core/req/handler.hpp>
#include <vm/core/req/result.hpp>
#include <vm/utils/debug.hpp>

namespace vm {

namespace detail {

RequestResult handle_memory_request(RTDebug const& debug_handle,
                                    RequestDescriptor descriptor) {
  debug_handle << "Handling memory request";
  return RequestResult{};
}

}  // namespace detail

RequestResult handle_request(RTDebug const& debug_handle,
                             RequestDescriptor descriptor) {
  switch (descriptor.get_request_kind()) {
    case RequestKind::MEMORY:
      return detail::handle_memory_request(debug_handle, descriptor);

    case RequestKind::__UNUSED:
    default:
      throw std::runtime_error(
          "Request handler not implemented for a request of kind "
          "'RequestKind::__UNUSED'.");
  }
}

}  // namespace vm