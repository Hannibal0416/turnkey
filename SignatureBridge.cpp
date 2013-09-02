/*
 * JVMService.cpp
 *
 *  Created on: 2013/8/31
 *      Author: Hannibal
 */

#include "SignatureBridge.h"

namespace jvm {
jclass clazz;    //全局变量，用来传递class
jobject object;  //全局变量，用来传递object

SignatureBridge::SignatureBridge() {
}

bool SignatureBridge::instance() {
	if (env == NULL) {
		std::cout << "JVM is not created" << std::endl;
		return false;
	} else {
		clazz = env->FindClass("com/tradevan/api/SignatureService");
		object = env->AllocObject(clazz);
		return true;
	}
}

char* SignatureBridge::testString(char* str) {

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

bool SignatureBridge::sign(int invoiceCount, char* format, char* migVer,
		char* json, char* certPath, char* certPassword, char* fromPartyId,
		char* fromRoutingId, char* fromVacDescription, char* toPartyId,
		char* toRoutingId, char* toVacDescription) {
	jmethodID sign =
			env->GetMethodID(clazz, "sign",
					"(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z");
	jstring jformat = (env)->NewStringUTF(format);
	jstring jmigVer = (env)->NewStringUTF(migVer);
	jstring jjson = (env)->NewStringUTF(json);
	jstring jcertPath = (env)->NewStringUTF(certPath);
	jstring jcertPassword = (env)->NewStringUTF(certPassword);
	jstring jfromPartyId = (env)->NewStringUTF(fromPartyId);
	jstring jfromRoutingId = (env)->NewStringUTF(fromRoutingId);
	jstring jfromVacDescription = (env)->NewStringUTF(fromVacDescription);
	jstring jtoPartyId = (env)->NewStringUTF(toPartyId);
	jstring jtoRoutingId = (env)->NewStringUTF(toRoutingId);
	jstring jtoVacDescription = (env)->NewStringUTF(toVacDescription);
	bool flag = env->CallObjectMethod(obj, sign, invoiceCount, jformat, jmigVer,
			jjson, jcertPath, jcertPassword, jfromPartyId, jfromRoutingId,
			jtoPartyId, jtoRoutingId, jfromVacDescription, jtoVacDescription);
	return flag;
}

bool SignatureBridge::unSign(char* unSignature, bool isJSON) {
	jmethodID unsign = env->GetMethodID(clazz, "unSing",
			"(Ljava/lang/String;Z)Z");
	jstring junSignature = (env)->NewStringUTF(unSignature);
	bool flag = env->CallObjectMethod(object, unsign, junSignature, isJSON);
	return flag;
}

string SignatureBridge::getSignature() {
	jmethodID sign = env->GetMethodID(clazz, "getSignature",
			"()Ljava/lang/String;");
	jstring msg = (jstring) env->CallObjectMethod(object, sign);
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	cout << rtnstr << endl;
	return "";
}

string SignatureBridge::getErrMsg() {
	jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
			"()Ljava/lang/String;");
	jstring msg = (jstring) env->CallObjectMethod(object, sign);
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	cout << rtnstr << endl;
	return "";
}

string SignatureBridge::getMigMsg() {
	jmethodID sign = env->GetMethodID(clazz, "getMigMsg",
			"()Ljava/lang/String;");
	jstring msg = (jstring) env->CallObjectMethod(object, sign);
	const char* rtnstr = env->GetStringUTFChars(msg, 0);
	cout << rtnstr << endl;
	return "";
}
;

} /* namespace jvm */
