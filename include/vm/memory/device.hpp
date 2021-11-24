// Creation: 11/24/2021
// Copyright (c) Daimyo

#ifndef VM_MEMORY_DEVICE_HPP
#define VM_MEMORY_DEVICE_HPP

#include <array>
#include <cassert>
#include <cstddef>
#include <iterator>

namespace vm {

/**
 * Represents a memory device with a given size. It a typical and naive
 * computer architecture, it could be viewed as a classic volatile memory, with
 * which the computer works in real time, when it is powered-up.
 *
 * @tparam size_v, amount of available space (in bytes).
 */
template <std::size_t size_v>
class MemoryDevice {
 public:
  using byte_ptr = std::byte* const;

 private:
  std::array<std::byte, size_v> basic_handle_;
  byte_ptr base_;

 public:
  MemoryDevice() : basic_handle_{}, base_{&basic_handle_[0]} {}

 public:
  byte_ptr get_base() const { return base_; }

  std::size_t get_size() const { return size_v; }
};

}  // namespace vm

#endif  // VM_MEMORY_DEVICE_HPP