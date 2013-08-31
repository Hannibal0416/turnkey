/*
 * JVMService.cpp
 *
 *  Created on: 2013/8/31
 *      Author: Hannibal
 */

#include "JVMService.h"

namespace jvm {
jclass clazz;    //全局变量，用来传递class
jobject object;  //全局变量，用来传递object

JVMService::JVMService() {
}

bool JVMService::instance(char* className){
	if (env == NULL) {
		std::cout << "JVM is not created" << std::endl;
		return false;
	} else {
		clazz = env->FindClass(className);
		object = env->AllocObject(clazz);
		return true;
	}
}

char* JVMService::testString(char* str) {

	std::cout << clazz << std::endl;
	jmethodID mid = env->GetMethodID(clazz, "testString",
			"(Ljava/lang/String;)Ljava/lang/String;");

	jstring arg = (env)->NewStringUTF(str);

	jstring msg = (jstring) env->CallObjectMethod(object, mid, arg);
	std::cout << msg << std::endl;
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	std::cout << rtnstr << std::endl;
	char* tmp;
//	strncpy(tmp, rtnstr, 4);
	return tmp;
}
} /* namespace jvm */
