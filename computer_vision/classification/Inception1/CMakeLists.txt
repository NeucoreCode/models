add_executable(
        inceptionV1
        src/main.c
        src/vnn_pre_process.c
        src/vnn_post_process.c
        src/vnn_inceptionv1.c
)

target_include_directories(
        inceptionV1
        PRIVATE
        ${G_LIBS_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/service/include
)

target_link_libraries(
        inceptionV1
        jpeg
        srvc
        ovxlib
        ${OpenCV_LIBS}
        ${G_LIBS_LIBRARIES}
)

install (
        TARGETS inceptionV1
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install/bin
)

install(
        FILES data/inceptionV1.export.data DESTINATION ${PROJECT_SOURCE_DIR}/install/data
)
