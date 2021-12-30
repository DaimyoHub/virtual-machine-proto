add_rules('mode.debug', 'mode.release')

add_requires('fmt')

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

-- Other utilities
target('vm-utils')
  set_kind('static')
  add_files('src/utils/*.cpp')
  add_packages('fmt')

-- Device interface
target('vm-device')
  set_kind('static')
  add_files('src/device/*.cpp')
  add_deps('vm-utils')

-- Request handling system
target('vm-request')
  set_kind('static')
  add_files('src/request/*.cpp')
  add_deps('vm-utils')

-- System APIs
target('vm-system')
  set_kind('static')
  add_files('src/system/*.cpp')
  add_deps('vm-utils')

-- Useless tests...
target('tests')
  set_kind('binary')
  add_files('tests/*.cpp')
  add_deps('vm-device', 'vm-request', 'vm-system', 'vm-utils')
