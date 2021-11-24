#include <vm/memory/chunk.hpp>
#include <vm/memory/device.hpp>

int main() {
  vm::MemoryDevice<256> mem;
  auto test = vm::MemoryChunk(mem, mem.get_base(), 64);

  return mem.get_size() / test.get_size();
}
