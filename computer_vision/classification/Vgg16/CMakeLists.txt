add_executable(
        vgg16
        src/main.c
        src/vnn_pre_process.c
        src/vnn_post_process.c
        src/vnn_vgg16caffe.c
)

target_include_directories(
        vgg16
        PRIVATE
        ${G_LIBS_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/service/include
)

target_link_libraries(
        vgg16
        jpeg
        srvc
        ovxlib
        ${OpenCV_LIBS}
        ${G_LIBS_LIBRARIES}
)

install (
        TARGETS vgg16
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install/bin
)

install(
        FILES data/vgg16_caffe.export.data DESTINATION ${PROJECT_SOURCE_DIR}/install/data
)
