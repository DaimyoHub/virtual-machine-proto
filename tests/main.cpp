#include <iostream>
#include <vm/core/request.hpp>
#include <vm/utils/debug.hpp>
#include <vm/utils/time.hpp>

int main() {
  using namespace vm;

  auto dbg = RTDebug(std::cout);
  /*auto man = RequestManager(dbg);

  auto req = RequestDescriptor{};

  man.enqueue_request(req);
  man.enqueue_request(req);
  man.enqueue_request(req);
  man.enqueue_request(req);

  run_request_manager(man);*/
  dbg << DebugKind::NOTICE << "Some useless notification...";
  dbg << DebugKind::NOTICE << "Some useless notification...";
  dbg << DebugKind::NOTICE << "Some useless notification...";
  dbg << DebugKind::NOTICE << "Some useless notification...";
  dbg << DebugKind::WARNING << "Some warning";
  dbg << DebugKind::WARNING << "Some warning";
  dbg << DebugKind::NOTICE << "Some useless notification...";
  dbg << DebugKind::ERROR << "There is an error.";
  dbg << DebugKind::NOTICE << "Some notification.";
  dbg << DebugKind::NOTICE << "Some  notification.";
  dbg << DebugKind::WARNING << "Some warning";
  dbg << DebugKind::WARNING << "Some warning";
  dbg << DebugKind::ERROR << "Another error.";
}
