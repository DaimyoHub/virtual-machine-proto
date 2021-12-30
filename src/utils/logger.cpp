#include <iostream>
#include <ostream>
#include <sstream>
#include <vm/utils/colors.hpp>
#include <vm/utils/logger.hpp>
#include <vm/utils/time.hpp>

namespace vm {

Logger::Logger(std::ostream& ostream)
    : output_stream_(ostream), enabled_level_(3) {}

Logger Logger::attach_to_stream(std::ostream& ostream) {
  return Logger(ostream);
}

std::string Logger::make_prefix(Color color) const {
  std::ostringstream oss;

  oss << color << '[' << get_current_time() << "] " << ColorTable::RESET;
  return oss.str();
}

int Logger::get_output_level() const { return enabled_level_; }

void Logger::set_output_level(int level) { enabled_level_ = level; }

std::ostream const& Logger::get_output_stream() const { return output_stream_; }

std::ostream& Logger::get_output_stream() { return output_stream_; }

}  // namespace vm