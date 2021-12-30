#include <vm/request/descriptor.hpp>
#include <vm/request/handler.hpp>
#include <vm/request/result.hpp>
#include <vm/utils/logger.hpp>

namespace vm {

namespace detail {

RequestResult handle_memory_request(Logger const& logger,
                                    RequestDescriptor descriptor) {
  logger.note("Handling memory request");
  return RequestResult{};
}

}  // namespace detail

RequestResult handle_request(Logger const& logger,
                             RequestDescriptor descriptor) {
  switch (descriptor.get_request_kind()) {
    case RequestKind::MEMORY:
      return detail::handle_memory_request(logger, descriptor);

    case RequestKind::__UNUSED:
    default:
      throw std::runtime_error(
          "Request handler not implemented for a request of kind "
          "'RequestKind::__UNUSED'.");
  }
}

}  // namespace vm