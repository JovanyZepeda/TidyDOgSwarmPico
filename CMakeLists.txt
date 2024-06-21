cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

# Set project name and high level config
set(projname "raspberry_pico_app")
project(${projname} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_SSTANDARD 17)

# Create variable to determine target group -> by default set to production
set(TARGET_GROUP production CACHE STRING "Group to build")

message("##### Setting up Project: ${projname}")

# Set source and include directory variables
set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(source_app_dir "${source_dir}/app")
set(source_bsp_dir "${source_dir}/bsp")
set(source_common_dir "${source_dir}/common")
set(source_drivers_dir "${source_dir}/drivers")

set(include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(include_app_dir "${include_dir}/app")
set(include_bsp_dir "${include_dir}/bsp")
set(include_common_dir "${include_dir}/common")
set(include_drivers_dir "${include_dir}/drivers")

# Initialize the pick sdk
pico_sdk_init()

# Set include directories
# include_directories(${include_dir})

# Globbing files before linking 
file(GLOB_RECURSE src_files "${source_dir}/*.c")
file(GLOB_RECURSE src_app_files "${source_app_dir}/*.c")
file(GLOB_RECURSE src_bsp_files "${source_bsp_dir}/*.c")
file(GLOB_RECURSE src_common_files "${source_common_dir}/*.c")
file(GLOB_RECURSE src_drivers_files "${source_drivers_dir}/*.c")

file(GLOB_RECURSE include_files "${include_dir}/*.h")
file(GLOB_RECURSE include_app_files "${include_app_dir}/*.h")
file(GLOB_RECURSE include_bsp_files "${include_bsp_dir}/*.h")
file(GLOB_RECURSE include_commmon_files "${include_common_dir}/*.h")
file(GLOB_RECURSE include_drivers_files "${include_drivers_dir}/*.h")


# Confirm that the proper source and header files were found
message("##### Source files: ${src_files}")
message("##### Include files: ${include_files}")


if( TARGET_GROUP STREQUAL production )

    message("##### Buiding Project: ${TARGET_GROUP}")

    add_subdirectory(src)

    # # Create the executable
    # add_executable(${projname} "${src_files}")

    # # Include the PICO Standard Library and Hardware Libraries
    # target_link_libraries(${projname} 
    #     pico_stdlib  
    #     hardware_pwm 
    #     )

    # # adjust to enable stdio via usb, or uart
    # pico_enable_stdio_usb(${projname} 0)
    # pico_enable_stdio_uart(${projname} 1)

    # # create map/bin/hex/uf2 file in addition to ELF.
    # pico_add_extra_outputs(${projname})


elseif(TARGET_GROUP STREQUAL test)
    message("##### Buiding Project: test")

    include(CTest)

    add_subdirectory(external)
    add_subdirectory(test)

else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown") 

endif()



# # Create the executable
# add_executable(${projname} "${src_files}")

# # Include the PICO Standard Library and Hardware Libraries
# target_link_libraries(${projname} 
#     pico_stdlib  
#     hardware_pwm 
#     )

# # adjust to enable stdio via usb, or uart
# pico_enable_stdio_usb(${projname} 0)
# pico_enable_stdio_uart(${projname} 1)

# # create map/bin/hex/uf2 file in addition to ELF.
# pico_add_extra_outputs(${projname})

