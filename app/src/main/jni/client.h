#ifndef ANDROLUAJIT_CLIENT
#define ANDROLUAJIT_CLIENT

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <android/log.h> 

#ifndef LOG_TAG
#define LOG_TAG "LuajitServer"
#endif

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG,__VA_ARGS__)
#define LOGS(...) __android_log_print(ANDROID_LOG_SILENT,LOG_TAG,__VA_ARGS__)
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)

#define LOCAL_SOCKET_SERVER_NAME "LuajitServer"

int socketSend(char * msg);


#endif