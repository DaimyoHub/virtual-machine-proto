#include <chrono>
#include <iostream>
#include <thread>
#include <vm/core/device.hpp>
#include <vm/core/req/descriptor.hpp>
#include <vm/core/req/runner.hpp>
#include <vm/core/request.hpp>

int main() {
  auto dbg = vm::RTDebug(std::cout);
  auto man = vm::RequestManager(dbg);

  auto request = vm::RequestDescriptor{};

  man.enqueue_request(vm::RequestDescriptor{});

  vm::run_request_manager(man);
}
