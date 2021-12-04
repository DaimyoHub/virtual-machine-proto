#ifndef VM_REQUEST_HANDLER_HPP
#define VM_REQUEST_HANDLER_HPP

#include <vm/request/descriptor.hpp>
#include <vm/request/result.hpp>
#include <vm/utils/debug.hpp>

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
RequestResult handle_request(RTDebug const& debug_handle,
                             RequestDescriptor descriptor);

}  // namespace vm

#endif  // VM_REQUEST_HANDLER_HPP
