// Creation: 11/24/2021
// Copyright (c) Daimyo

#ifndef VM_MEMORY_CHUNK_HPP
#define VM_MEMORY_CHUNK_HPP

#include <cstddef>
#include <vm/memory/device.hpp>

namespace vm {

/**
 * Represents a memory page is a memory device. It is a part of the device: it
 * begins at a precise offset and ends at the byte next to the last byte
 * allocated.
 *
 * In the virtual machine, it serves as basic chunk memory for different types
 * of data-structures dedicated to a process; such as the stack, the heap, the
 * code section, etc.
 */
class MemoryChunk {
 public:
  using byte_ptr = std::byte* const;

 private:
  byte_ptr const begin_;
  std::size_t size_;

  bool is_corrupted_;

 public:
  template <std::size_t size_v>
  MemoryChunk(MemoryDevice<size_v> const& device, byte_ptr begin,
              std::size_t size)
      : begin_{begin}, size_{size}, is_corrupted_{false} {
    assert(device.get_base() == begin);
    assert(begin != nullptr);
  }

  template <std::size_t size_v>
  MemoryChunk(MemoryDevice<size_v> const& device, byte_ptr begin,
              std::byte* end)
      : begin_{begin},
        size_{static_cast<std::size_t>(std::distance(begin, end))} {
    assert(device.get_base() == begin);
    assert(begin != nullptr);
  }

 public:
  std::size_t get_size() const { return size_; }

  byte_ptr get_begin() const { return begin_; }

  bool is_corrupted() const { return is_corrupted_; }
};

}  // namespace vm

#endif  // VM_MEMORY_CHUNK_HPP