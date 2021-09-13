package com.reactnativejsiexample;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;
import com.facebook.react.bridge.JavaScriptContextHolder;

@ReactModule(name = JsiExampleModule.NAME)
public class JsiExampleModule extends ReactContextBaseJavaModule {
    public static final String NAME = "JsiExample";

    public JsiExampleModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    private static native void initialize(long jsiPtr, String docDir);

    @Override
    public void initialize(){
        super.initialize();
        JsiExampleModule.initialize(this.getReactApplicationContext().getJavaScriptContextHolder().get(),
                this.getReactApplicationContext().getFilesDir().getAbsolutePath());
    }

    static {
        try {
            // Used to load the 'native-lib' library on application startup.
            System.loadLibrary("cpp");
        } catch (Exception ignored) {
        }
    }

    // Example method
    // See https://reactnative.dev/docs/native-modules-android
    @ReactMethod
    public void multiply(int a, int b, Promise promise) {
        promise.resolve(nativeMultiply(a, b));
    }

    @ReactMethod
    public void add(int a, int b, Promise promise) {
        promise.resolve(nativeAdd(a, b));
    }

    public static native int nativeMultiply(int a, int b);
    public static native int nativeAdd(int a, int b);
}
