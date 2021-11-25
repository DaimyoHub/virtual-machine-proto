add_rules('mode.debug', 'mode.release')

set_languages('cxx17')
add_includedirs('include/')

if is_mode('debug') then 
  set_symbols('debug')
  set_optimize('none')
  add_defines('VM_DEBUG')
else
  set_optimize('faster')
  add_defines('VM_RELEASE')
end

-- Arithmetic and logic unit
--target('vm-logimetic')
--  set_kind('static')
--  add_files('src/alu/*.cpp')


-- Memory API
target('vm-memory')
  set_kind('static')
  add_files('src/memory/*.cpp')


-- Utilities
target('vm-utilities')
  set_kind('static')
  add_files('src/utilities/*.cpp')


-- ISA API
--target('vm-assembly')
--  set_kind('static')
--  add_files('src/asm/*.cpp')


-- Debugger API
--target('vm-debugger')
--  set_kind('static')
--  add_files('src/dbg/*.cpp')


-- Machine API
--target('vm-processor')
--  set_kind('static')
--  add_files('src/core/*.cpp')


-- Machine application
--target('vm')
--  set_kind('binary')
--  add_files('src/cli/*.cpp')


-- Useless tests...
target('tests')
  set_kind('binary')
  add_files('tests/*.cpp')
