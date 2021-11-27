#include <iostream>
#include <vm/core/req/handler.hpp>
#include <vm/core/req/kind.hpp>
#include <vm/core/req/queue.hpp>
#include <vm/mem/chunk.hpp>
#include <vm/mem/device.hpp>

int main() {
  vm::MemoryDevice<256> mem;
  // auto test = vm::MemoryChunk(mem, mem.get_base(), 64);

  vm::RequestHandler<vm::RequestKind::MEMORY> handler;
}
