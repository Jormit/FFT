# CMakeList.txt : CMake project for FFT, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_compile_definitions(_USE_MATH_DEFINES)
add_executable (FFT  "FFT.h"  "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FFT PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
