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

  /**
   * Construct a logger attached to the given output stream.
   *
   * @param ostream, the stream attached to the logger.
   */
  static Logger attach_to_stream(std::ostream& ostream);

 public:
  /**
   * Get the attached output stream.
   */
  std::ostream const& get_output_stream() const;

  /**
   * Get the attached output stream.
   */
  std::ostream& get_output_stream();

  /**
   * Get the current output level.
   */
  int get_output_level() const;

  /**
   * Set the current output level.
   *
   * @pre level ∈ {1, 2, 3}
   */
  void set_output_level(int level);

  /**
   * Make the output prefix. It is composed of the date and the color of the
   * output level.
   *
   * @param color, the color of the output level.
   * @return std::string, the formatted prefix.
   */
  std::string make_prefix(Color color) const;

  /**
   * Output a note with a given message.
   *
   * @param message, the raw unformatted message.
   * @param args, the arguments of the message.
   */
  template <class... arg_ts>
  void note(std::string_view message, arg_ts&&... args) const {
    if (get_output_level() >= 3)
      output_stream_ << make_prefix(ColorTable::GREEN)
                     << fmt::format(message, std::forward<arg_ts>(args)...)
                     << '\n';
  }

  /**
   * Output a warning with a given message.
   *
   * @param message, the raw unformatted message.
   * @param args, the arguments of the message.
   */
  template <class... arg_ts>
  void warn(std::string_view message, arg_ts&&... args) const {
    if (get_output_level() >= 2)
      output_stream_ << make_prefix(ColorTable::YELLOW)
                     << fmt::format(message, std::forward<arg_ts>(args)...)
                     << '\n';
  }

  /**
   * Output a failure with a given message.
   *
   * @param message, the raw unformatted message.
   * @param args, the arguments of the message.
   */
  template <class... arg_ts>
  void fail(std::string_view message, arg_ts&&... args) const {
    if (get_output_level() >= 1)
      output_stream_ << make_prefix(ColorTable::RED)
                     << fmt::format(message, std::forward<arg_ts>(args)...)
                     << '\n';
  }
};

}  // namespace vm

#endif  // VM_UTILS_LOGGER_HPP