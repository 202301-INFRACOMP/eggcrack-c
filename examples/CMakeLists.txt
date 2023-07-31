add_executable(id_sequencer_example)
target_sources(id_sequencer_example PRIVATE id_sequencer_example.c)
target_link_libraries(id_sequencer_example PRIVATE eggrack::library)
target_compile_definitions(id_sequencer_example PRIVATE ${platform_macro})

if(${platform_macro} STREQUAL WINDOWS_PLATFORM)
	target_link_libraries(id_sequencer_example PRIVATE windows_internal)
endif()
