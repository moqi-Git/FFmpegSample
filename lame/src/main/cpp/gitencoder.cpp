//
// Created by reol on 2019-08-02.
//

#include <jni.h>
#include <android/log.h>
#include <iosfwd>
#include <stdio.h>

extern "C" {
#include "libavcodec/avcodec.h"
#include "libavutil/frame.h"
}

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"gitencoder", ##__VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_lame_GifEncoder_encode(JNIEnv *env, jobject instance, jobjectArray paths, jstring outputName_,
                                        jint rate) {

    const char *outputName = env->GetStringUTFChars(outputName_, nullptr);

    LOGE("output name is %s", outputName);
    LOGE("rate is %d", rate);

    for (int i = 0; i < env->GetArrayLength(paths); ++i) {
        auto path = (jstring) (env)->GetObjectArrayElement(paths, i);
        const char *s_path = env->GetStringUTFChars(path, nullptr);

        LOGE("intput path %d is %s", i, s_path);
//        env->ReleaseStringUTFChars(outputName_, outputName);
    }

    env->ReleaseStringUTFChars(outputName_, outputName);
    return env->NewStringUTF(outputName);
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_lame_GifEncoder_decode(JNIEnv *env, jobject instance, jstring path_) {
    const char *path = env->GetStringUTFChars(path_, nullptr);
    const FILE *input_file;

    const AVCodec *avCodec;
    const AVCodecParserContext *avCodecParserContext;
    const AVCodecContext *avCodecContext;

    LOGE("input gif path is %s", path);
    avcodec_register_all();
//    FILE *file = fopen(path, "r+");
    avCodec = avcodec_find_decoder(AV_CODEC_ID_GIF);
    if (!avCodec) {
        LOGE("GIF decoder not found");
        return nullptr;
    }

    avCodecParserContext = av_parser_init(avCodec->id);
    if (!avCodecParserContext) {
        LOGE("Parser not found");
        return nullptr;
    }

    avCodecContext = avcodec_alloc_context3(avCodec);
    if (!avCodecContext) {
        LOGE("codec context not found");
        return nullptr;
    }

    input_file = fopen(path, "rb");
    if (!input_file) {
        LOGE("input file not found");
        return nullptr;
    }

    env->ReleaseStringUTFChars(path_, path);
    return nullptr;
}

