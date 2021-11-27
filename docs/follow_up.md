## 11/24/2021

### Done

* Started to develop the memory section
  * A memory device is partially available (there only have the minimal interface)
  * Chunks are partially available too.
    * Chunks are connected to memory devices. They begin at a given memory offset
    and finish at the end of the allocated block.

### Plan

* Create a memory (de)allocation request, request-based system.
  * Maybe base this system on an interface dedicated to request handling ?

## 11/25/2021

### Done

* Started a request system for the VM
  * The request system will be usefull in all the VM API. It is not limited to
  memory managment.
  * The system is based of a request queue progressively filled by request
  descriptors, with a given kind.

### Plan

* Continue the request system
  * Continue to implement the basic structure of the system.
  * Begin to implement the request consumer.

## 11/27/2021

### Done

* Finished the basic structure of the request system.

* Added a device ID system for device identification.
  * It is composed of two parts: the device kind (memory, serial, etc.) and a 
  unique numeric ID.

* Added a memory allocator for the virtual machine.

### Plan

