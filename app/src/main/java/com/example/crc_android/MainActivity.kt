package com.example.crc_android

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.crc_android.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val b=ByteArray(5){
            (it+1146).toByte()
        }
        // Example of a call to a native method
        binding.sampleText.text = CRCUtils.calCRC8(b).toString().toString()
        // Example of a call to a native method
        binding.sampleText2.text = crc(b).toString().toString()
    }

    /**
     * A native method that is implemented by the 'crc_android' native library,
     * which is packaged with this application.
     */

    external fun crc(b:ByteArray): Byte

    companion object {
        // Used to load the 'crc_android' library on application startup.
        init {
            System.loadLibrary("crc_android")
        }
    }
}