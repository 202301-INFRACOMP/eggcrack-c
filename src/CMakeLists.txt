set(FACTORY "factory/worker/red_worker.c")
set(STORAGE "storage/mailbox/finite_mailbox.c" "storage/circular_queue.c" "storage/priority_queue.c")

add_library(eggcrack ${FACTORY} ${STORAGE})
target_include_directories(eggcrack PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_compile_features(eggcrack PUBLIC c_std_17)
set_target_properties(eggcrack PROPERTIES C_EXTENSIONS OFF)
