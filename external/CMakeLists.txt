

message("##### Create Unity Library for Testing") 

add_library(Unity STATIC Unity/src/unity.c)
# target_link_directories(Unity PUBLIC Unity/src)
target_include_directories(Unity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)