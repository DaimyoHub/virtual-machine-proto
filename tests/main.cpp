#include <iostream>
#include <vm/core/request.hpp>
#include <vm/mem/allocator.hpp>

int main() {
  auto man = vm::RequestManager();
  man.enqueue_request(vm::RequestDescriptor{});
  man.enqueue_request(vm::RequestDescriptor{});

  auto runner = vm::RequestManagerRunner(man);
}
