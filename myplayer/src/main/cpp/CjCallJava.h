//
// Created by cxj on 2020-2-28.
//

#ifndef MYMUSIC_WLCALLJAVA_H
#define MYMUSIC_WLCALLJAVA_H

#include "jni.h"
#include <linux/stddef.h>
#include "AndroidLog.h"

#define MAIN_THREAD 0
#define CHILD_THREAD 1


class CjCallJava {

public:
    _JavaVM *javaVM = NULL;
    JNIEnv *jniEnv = NULL;
    jobject jobj;

    jmethodID jmid_parpared;
    jmethodID jmid_load;
    jmethodID jmid_timeinfo;
    jmethodID jmid_error;
    jmethodID jmid_complete;
    jmethodID jmid_valumedb;
    jmethodID jmid_pcmtoaac;
    jmethodID jmid_pcminfo;
    jmethodID jmid_pcmrate;

public:
    CjCallJava(_JavaVM *javaVM, JNIEnv *env, jobject *obj);
    ~CjCallJava();

    void onCallParpared(int type);

    void onCallLoad(int type, bool load);

    void onCallTimeInfo(int type, int curr, int total);

    void onCallError(int type, int code, char *msg);

    void onCallComplete(int type);

    void onCallValumeDB(int type, int db);

    void onCallPcmToAAc(int type, int size, void *buffer);

    void onCallPcmInfo(void *buffer, int size);

    void onCallPcmRate(int samplerate);

};


#endif //MYMUSIC_WLCALLJAVA_H
