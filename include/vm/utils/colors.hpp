#ifndef VM_UTILS_COLORS_HPP
#define VM_UTILS_COLORS_HPP

#include <string_view>

namespace vm {

using Color = std::string_view;

struct ColorTable {
  ColorTable() = delete;

  ColorTable(ColorTable const& other) = delete;
  ColorTable& operator=(ColorTable const& other) = delete;

  ColorTable(ColorTable&& other) = delete;
  ColorTable& operator=(ColorTable&& other) = delete;

  static constexpr std::string_view BLACK = "\u001b[30;1m";
  static constexpr std::string_view RED = "\u001b[31;1m";
  static constexpr std::string_view GREEN = "\u001b[32;1m";
  static constexpr std::string_view YELLOW = "\u001b[33;1m";
  static constexpr std::string_view BLUE = "\u001b[34;1m";
  static constexpr std::string_view MAGENTA = "\u001b[35;1m";
  static constexpr std::string_view CYAN = "\u001b[36;1m";
  static constexpr std::string_view WHITE = "\u001b[37;1m";
  static constexpr std::string_view RESET = "\u001b[0m";

  static constexpr std::string_view NOTHING = "";
};

}  // namespace vm

#endif  // VM_UTILS_COLORS_HPP