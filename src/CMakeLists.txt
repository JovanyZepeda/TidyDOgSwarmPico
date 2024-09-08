message("####### In directory ${CMAKE_CURRENT_SOURCE_DIR}")


# Create Executable for the application
add_executable(${projname}
    main.c
)

################### Creating Libraries and Including Directories ###################

message("####### Linking Application Source and Headers! <----")


# Check if the files exist in the respective directories first
if(src_app_files OR include_app_files)
    message("----> Application Source Files Exists! <----")
    add_library(application_modules STATIC "${src_app_files}")
    target_include_directories(application_modules PRIVATE "${include_app_dir}")

    # Link pico libraries that are needed for implementation 
    target_link_libraries(application_modules PRIVATE 
        pico_stdlib
        hardware_pwm
    )

    target_link_libraries(${projname} PRIVATE application_modules)
endif()

if(src_bsp_files OR include_bsp_files)
    message("----> BSP Source Files Exists! <----")
    add_library(board_support_modules STATIC "${src_bsp_files}")
    target_include_directories(board_support_modules PRIVATE "${include_bsp_dir}")
    
    # Link pico libraries that are needed for implementation 
    target_link_libraries(board_support_modules PRIVATE 
        pico_stdlib
        hardware_pwm
    )
    
    target_link_libraries(${projname} PRIVATE board_support_modules)
endif()

if(src_common_files OR include_commmon_files)
    message("----> Common Source Files Exists! <----")
    add_library(common_modules STATIC "${src_common_files}")
    target_include_directories(common_modules PRIVATE "${include_common_dir}")
    
    # Link pico libraries that are needed for implementation 
    target_link_libraries(common_modules PRIVATE 
        pico_stdlib
    )    

    target_link_libraries(${projname} PRIVATE common_modules pico_stdlib)
endif()

if(src_drivers_files OR include_drivers_files)
    message("----> Drivers Source Files Exists! <----")
    add_library(drivers_modules STATIC "${src_drivers_files}")
    target_include_directories(drivers_modules PRIVATE "${include_drivers_dir}")
    
    # Link pico libraries that are needed for implementation 
    target_link_libraries(src_drivers_files PRIVATE 
        pico_stdlib
        hardware_pwm
    )

    target_link_libraries(${projname} PRIVATE drivers_modules)
endif()

message("####### Linking Pico Source and Headers! <----")

# Include the PICO Standard Library and Hardware Libraries
target_link_libraries(${projname} PRIVATE
pico_stdlib 
)



################### Pico Build Configuration ###################

message("####### Pico Build Configuration! <----")

# adjust to enable stdio via usb, or uart
pico_enable_stdio_usb(${projname} 1)
pico_enable_stdio_uart(${projname} 0)

# create map/bin/hex/uf2 file in addition to ELF
pico_add_extra_outputs(${projname})