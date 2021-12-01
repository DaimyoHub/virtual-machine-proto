#ifndef VM_CORE_REQ_RUNNER_HPP
#define VM_CORE_REQ_RUNNER_HPP

#include <chrono>
#include <thread>
#include <vm/core/req/manager.hpp>

namespace vm {

class RequestManagerRunner {
 private:
  RequestManager& handled_manager_;
  std::thread worker_;

 public:
  RequestManagerRunner(RequestManager& manager)
      : handled_manager_{manager},
        worker_{std::thread(&RequestManagerRunner::run_manager, this)} {}

  ~RequestManagerRunner() { worker_.join(); }

  void run_manager() {
    while (true) {
      if (handled_manager_.has_available_requests())
        handled_manager_.handle_last_request();

      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  }
};

}  // namespace vm

#endif  // VM_CORE_REQ_RUNNER_HPP