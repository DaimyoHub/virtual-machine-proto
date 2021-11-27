#ifndef VM_CORE_DEV_DEVICE_HPP
#define VM_CORE_DEV_DEVICE_HPP

#include <vm/core/dev/id.hpp>

namespace vm {

class Device {
 private:
  DeviceID id_ = DeviceID::as_unused();

 public:
  virtual ~Device() = default;

  Device(DeviceKind kind, int id) : id_{DeviceID(kind, id)} {
    assert(id < 16 and id > 0);
  }

 public:
  DeviceID get_id() const { return id_; }
};

}  // namespace vm

#endif  // VM_CORE_DEV_DEVICE_HPP