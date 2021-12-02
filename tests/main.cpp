#include <chrono>
#include <iostream>
#include <thread>
#include <vm/utils/debug.hpp>

int main() {
  using namespace vm;

  auto debug = RTDebug(std::cout);
  debug.disable_kind(DebugKind::ERROR);

  debug << DebugKind::WARNING << "Hello, world!";
}
