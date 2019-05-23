add_executable(
        mobilenet
        src/main.c
        src/vnn_pre_process.c
        src/vnn_post_process.c
        src/vnn_mobilenet.c
)

target_include_directories(
        mobilenet
        PRIVATE
        ${G_LIBS_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/service/include
)

target_link_libraries(
        mobilenet
        jpeg
        srvc
        ovxlib
        ${OpenCV_LIBS}
        ${G_LIBS_LIBRARIES}
)

install (
        TARGETS mobilenet
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install/bin
)

install(
        FILES data/mobilenet.export.data DESTINATION ${PROJECT_SOURCE_DIR}/install/data
)
