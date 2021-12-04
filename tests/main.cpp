#include <iostream>
#include <vm/core/request.hpp>
#include <vm/core/sys/call.hpp>
#include <vm/core/sys/kind.hpp>
#include <vm/utils/debug.hpp>
#include <vm/utils/time.hpp>

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
