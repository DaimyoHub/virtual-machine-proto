#include <iostream>
#include <vm/core/request/kind.hpp>
#include <vm/core/request/queue.hpp>
#include <vm/mem/chunk.hpp>
#include <vm/mem/device.hpp>

int main() {
  vm::MemoryDevice<256> mem;
  // auto test = vm::MemoryChunk(mem, mem.get_base(), 64);

  vm::RequestQueue<vm::RequestDescriptor<vm::RequestKind::MEMORY>> queue;
  queue.enqueue(vm::RequestDescriptor<vm::RequestKind::MEMORY>{10});

  for (auto i{0}; i < queue.get_size(); ++i)
    std::cout << queue.dequeue().value << std::endl;
}
