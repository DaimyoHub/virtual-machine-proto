#ifndef VM_DEVICE_TABLE_HPP
#define VM_DEVICE_TABLE_HPP

#include <unordered_map>
#include <vm/device/device.hpp>
#include <vm/device/id.hpp>

namespace vm {

class DeviceTable {
 public:
  using device_ptr = Device*;

 private:
  std::unordered_map<DeviceID, device_ptr> devices_;

 public:
  void register_device(Device& device) {
    devices_.insert({device.get_id(), &device});
  }

  void remove_device_by_id(DeviceID id) { devices_.erase(id); }

  device_ptr get_device_by_id(DeviceID id) { return devices_[id]; }
};

}  // namespace vm

#endif  // VM_DEVICE_TABLE_HPP