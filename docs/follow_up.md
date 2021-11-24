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