package com.example.lame;

public class GifEncoder {

    public native String encode(String[] paths, String outputName, int rate);

    public native String[] decode(String path);
}
