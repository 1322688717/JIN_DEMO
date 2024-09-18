package com.zcq.jni_demo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.zcq.jni_demo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'jni_demo' library on application startup.
    static {
        System.loadLibrary("jni_demo");
    }

    private ActivityMainBinding binding;

    private  String testStr = "Hello from Java";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
        Log.d("MainActivity", "调用cpp方法ntFromJNI: " + intFromJNI());

        // 调用C++中的callJavaMethod函数
        callJavaMethod();
        changeStrToC();
    }


    public void test(){
        Log.d("MainActivity", "c层调用了我");
    }

    public void test1(String str){
        testStr = str;
        Log.d("MainActivity", "c层改变字符串是：" + testStr);
    }

    /**
     * A native method that is implemented by the 'jni_demo' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int intFromJNI();

    public native void callJavaMethod();

    public native void changeStrToC();
}