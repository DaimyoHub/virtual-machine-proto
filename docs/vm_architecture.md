## Memory management process

* Users are working in chunks, that is to say, the only memory link they directly
share with the memory management system is the chunk.
* If a user needs to perform actions that needs some memory management
  * He calls a system API:
    1. The call will transmit the management request to the device
    2. The device will adapt it to the memory allocator
    3. THe memory allocator will formulate a precise request that will be sent to
  the request manager of the core system.
