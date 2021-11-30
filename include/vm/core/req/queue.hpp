#ifndef VM_CORE_REQ_QUEUE_HPP
#define VM_CORE_REQ_QUEUE_HPP

#include <cassert>
#include <mutex>
#include <type_traits>
#include <vector>
#include <vm/core/req/descriptor.hpp>

namespace vm {

/**
 * The request queue represents a queue stocking requests dedicated to the
 * virtual machine core. It is made to stock descriptors, so that it fits the
 * request model design. See the request descriptor class documentation for more
 * informations.
 *
 * This data structure is thread-safe. All mutation operations are protected by
 * a mutex.
 *
 * @tparam request_descriptor_t, the request descriptor type.
 */
template <RequestKind kind_v>
class RequestQueue {
 private:
  std::vector<RequestDescriptor<kind_v>> requests_;
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
  /**
   * Adds a request descriptor to the head of the queue.
   */
  void enqueue(RequestDescriptor<kind_v> descriptor) {
    std::lock_guard<std::mutex> lock(lock_);  // lock
    requests_.emplace_back(descriptor);
  }

  /**
   * Checks if the queue is empty.
   */
  bool is_empty() const { return requests_.empty(); }

  /**
   * Removes the request descriptor from the queue tail.
   *
   * @return request_descriptor_t, the request at the tail of the queue.
   *
   * @pre The queue must not be empty.
   */
  RequestDescriptor<kind_v> dequeue() {
    assert(not is_empty());

    std::lock_guard<std::mutex> lock(lock_);
    return *requests_.erase(requests_.begin());
  }

  /**
   * Gets the count of request descriptors stocked in the queue.
   */
  std::size_t get_size() const { return requests_.size(); }
};

}  // namespace vm

#endif  // VM_CORE_REQ_QUEUE_HPP