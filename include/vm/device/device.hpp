#ifndef VM_DEVICE_DEVICE_HPP
#define VM_DEVICE_DEVICE_HPP

#include <vm/device/id.hpp>

namespace vm {

/**
 * Represents an interface for a device.
 */
class Device {
 private:
  DeviceID id_ = DeviceID::as_unused();

 public:
  virtual ~Device() = default;

  /**
   * Constructs the device with a given ID.
   *
   * @param kind, the kind of device.
   * @param id; the numeric ID of the device.
   */
  Device(DeviceKind kind, int id) : id_{DeviceID(kind, id)} {
    assert(id < 16 and id > 0);
  }

 public:
  /**
   * Get the numeric ID of the device.
   */
  DeviceID get_id() const { return id_; }
};

}  // namespace vm

#endif  // VM_DEVICE_DEVICE_HPP