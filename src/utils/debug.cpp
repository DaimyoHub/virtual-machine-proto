#include <chrono>
#include <sstream>
#include <string_view>
#include <system_error>
#include <vm/utils/colors.hpp>
#include <vm/utils/debug.hpp>
#include <vm/utils/time.hpp>

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

std::string_view RTDebug::get_color() const {
  switch (kind_) {
    case DebugKind::ERROR:
      return Colors::red;

    case DebugKind::WARNING:
      return Colors::yellow;

    case DebugKind::NOTICE:
      return Colors::green;

    case DebugKind::__UNUSED:
      return Colors::white;
  }
}

std::string RTDebug::make_prefix() const {
  std::ostringstream oss;

  auto color = get_color();
  oss << color << '[' << get_current_time() << "] " << Colors::reset;

  return oss.str();
}

}  // namespace vm