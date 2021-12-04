#include <vm/utils/debug.hpp>

namespace vm {

RTDebug::RTDebug(std::ostream& os)
    : output_stream_{os},
      disabled_kind_{DebugKind::__UNUSED},
      kind_{DebugKind::NOTICE} {}

void RTDebug::disable_kind(DebugKind kind) { disabled_kind_ = kind; }

void RTDebug::set_debug_kind(DebugKind kind) { kind_ = kind; }

RTDebug& operator<<(RTDebug& debug_handle, DebugKind kind) {
  debug_handle.set_debug_kind(kind);
  return debug_handle;
}

DebugKind RTDebug::get_debug_kind() const { return kind_; }

std::ostream& RTDebug::get_output_stream() { return output_stream_; }

}  // namespace vm