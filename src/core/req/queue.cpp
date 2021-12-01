#include <cstddef>
#include <vm/core/req/queue.hpp>

namespace vm {

namespace detail {

RequestQueue::RequestQueue(RequestQueue const& other)
    : requests_{other.requests_}, lock_{} {}

RequestQueue& RequestQueue::operator=(RequestQueue const& other) {
  requests_ = other.requests_;

  return *this;
}

RequestQueue::RequestQueue(RequestQueue&& other)
    : requests_{std::move(other.requests_)}, lock_{} {}

RequestQueue& RequestQueue::operator=(RequestQueue&& other) {
  requests_ = std::move(other.requests_);

  return *this;
}

RequestQueue::~RequestQueue() { requests_.clear(); }

void RequestQueue::enqueue(RequestDescriptor descriptor) {
  std::lock_guard<std::mutex> lock(lock_);
  requests_.emplace_back(descriptor);
}

RequestDescriptor RequestQueue::dequeue() {
  assert(not is_empty() && "Can not dequeue an empty queue.");

  std::lock_guard<std::mutex> lock(lock_);
  return *requests_.erase(requests_.begin());
}

std::size_t RequestQueue::get_size() const { return requests_.size(); }

bool RequestQueue::is_empty() const { return requests_.empty(); }

}  // namespace detail

}  // namespace vm