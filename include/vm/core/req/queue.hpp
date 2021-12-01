#ifndef VM_CORE_REQ_QUEUE_HPP
#define VM_CORE_REQ_QUEUE_HPP

#include <cassert>
#include <mutex>
#include <type_traits>
#include <vector>
#include <vm/core/req/descriptor.hpp>

namespace vm {

namespace detail {

/**
 * The request queue represents a queue stocking requests dedicated to the
 * virtual machine core. It is made to stock descriptors, so that it fits the
 * request model design. See the request descriptor class documentation for more
 * informations.
 *
 * This data structure is thread-safe. All mutation operations are protected by
 * a mutex.
 */
class RequestQueue {
 private:
  std::vector<RequestDescriptor> requests_;
  std::mutex lock_;

 public:
  RequestQueue() = default;

  RequestQueue(RequestQueue const& other);
  RequestQueue& operator=(RequestQueue const& other);

  RequestQueue(RequestQueue&& other);
  RequestQueue& operator=(RequestQueue&& other);

  ~RequestQueue();

 public:
  /// Adds a request descriptor to the head of the queue.
  void enqueue(RequestDescriptor descriptor);

  /// Checks if the queue is empty.
  bool is_empty() const;

  /// Removes the request descriptor from the queue tail.
  ///
  /// @pre The queue must not be empty.
  RequestDescriptor dequeue();

  /// Gets the count of request descriptors stocked in the queue.
  std::size_t get_size() const;
};

}  // namespace detail

}  // namespace vm

#endif  // VM_CORE_REQ_QUEUE_HPP