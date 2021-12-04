#include <vm/utils/time.hpp>

namespace vm {

std::string get_current_time() {
  auto now = std::chrono::system_clock::now();
  auto time_now = std::chrono::system_clock::to_time_t(now);

  std::tm time_hints;

  char buf[80];
  time_hints = *std::localtime(&time_now);
  std::strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &time_hints);

  return buf;
}

}  // namespace vm