add_executable(
        resnet50
        src/main.c
        src/vnn_pre_process.c
        src/vnn_post_process.c
        src/vnn_resnet50caffe.c
)

target_include_directories(
        resnet50
        PRIVATE
        ${G_LIBS_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/service/include
)

target_link_libraries(
        resnet50
        jpeg
        srvc
        ovxlib
        ${OpenCV_LIBS}
        ${G_LIBS_LIBRARIES}
)

install (
        TARGETS resnet50
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install/bin
)

install(
        FILES data/resnet50_caffe.export.data DESTINATION ${PROJECT_SOURCE_DIR}/install/data
)
