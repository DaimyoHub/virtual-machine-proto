#include <utility>

template <class first_t, class... arg_ts>
void RTDebug::out_with_kind(DebugKind kind, first_t&& first,
                            arg_ts&&... args) const {
  if (static_cast<unsigned int>(kind) <
      static_cast<unsigned int>(disabled_kind_)) {
    output_stream_ << first;
    ((output_stream_ << args), ...);
  }
}

template <class first_t, class... arg_ts>
void RTDebug::out(first_t&& first, arg_ts&&... args) const {
  out_with_kind(kind_, std::forward<first_t>(first),
                std::forward<arg_ts>(args)...);
}

template <class arg_t>
RTDebug& operator<<(RTDebug& debug_handle, arg_t&& data) {
  debug_handle.out(std::forward<arg_t>(data));
  return debug_handle;
}