#include <iostream>
#include <vm/core/req/handler.hpp>
#include <vm/core/req/kind.hpp>
#include <vm/core/req/queue.hpp>
#include <vm/mem/chunk.hpp>
#include <vm/mem/device.hpp>
#include <vm/utils/device_id.hpp>

int main() {
  auto mem = vm::MemoryDevice<256>(1);
  // auto test = vm::MemoryChunk(mem, mem.get_base(), 64);

  auto id = vm::DeviceID(vm::DeviceKind::MEMORY, 3);
  assert(id.eval_kind() == vm::DeviceKind::MEMORY);
  assert(id.get_id() == 3);
}
