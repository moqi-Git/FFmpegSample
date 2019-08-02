package com.example.lamedemo

import android.Manifest
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.os.Handler
import android.util.Log
import android.widget.Toast
import com.example.lame.GifEncoder
import com.example.lame.NativeStaticBridge
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            requestPermissions(arrayOf(Manifest.permission.WRITE_EXTERNAL_STORAGE), 1000)
        }

        Toast.makeText(this, NativeStaticBridge.getLameInfo(), Toast.LENGTH_LONG).show()

//        tv_main.text = NativeStaticBridge.getFFmpegInfo()

        val encoder = GifEncoder()
        encoder.encode(arrayOf("path-a", "path-b", "path-c"), "app.gif", 5)
        val root = Environment.getExternalStorageDirectory().absoluteFile
        val t2_path = "${root}/Picture/t2.gif"
        Log.e("asdfg", t2_path)
        encoder.decode(t2_path)
    }
}
