#ifndef VM_UTILS_COLORS_HPP
#define VM_UTILS_COLORS_HPP

#include <string_view>

namespace vm {

struct Colors {
  Colors() = delete;

  Colors(Colors const& other) = delete;
  Colors& operator=(Colors const& other) = delete;

  Colors(Colors&& other) = delete;
  Colors& operator=(Colors&& other) = delete;

  static constexpr std::string_view black = "\u001b[30;1m";
  static constexpr std::string_view red = "\u001b[31;1m";
  static constexpr std::string_view green = "\u001b[32;1m";
  static constexpr std::string_view yellow = "\u001b[33;1m";
  static constexpr std::string_view blue = "\u001b[34;1m";
  static constexpr std::string_view magenta = "\u001b[35;1m";
  static constexpr std::string_view cyan = "\u001b[36;1m";
  static constexpr std::string_view white = "\u001b[37;1m";
  static constexpr std::string_view reset = "\u001b[0m";
};

}  // namespace vm

#endif  // VM_UTILS_COLORS_HPP