cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

# Set project name and high level config
set(projname "raspberry_pico_app")
project(${projname} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_SSTANDARD 17)

message("##### Buiding Project: ${projname}")

# Set source and include directory variables
set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Initialize the pick sdk
pico_sdk_init()

# Set include directories
include_directories(${include_dir})

# Globbing files before linking 
file(GLOB_RECURSE src_files "${source_dir}/*.c")
file(GLOB_RECURSE include_files "${include_dir}/*.h")

# Confirm that the proper source and header files were found
message("##### Source files: ${src_files}")
message("##### Include files: ${include_files}")

# Create the executable
add_executable(${projname} "${src_files}")

# Include the PICO Standard Library and Hardware Libraries
target_link_libraries(${projname} 
    pico_stdlib  
    hardware_pwm 
    )

# adjust to enable stdio via usb, or uart
pico_enable_stdio_usb(${projname} 0)
pico_enable_stdio_uart(${projname} 1)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${projname})

