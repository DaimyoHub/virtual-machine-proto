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

if is_plat('linux') then
  add_syslinks('pthread')
end

-- Arithmetic and logic unit
--target('vm-alu')
--  set_kind('static')
--  add_files('src/alu/*.cpp')


-- Memory API
target('vm-mem')
  set_kind('static')
  add_files('src/mem/*.cpp')


-- ISA API
--target('vm-asm')
--  set_kind('static')
--  add_files('src/asm/*.cpp')


-- Debugger API
--target('vm-dbg')
--  set_kind('static')
--  add_files('src/dbg/*.cpp')


-- Machine API
target('vm-core')
  set_kind('static')
  add_files('src/core/**/*.cpp')


-- Useless tests...
target('tests')
  set_kind('binary')
  add_files('tests/*.cpp')
