#include <jni.h>
#include "example.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_reactnativejsiexample_JsiExampleModule_nativeMultiply(JNIEnv *env, jclass type, jint a, jint b) {
    return example::multiply(a, b);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_reactnativejsiexample_JsiExampleModule_nativeAdd(JNIEnv *env, jclass type, jint a, jint b) {
    return example::add(a, b);
}
