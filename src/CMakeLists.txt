add_subdirectory(factory)

add_subdirectory(platform)
if(${platform_macro} STREQUAL WINDOWS_PLATFORM)
	target_link_libraries(eggcrack PRIVATE windows_internal)
endif()

target_sources(eggcrack_executable PRIVATE main.c)
