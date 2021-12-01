#include <chrono>
#include <iostream>
#include <thread>
#include <vm/core/request.hpp>
#include <vm/mem/allocator.hpp>

int main() {
  using namespace vm;

  auto man = RequestManager();

  auto desc = RequestDescriptor{};
  // desc.kind_ = RequestKin;

  man.enqueue_request(desc);

  vm::run_request_manager(man);
}
