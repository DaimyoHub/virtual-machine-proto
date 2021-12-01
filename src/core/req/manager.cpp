#include <cassert>
#include <vm/core/req/handler.hpp>
#include <vm/core/req/manager.hpp>

namespace vm {

RequestManager::RequestManager(RequestManager&& other)
    : queue_{std::move(other.queue_)} {}

RequestManager& RequestManager::operator=(RequestManager&& other) {
  queue_ = std::move(other.queue_);

  return *this;
}

void RequestManager::handle_last_request() {
  assert(not queue_.is_empty() &&
         "Can not handle the last request in the queue if the queue is empty.");

  auto request = queue_.dequeue();
  auto result = handle_request(request);

  // TODO: send back request handling result
}

void RequestManager::enqueue_request(RequestDescriptor descriptor) {
  queue_.enqueue(descriptor);
}

RequestDescriptor RequestManager::dequeue_request() { return queue_.dequeue(); }

bool RequestManager::has_available_requests() const {
  return not queue_.is_empty();
}

}  // namespace vm