/*
 * JVMLoader.h
 *
 *  Created on: 2013/8/31
 *      Author: Hannibal
 */
#include "jni.h"
#include "windows.h"
#include <string>
#include <iostream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <exception>
#ifndef JVMLOADER_H_
#define JVMLOADER_H_
namespace jvm {
typedef jint (WINAPI *PFunCreateJavaVM)(JavaVM **, void **, void *);
int getdir(std::string dir, std::vector<std::string> &files);
class JVMLoader
{
public:
    static bool StartJVM();
    static bool DestroyJVM();
    static bool isJVMAlive();
    JVMLoader();
    virtual ~JVMLoader();
protected:
    static JNIEnv* env;
    static JavaVM* jvm;
};

} /* namespace jvm */
#endif /* JVMLOADER_H_ */
