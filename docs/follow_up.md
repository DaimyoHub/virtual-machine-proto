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

## 12/01/2021

### Done

* Improved the request handling
  * I had a manager runner, that handles all requests in a separated thread.
  * I completed the whole request handling system, just a bit:
    * A handling result and its management system was added
    * The whole system architecture was improved, to allow the handling of
    many different request kinds at the same time. This design decision had a
    cost: the kind-specific request handling part of the system is not easily
    accessible by the user, its modification is intrusive.

### Plan

* Continue the request handling system
  * Link it to the device interface

* Think about a non-intrusive design for specific-kind request handling

* Begin the request format specification