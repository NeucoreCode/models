add_executable(
        inceptionV4
        src/main.c
        src/vnn_pre_process.c
        src/vnn_post_process.c
        src/vnn_inceptionv4.c
)

target_include_directories(
        inceptionV4
        PRIVATE
        ${G_LIBS_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/service/include
)

target_link_libraries(
        inceptionV4
        jpeg
        srvc
        ovxlib
        ${OpenCV_LIBS}
        ${G_LIBS_LIBRARIES}
)

install (
        TARGETS inceptionV4
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/install/bin
)

install(
        FILES data/inceptionV4.export.data DESTINATION ${PROJECT_SOURCE_DIR}/install/data
)
