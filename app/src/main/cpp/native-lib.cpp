#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_zcq_jni_1demo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

// 实现 intFromJNI 方法
extern "C" JNIEXPORT jint JNICALL
Java_com_zcq_jni_1demo_MainActivity_intFromJNI(JNIEnv *env, jobject) {
    return 100;  // 返回一个整数
}

// 获取Java类的引用并调用方法
extern "C" JNIEXPORT void JNICALL
Java_com_zcq_jni_1demo_MainActivity_callJavaMethod(JNIEnv *env, jobject obj) {
    // 获取 Java 类的引用
    jclass cls = env->GetObjectClass(obj);

    // 确保类引用不为空
    if (cls == nullptr) {
        return;  // 处理错误情况
    }

    // 获取 Java 方法的 ID
    jmethodID mid = env->GetMethodID(cls, "test", "()V");
    if (mid == nullptr) {
        return;  // 方法ID获取失败
    }

    // 调用 Java 方法
    env->CallVoidMethod(obj, mid);
}

// 实现 intFromJNI 方法
extern "C" JNIEXPORT void JNICALL
Java_com_zcq_jni_1demo_MainActivity_changeStrToC(JNIEnv *env, jobject obj) {
    // 获取 Java 类的引用
    jclass cls = env->GetObjectClass(obj);

    // 确保类引用不为空
    if (cls == nullptr) {
        return;  // 处理错误情况
    }

    // 要传递给 Java 方法的字符串
    std::string hello = "Hello from C++";

    // 获取 Java 方法的 ID
    // 这里 "test1" 方法的签名是 "(Ljava/lang/String;)V"，表示它接收一个 String 参数，返回 void
    jmethodID mid = env->GetMethodID(cls, "test1", "(Ljava/lang/String;)V");
    if (mid == nullptr) {
        return;  // 方法ID获取失败
    }

    // 将 C++ 的 std::string 转换为 Java 的 jstring
    jstring javaString = env->NewStringUTF(hello.c_str());

    // 调用 Java 方法，传递字符串
    env->CallVoidMethod(obj, mid, javaString);

    // 释放局部引用
    env->DeleteLocalRef(javaString);

}