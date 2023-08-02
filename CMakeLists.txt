cmake_minimum_required(VERSION 3.26)

project(eggcrack LANGUAGES C)

find_package(Threads REQUIRED)

if(NOT ${Threads_FOUND})
    message(FATAL_ERROR "Could not proceed, there is not a threading library available.")
endif()

if(${CMAKE_USE_WIN32_THREADS_INIT})
    message(NOTICE "Using Windows Threads.")
    SET(platform_macro WINDOWS_PLATFORM)
elseif(${CMAKE_USE_PTHREADS_INIT})
    message(NOTICE "Using POSIX Threads.")
    SET(platform_macro POSIX_PLATFORM)
else()
    message(FATAL_ERROR "Thread library not suported.")
endif()

include(CheckIPOSupported)
check_ipo_supported(LANGUAGES C)

SET(C_STANDARD C17)
set(CMAKE_CXX_EXTENSIONS OFF)

# library
add_library(eggcrack STATIC)
add_library(eggrack::library ALIAS eggcrack)
target_link_libraries(eggcrack PRIVATE Threads::Threads)
target_include_directories(eggcrack PUBLIC include)
target_compile_definitions(eggcrack PRIVATE ${platform_macro})
set_target_properties(eggcrack PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)

# executable
add_executable(eggcrack_executable)
target_link_libraries(eggcrack_executable PRIVATE eggrack::library)
set_target_properties(eggcrack PROPERTIES 
    OUTPUT_NAME eggcrack
    INTERPROCEDURAL_OPTIMIZATION TRUE
)

add_subdirectory(src)
add_subdirectory(examples)
