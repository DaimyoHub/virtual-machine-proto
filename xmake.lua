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
target('vm-alu')
  set_kind('static')
  add_files('src/alu/*.cpp')


-- Memory API
target('vm-mem')
  set_kind('static')
  add_files('src/mem/*.cpp')


-- ISA API
target('vm-asm')
  set_kind('static')
  add_files('src/asm/*.cpp')


-- Debugger API
target('vm-dbg')
  set_kind('static')
  add_files('src/dbg/*.cpp')


-- Machine API
target('vm-core')
  set_kind('static')
  add_files('src/core/*.cpp')


-- Machine application
target('vm-cli')
  set_kind('binary')
  add_files('src/cli/*.cpp')


-- Useless tests...
target('tests')
  set_kind('binary')
  add_files('tests/*.cpp')