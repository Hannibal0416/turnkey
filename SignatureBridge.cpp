/*
 * JVMService.cpp
 *
 *  Created on: 2013/8/31
 *      Author: Hannibal
 */

#include "SignatureBridge.h"

namespace jvm {
jclass clazz;
jobject object;
SignatureBridge::SignatureBridge() {
}

bool SignatureBridge::instance() {
	if (env == NULL) {
		std::cout << "JVM is not created" << std::endl;
		return false;
	} else {
		std::cout << "jvm::" << jvm << std::endl;
		jvm->AttachCurrentThread((void **) &env, NULL);
		clazz = env->FindClass("com/tradevan/api/Signature");
		std::cout << "clazz::" << clazz << std::endl;
		object = env->AllocObject(clazz);
		std::cout << "object::" << object << std::endl;
		return true;
	}
}

std::string SignatureBridge::testString(char* str) {
	jvm->AttachCurrentThread((void **) &env, NULL);
	jmethodID mid = env->GetMethodID(clazz, "testString",
			"(Ljava/lang/String;)Ljava/lang/String;");
	jstring arg = (env)->NewStringUTF(str);//WindowsTojstring(env,str);
	jstring msg = (jstring) env->CallObjectMethod(object, mid, arg);
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	char* tmp = (char*) malloc(strlen(rtnstr) + 1);
	strcpy(tmp, rtnstr);
	return tmp;
}

bool SignatureBridge::sign(int invoiceCount, char* format, char* migVer,
		char* json, char* certPath, char* certPassword, char* fromPartyId,
		char* fromRoutingId, char* fromVacDescription, char* toPartyId,
		char* toRoutingId, char* toVacDescription) {
	jvm->AttachCurrentThread((void **) &env, NULL);
	jmethodID sign =
			env->GetMethodID(clazz, "sign",
					"(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z");

	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jformat = (env)->NewStringUTF(format);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jmigVer = (env)->NewStringUTF(migVer);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jjson = (env)->NewStringUTF(json);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jcertPath = (env)->NewStringUTF(certPath);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jcertPassword = (env)->NewStringUTF(certPassword);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jfromPartyId = (env)->NewStringUTF(fromPartyId);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jfromRoutingId = (env)->NewStringUTF(fromRoutingId);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jfromVacDescription = (env)->NewStringUTF(fromVacDescription);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jtoPartyId = (env)->NewStringUTF(toPartyId);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jtoRoutingId = (env)->NewStringUTF(toRoutingId);
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring jtoVacDescription = (env)->NewStringUTF(toVacDescription);
	jvm->AttachCurrentThread((void **) &env, NULL);
	bool flag = env->CallObjectMethod(object, sign, invoiceCount, jformat,
			jmigVer, jjson, jcertPath, jcertPassword, jfromPartyId,
			jfromRoutingId, jfromVacDescription, jtoPartyId, jtoRoutingId,
			jtoVacDescription);
	return flag;
}

bool SignatureBridge::unSign(char* unSignature, bool isJSON) {
	jvm->AttachCurrentThread((void **) &env, NULL);
	jmethodID unsign = env->GetMethodID(clazz, "unSing",
			"(Ljava/lang/String;Z)Z");
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring junSignature = (env)->NewStringUTF(unSignature);
	jvm->AttachCurrentThread((void **) &env, NULL);
	bool flag = env->CallObjectMethod(object, unsign, junSignature, isJSON);
	return flag;
}

std::string SignatureBridge::getSignature() {
	jvm->AttachCurrentThread((void **) &env, NULL);
	jmethodID sign = env->GetMethodID(clazz, "getSignature",
			"()Ljava/lang/String;");
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring msg = (jstring) env->CallObjectMethod(object, sign);
	jvm->AttachCurrentThread((void **) &env, NULL);
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	char* tmp = (char*) malloc(strlen(rtnstr) + 1);
	strcpy(tmp, rtnstr);
	return tmp;
}

std::string SignatureBridge::getErrMsg() {
	jvm->AttachCurrentThread((void **) &env, NULL);
	jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
			"()Ljava/lang/String;");
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring msg = (jstring) env->CallObjectMethod(object, sign);
	jvm->AttachCurrentThread((void **) &env, NULL);
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	char* tmp = (char*) malloc(strlen(rtnstr) + 1);
	strcpy(tmp, rtnstr);
	delete rtnstr;
	return tmp;
}

std::string SignatureBridge::getMigMsg() {
	jvm->AttachCurrentThread((void **) &env, NULL);
	jmethodID sign = env->GetMethodID(clazz, "getMigMsg",
			"()Ljava/lang/String;");
	jvm->AttachCurrentThread((void **) &env, NULL);
	jstring msg = (jstring) env->CallObjectMethod(object, sign);
	jvm->AttachCurrentThread((void **) &env, NULL);
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	char* tmp = (char*) malloc(strlen(rtnstr) + 1);
	strcpy(tmp, rtnstr);
	delete rtnstr;
	return tmp;
}
;

} /* namespace jvm */
