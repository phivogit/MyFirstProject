# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "Autoclicker_autogen"
  "CMakeFiles\\Autoclicker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Autoclicker_autogen.dir\\ParseCache.txt"
  )
endif()
