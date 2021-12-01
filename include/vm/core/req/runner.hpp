#ifndef VM_CORE_REQ_RUNNER_HPP
#define VM_CORE_REQ_RUNNER_HPP

#include <chrono>
#include <thread>
#include <vm/core/req/manager.hpp>

namespace vm {

namespace detail {

class RequestManagerRunner {
 private:
  RequestManager& handled_manager_;
  std::thread worker_;

 public:
  RequestManagerRunner(RequestManager& manager);

  RequestManagerRunner(RequestManagerRunner const& other) = delete;
  RequestManagerRunner& operator=(RequestManagerRunner const& other) = delete;

  RequestManagerRunner(RequestManagerRunner&& other) = delete;
  RequestManagerRunner& operator=(RequestManagerRunner&& other) = delete;

  ~RequestManagerRunner();

  /// Runs the attached request manager in a separated thread.
  void run_manager();
};

}  // namespace detail

/// Runs the given request manager in a separated thread.
void run_request_manager(RequestManager& manager);

}  // namespace vm

#endif  // VM_CORE_REQ_RUNNER_HPP