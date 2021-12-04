#ifndef VM_UTILS_DEBUG_HPP
#define VM_UTILS_DEBUG_HPP

#include <chrono>
#include <iostream>
#include <string_view>
#include <utility>
#include <vm/utils/colors.hpp>
#include <vm/utils/time.hpp>

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

  /// Gets the current debug kind
  DebugKind get_debug_kind() const;

  /// Gets the output stream attached
  std::ostream& get_output_stream();

  /// Gets the color associated to the debug kind
  std::string_view get_color() const;

  /// Makes the lessage prefix according to the debug handle state
  std::string make_prefix() const;
};

template <class first_t, class... arg_ts>
void RTDebug::out_with_kind(DebugKind kind, first_t&& first,
                            arg_ts&&... args) const {
  if (static_cast<unsigned int>(kind) <
      static_cast<unsigned int>(disabled_kind_)) {
    output_stream_ << make_prefix() << first;
    ((output_stream_ << args), ...);
    output_stream_ << '\n';
  }
}

template <class first_t, class... arg_ts>
void RTDebug::out(first_t&& first, arg_ts&&... args) const {
  out_with_kind(kind_, std::forward<first_t>(first),
                std::forward<arg_ts>(args)...);
}

}  // namespace vm

#endif  // VM_UTILS_DEBUG_HPP