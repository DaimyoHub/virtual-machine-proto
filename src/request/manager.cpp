#include <cassert>
#include <vm/request/handler.hpp>
#include <vm/request/manager.hpp>
#include <vm/utils/debug.hpp>

namespace vm {

RequestManager::RequestManager(RTDebug& debug_handle)
    : debug_handle_{debug_handle} {}

RequestManager::RequestManager(RequestManager&& other)
    : queue_{std::move(other.queue_)}, debug_handle_(other.debug_handle_) {}

RequestManager& RequestManager::operator=(RequestManager&& other) {
  queue_ = std::move(other.queue_);

  return *this;
}

void RequestManager::handle_last_request() {
  assert(not queue_.is_empty() &&
         "Can not handle the last request in the queue if the queue is empty.");

  auto request = queue_.dequeue();
  auto result = handle_request(debug_handle_, request);

  // TODO: send back request handling result
}

void RequestManager::enqueue_request(RequestDescriptor descriptor) {
  queue_.enqueue(descriptor);
}

RequestDescriptor RequestManager::dequeue_request() { return queue_.dequeue(); }

bool RequestManager::has_available_requests() const {
  return not queue_.is_empty();
}

RTDebug const& RequestManager::get_debug_handle() const {
  return debug_handle_;
}

RTDebug& RequestManager::get_debug_handle() { return debug_handle_; }

}  // namespace vm