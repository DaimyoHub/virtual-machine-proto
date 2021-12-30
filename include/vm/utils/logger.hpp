#ifndef VM_UTILS_LOGGER_HPP
#define VM_UTILS_LOGGER_HPP

#include <fmt/format.h>

#include <iostream>
#include <vm/utils/colors.hpp>
#include <vm/utils/time.hpp>

namespace vm {

class Logger {
 private:
  std::ostream& output_stream_;
  int enabled_level_;

 private:
  Logger(std::ostream& ostream);

 public:
  Logger(Logger const& other) = delete;
  Logger& operator=(Logger const& other) = delete;

  Logger(Logger&& other) = delete;
  Logger& operator=(Logger&& other) = delete;

  ~Logger() = default;

  static Logger attach_to_stream(std::ostream& ostream);

 public:
  std::ostream const& get_output_stream() const;

  std::ostream& get_output_stream();

  int get_output_level() const;

  void set_output_level(int level);

  std::string make_prefix(Color color) const;

  template <class... arg_ts>
  void note(std::string_view message, arg_ts&&... args) const {
    if (get_output_level() >= 3) {
      auto current_time = get_current_time();
      output_stream_ << make_prefix(ColorTable::GREEN)
                     << fmt::format(message, std::forward<arg_ts>(args)...)
                     << '\n';
    }
  }

  template <class... arg_ts>
  void warn(std::string_view message, arg_ts&&... args) const {
    if (get_output_level() >= 2) {
      auto current_time = get_current_time();
      output_stream_ << make_prefix(ColorTable::YELLOW)
                     << fmt::format(message, std::forward<arg_ts>(args)...)
                     << '\n';
    }
  }

  template <class... arg_ts>
  void fail(std::string_view message, arg_ts&&... args) const {
    if (get_output_level() >= 1) {
      auto current_time = get_current_time();
      output_stream_ << make_prefix(ColorTable::RED)
                     << fmt::format(message, std::forward<arg_ts>(args)...)
                     << '\n';
    }
  }
};

}  // namespace vm

#endif  // VM_UTILS_LOGGER_HPP