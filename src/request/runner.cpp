#include <vm/request/manager.hpp>
#include <vm/request/runner.hpp>

namespace vm {

namespace detail {

RequestManagerRunner::RequestManagerRunner(RequestManager& manager)
    : handled_manager_{manager},
      worker_{std::thread(&RequestManagerRunner::run_manager, this)} {}

RequestManagerRunner::~RequestManagerRunner() { worker_.join(); }

void RequestManagerRunner::run_manager() {
  while (true) {
    if (handled_manager_.has_available_requests()) {
      handled_manager_.handle_last_request();
    }
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

}  // namespace detail

void run_request_manager(RequestManager& manager) {
  auto runner = detail::RequestManagerRunner(manager);
}

}  // namespace vm