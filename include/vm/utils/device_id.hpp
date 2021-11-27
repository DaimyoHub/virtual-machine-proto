#ifndef VM_UTILS_DEVICE_ID_HPP
#define VM_UTILS_DEVICE_ID_HPP

#include <cassert>
#include <cstddef>
#include <iostream>

namespace vm {

enum class DeviceKind : unsigned char { MEMORY, __UNUSED };

/**
 * Represents a simple device ID divided in two parts: the device kind, and the
 * numeric ID.
 *
 * A such device ID must be unique. That is why this class does not implement
 * any copy ctor/op= or move ctor/op=.
 */
class DeviceID {
 private:
  unsigned char raw_id_;

 public:
  /**
   * Constructs a device id from a device kind and a numeric identifier.
   */
  DeviceID(DeviceKind kind, unsigned char id) {
    assert(id < 16);
    raw_id_ = static_cast<unsigned char>(kind) | id;
  }

  DeviceID(DeviceID const& other) = delete;
  DeviceID& operator=(DeviceID const& other) = delete;

  DeviceID(DeviceID&& other) = delete;
  DeviceID& operator=(DeviceID&& other) = delete;

 public:
  /**
   * Represents the layouts of the raw id handled by this class.
   *
   */
  struct Layout {
    static constexpr unsigned char kind = 0b11110000;
    static constexpr unsigned char id = 0b00001111;
  };

  /**
   * Evaluates the kind of the ID to convert it into the concrete device kind.
   *
   * @return DeviceKind, the kind of the device.
   */
  DeviceKind eval_kind() const {
    auto kind_side = raw_id_ & Layout::kind;
    return static_cast<DeviceKind>(kind_side);
  }

  /**
   * Gets the numeric ID of the device.
   */
  int get_id() const { return raw_id_ & Layout::id; }
};

}  // namespace vm

#endif  // VM_UTILS_DEVICE_ID_HPP