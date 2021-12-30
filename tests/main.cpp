#include <iostream>
#include <vm/device.hpp>
#include <vm/request.hpp>
#include <vm/system.hpp>
#include <vm/utils.hpp>

#include "vm/request/descriptor.hpp"
#include "vm/request/kind.hpp"
#include "vm/request/manager.hpp"
#include "vm/request/runner.hpp"

int main() {
  using namespace vm;

  auto log = Logger::attach_to_stream(std::clog);
  auto man = RequestManager(log);

  man.enqueue_request(RequestDescriptor{});
  man.enqueue_request(RequestDescriptor{});
  man.enqueue_request(RequestDescriptor{});
  man.enqueue_request(RequestDescriptor{});

  run_request_manager(man);
}
