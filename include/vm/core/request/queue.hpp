#ifndef VM_UTILITIES_REQUEST_QUEUE_HPP
#define VM_UTILITIES_REQUEST_QUEUE_HPP

#include <mutex>
#include <type_traits>
#include <vector>
#include <vm/core/request/descriptor.hpp>
#include <vm/core/request/kind.hpp>

namespace vm {

template <class request_descriptor_t>
class RequestQueue {
 private:
  std::vector<request_descriptor_t> requests_;
  std::mutex lock_;

 public:
  RequestQueue() : requests_{}, lock_{} {}

  RequestQueue(RequestQueue const& other)
      : requests_{other.requests_}, lock_{} {}

  RequestQueue& operator=(RequestQueue const& other) {
    requests_ = other.requests_;

    return *this;
  }

  RequestQueue(RequestQueue&& other)
      : requests_{std::move(other.requests_)}, lock_{std::move(other.lock_)} {}

  RequestQueue& operator=(RequestQueue&& other) {
    requests_ = std::move(other.requests_);
    lock_ = std::move(other.lock_);

    return *this;
  }

  ~RequestQueue() { requests_.clear(); }

 public:
  void enqueue(request_descriptor_t descriptor) {
    std::lock_guard<std::mutex> lock(lock_);  // lock
    requests_.emplace_back(descriptor);
  }

  bool is_empty() const { return requests_.empty(); }

  request_descriptor_t dequeue() {
    if (not is_empty()) {
      std::lock_guard<std::mutex> lock(lock_);
      requests_.erase(requests_.begin());
    }
  }

  std::size_t get_size() const { return requests_.size(); }
};

}  // namespace vm

#endif  // VM_UTILITIES_REQUEST_QUEUE_HPP