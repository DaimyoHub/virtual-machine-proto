#ifndef VM_UTILS_DEBUG_HPP
#define VM_UTILS_DEBUG_HPP

#include <iostream>
#include <string_view>
#include <utility>
#include <vm/utils/colors.hpp>

namespace vm {

enum class DebugKind { NOTICE, WARNING, ERROR, __UNUSED };

class RTDebug {
 private:
  std::ostream& output_stream_;
  DebugKind disabled_kind_;
  DebugKind kind_;

 public:
  RTDebug(std::ostream& os);

  RTDebug(RTDebug const& other) = delete;
  RTDebug& operator=(RTDebug const& other) = delete;

  RTDebug(RTDebug&& other) = delete;
  RTDebug& operator=(RTDebug&& other) = delete;

  ~RTDebug() = default;

 public:
  /// Disables the handling of the given debug message kind.
  void disable_kind(DebugKind kind);

  /// Sets the default debug message kind.
  void set_debug_kind(DebugKind kind);

  /// Outs the given data to the attached output stream, with the given message
  /// kind.
  template <class first_t, class... arg_ts>
  void out_with_kind(DebugKind kind, first_t&& first, arg_ts&&... args) const;

  /// Outs the given data to the attached output stream, formatted to the
  /// default message kind.
  template <class first_t, class... arg_ts>
  void out(first_t&& first, arg_ts&&... args) const;

  /// @see RTDebug::out(first_t&& first, arg_ts&&... args)
  template <class arg_t>
  friend RTDebug const& operator<<(RTDebug const& debug_handle, arg_t&& data);

  /// @see RTDebug::set_debug_kind(DebugKind kind)
  friend RTDebug& operator<<(RTDebug& debug_handle, DebugKind kind);

  /// Gets the current debug kind
  DebugKind get_debug_kind() const;

  /// Gets the output stream attached
  std::ostream& get_output_stream();
};

#include <vm/utils/debug.ipp>

}  // namespace vm

#endif  // VM_UTILS_DEBUG_HPP