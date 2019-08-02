package com.example.lame;

public class NativeStaticBridge {

    static {
        System.loadLibrary("native-lib");
    }

    public static native String getLameInfo();

    public static native String getFFmpegInfo();
}
