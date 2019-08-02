//
// Created by reol on 2019-07-23.
//

#include <jni.h>
#include "lame/lame.h"

extern "C" {
    #include "libavcodec/avcodec.h"
}



extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_lame_NativeStaticBridge_getLameInfo(JNIEnv* env, jclass type){

    return env->NewStringUTF(get_lame_version());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_lame_NativeStaticBridge_getFFmpegInfo(JNIEnv* env, jclass type){

    return env->NewStringUTF(avcodec_configuration());
}