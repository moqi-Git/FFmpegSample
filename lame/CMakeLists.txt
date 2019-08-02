cmake_minimum_required(VERSION 3.4.1)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add.library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.

include_directories(src/main/cpp/include/)
set(ANDROID_ABI armeabi-v7a)

#message(FATAL_ERROR ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI})

add_library(avcodec SHARED IMPORTED)
set_target_properties(avcodec
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libavcodec.so
        )
add_library(avfilter SHARED IMPORTED)
set_target_properties(avfilter
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libavfilter.so
        )
add_library(avformat SHARED IMPORTED)
set_target_properties(avformat
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libavformat.so
        )
add_library(avutil SHARED IMPORTED)
set_target_properties(avutil
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libavutil.so
        )
add_library(swresample SHARED IMPORTED)
set_target_properties(swresample
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libswresample.so
        )
add_library(swscale SHARED IMPORTED)
set_target_properties(swscale
        PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libswscale.so
        )

add_library( # Specifies the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native_bridge.cpp
        src/main/cpp/gitencoder.cpp
        src/main/cpp/lame/bitstream.c
        src/main/cpp/lame/encoder.c
        src/main/cpp/lame/fft.c
        src/main/cpp/lame/gain_analysis.c
        src/main/cpp/lame/id3tag.c
        src/main/cpp/lame/lame.c
        src/main/cpp/lame/mpglib_interface.c
        src/main/cpp/lame/newmdct.c
        src/main/cpp/lame/presets.c
        src/main/cpp/lame/psymodel.c
        src/main/cpp/lame/quantize.c
        src/main/cpp/lame/quantize_pvt.c
        src/main/cpp/lame/reservoir.c
        src/main/cpp/lame/set_get.c
        src/main/cpp/lame/tables.c
        src/main/cpp/lame/takehiro.c
        src/main/cpp/lame/util.c
        src/main/cpp/lame/vbrquantize.c
        src/main/cpp/lame/VbrTag.c
        src/main/cpp/lame/version.c
        )

find_library( # Defines the name of the path variable that stores the
        # location of the NDK library.
        log-lib

        # Specifies the name of the NDK library that
        # CMake needs to locate.
        log)

target_link_libraries( # Specifies the target library.
        native-lib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        )

target_link_libraries(
        native-lib
        avcodec
        avfilter
        avformat
        swresample
        swscale
        avutil
)