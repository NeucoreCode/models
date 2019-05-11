add_executable(
        alexnet
        src/main.c
        src/vnn_pre_process.c
        src/vnn_post_process.c
        src/vnn_alexnetcaffe.c
)

target_include_directories(
        alexnet
        PRIVATE
        ${G_LIBS_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/alexnet
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/service/include
)

target_link_libraries(
        alexnet
        jpeg
        srvc
        ovxlib
        ${OpenCV_LIBS}
        ${G_LIBS_LIBRARIES}
)

install (
        TARGETS alexnet
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install/bin
)

install(
        FILES data/alexnet_caffe.export.data DESTINATION ${PROJECT_SOURCE_DIR}/install/data
)
