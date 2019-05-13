add_executable(
        bvlc_googlenet
        src/main.c
        src/vnn_pre_process.c
        src/vnn_post_process.c
        src/vnn_bvlcgooglenetcaffe.c
)

target_include_directories(
        bvlc_googlenet
        PRIVATE
        ${G_LIBS_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/service/include
)

target_link_libraries(
        bvlc_googlenet
        jpeg
        srvc
        ovxlib
        ${OpenCV_LIBS}
        ${G_LIBS_LIBRARIES}
)

install (
        TARGETS bvlc_googlenet
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install/bin
)

install(
        FILES data/bvlc_googlenet_caffe.export.data DESTINATION ${PROJECT_SOURCE_DIR}/install/data
)
