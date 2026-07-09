# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyTrainer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyTrainer_autogen.dir\\ParseCache.txt"
  "MyTrainer_autogen"
  )
endif()
