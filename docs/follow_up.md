## 11/24/2021

* Started to develop the memory section
  * A memory device is partially available (there only have the minimal interface)
  * Chunks are partially available too.
    * Chunks are connected to memory devices. They begin at a given memory offset
    and finish at the end of the allocated block.

## 11/25/2021

* Started a request system for the VM
  * The request system will be usefull in all the VM API. It is not limited to
  memory managment.
  * The system is based of a request queue progressively filled by request
  descriptors, with a given kind.

## 11/27/2021

* Finished the basic structure of the request system.

* Added a device ID system for device identification.
  * It is composed of two parts: the device kind (memory, serial, etc.) and a 
  unique numeric ID.

* Added a memory allocator for the virtual machine.

## 12/01/2021

* Improved the request handling
  * I had a manager runner, that handles all requests in a separated thread.
  * I completed the whole request handling system, just a bit:
    * A handling result and its management system was added
    * The whole system architecture was improved, to allow the handling of
    many different request kinds at the same time. This design decision had a
    cost: the kind-specific request handling part of the system is not easily
    accessible by the user, its modification is intrusive.

* Refactored the request handling API:
  * Separated the interface from the implementation.
  * Documented APIs.

## 12/02/2021

* Added a simple output-based debugging system:
  * It is able to output formatted messages in an output stream
  * It is possible to enable some kinds of debug messages

* Added debugging support for request handling
  * The debugging system outputs a message when a memory request is being handled.

## 12/04/2021

* Added some informations to the debug output
  * Added a colored output to the prefix
  * Added a prefix containing the date and the time of the message

## TODO

* Prettify the output messages with colors and bloat.

* Continue the request handling system
  * Link it to the device interface
  * Implement the request descriptor

* Think about a non-intrusive design for specific-kind request handling

* Begin the request format specification

* Optimize the request manager runner:
  * Activate the runner only when requests are available, instead of handling
  it forever ?