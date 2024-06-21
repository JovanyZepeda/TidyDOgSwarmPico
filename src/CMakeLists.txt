message("####### In directory ${CMAKE_CURRENT_SOURCE_DIR}")


# Create Executable for the application
add_executable(${projname}
    main.c
)

################### Creating Libraries and Including Directoires ###################

message("----> Linking Pico Source and Haeders! <----")

# Include the PICO Standard Library and Hardware Libraries
target_link_libraries(${projname} 
pico_stdlib  
hardware_pwm 
)

# Check if the files exist in the respective directories first
if(src_app_files OR include_app_files)
    message("----> Application Source Files Exists! <----")
    add_library(application_modules STATIC "${src_app_files}")
    target_include_directories(application_modules PUBLIC "${include_app_dir}")
    target_link_libraries(${projname} application_modules)
endif()

if(src_bsp_files OR include_bsp_files)
    message("----> BSP Source Files Exists! <----")
    add_library(board_support_modules STATIC "${src_bsp_files}")
    target_include_directories(board_support_modules PUBLIC "${include_bsp_dir}")
    target_link_libraries(${projname} board_support_modules)
endif()

if(src_common_files OR include_commmon_files)
    message("----> Common Source Files Exists! <----")
    add_library(common_modules STATIC "${src_common_files}")
    target_include_directories(common_modules PUBLIC "${include_common_dir}")
    target_link_libraries(${projname} common_modules)
endif()

if(src_drivers_files OR include_drivers_files)
    message("----> Drivers Source Files Exists! <----")
    add_library(drivers_modules STATIC "${src_drivers_files}")
    target_include_directories(drivers_modules PUBLIC "${include_drivers_dir}")
    target_link_libraries(${projname} drivers_modules)
endif()

################### Creating Executable and Linking Libraries ###################

# message("----> Linking Pico Source and Haeders! <----")

# # Include the PICO Standard Library and Hardware Libraries
# target_link_libraries(${projname} 
# pico_stdlib  
# hardware_pwm 
# )

# adjust to enable stdio via usb, or uart
pico_enable_stdio_usb(${projname} 0)
pico_enable_stdio_uart(${projname} 1)

# create map/bin/hex/uf2 file in addition to ELF
pico_add_extra_outputs(${projname})