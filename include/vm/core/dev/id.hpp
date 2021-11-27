#ifndef VM_DEV_ID_HPP
#define VM_DEV_ID_HPP

#include <cassert>
#include <cstddef>
#include <iostream>

namespace vm {

enum class DeviceKind : unsigned char { MEMORY, UNUSED };

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
   *
   * @pre @p id must be in the ID range: strictly inferior to 16 and strictly
   * superior to 0.
   * @pre The given numeric ID must be unique.
   */
  DeviceID(DeviceKind kind, unsigned char id) {
    assert(id < 16 and id > 0);
    raw_id_ = static_cast<unsigned char>(kind) | id;
  }

  /**
   * Affects a null device ID (with kind DeviceKind::NULL) to a valid device ID.
   *
   * @pre @p other must not be an ID affected to a concrete device.
   */
  DeviceID& operator=(DeviceID other) {
    assert(eval_kind() == DeviceKind::UNUSED);

    raw_id_ = other.raw_id_;
    return *this;
  }

  DeviceID(DeviceID&& other) = delete;

  DeviceID(DeviceID const& other) : raw_id_{other.raw_id_} {}

  /**
   * Constructs an unusable ID. It may essentially be used in the declaration of
   * member variables of a class.
   */
  static DeviceID as_unused() { return DeviceID(DeviceKind::UNUSED, 0); }

 public:
  /**
   * Represents the layouts of the raw id handled by this class.
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

#endif  // VM_DEV_ID_HPP