#ifndef VM_REQUEST_HANDLER_HPP
#define VM_REQUEST_HANDLER_HPP

#include <vm/request/descriptor.hpp>
#include <vm/request/result.hpp>
#include <vm/utils/logger.hpp>

namespace vm {

namespace detail {

/// Handles a given memory request. This function is called by
/// vm::handle_request(...), it is made to provide a specific handling for the
/// specific memory request kind.
///
/// @return RequestResult, the result of the request treatment.
RequestResult handle_memory_request(RequestDescriptor descriptor);

}  // namespace detail

/// Handles all kinds of given requests.
///
/// @return RequestResult, the result of the treatment.
RequestResult handle_request(Logger const& logger,
                             RequestDescriptor descriptor);

}  // namespace vm

#endif  // VM_REQUEST_HANDLER_HPP
