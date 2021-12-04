#include <iostream>
#include <vm/device.hpp>
#include <vm/request.hpp>
#include <vm/system.hpp>
#include <vm/utils.hpp>

int main() {
  using namespace vm;

  auto dbg = RTDebug(std::cout);
  auto man = RequestManager(dbg);

  auto req = RequestDescriptor{};

  man.enqueue_request(req);
  man.enqueue_request(req);
  man.enqueue_request(req);
  man.enqueue_request(req);

  // run_request_manager(man);

  auto x = Syscall(SyscallKind::MEM_ALLOC);
}
