/*
 * JVMService.cpp
 *
 *  Created on: 2013/8/31
 *      Author: Hannibal
 */

#include "SignatureBridge.h"
#include<iostream>
#include<fstream>
namespace jvm {

SignatureBridge::SignatureBridge() {
}

char* SignatureBridge::testFile(char* str) {
	FILE * pFile;
	pFile = fopen ("/apsmeTestFile.txt","w");
	fprintf (pFile, str);
	fclose (pFile);
	return str;
}

char* SignatureBridge::testString(char* str) {
	JNIEnv *env;
	jvm->AttachCurrentThread((void **) &env, NULL);
	jclass clazz = env->FindClass("com/tradevan/api/Signature");
	jobject object = env->AllocObject(clazz);
	jmethodID mid = env->GetMethodID(clazz, "testString",
			"(Ljava/lang/String;)Ljava/lang/String;");
	char* tmp;
	if (mid) {
		jstring arg = (env)->NewStringUTF(str);
		jstring msg = (jstring) env->CallObjectMethod(object, mid, arg);
		if (msg) {
			const char* rtnstr = env->GetStringUTFChars(msg, 0);
			tmp = (char*) malloc(strlen(rtnstr) + 1);
			strcpy(tmp, rtnstr);
		}
	}
//	delete rtnstr;
	return tmp;
}

bool SignatureBridge::signString(char* certPath, char* certPassword,char* singStr){
	JNIEnv *env;
	jvm->AttachCurrentThread((void **) &env, NULL);
	jclass clazz = env->FindClass("com/tradevan/api/Signature");
	jobject object = env->AllocObject(clazz);
	jmethodID signString = env->GetMethodID(clazz, "signString",
						"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z");
	jstring jcertPath = (env)->NewStringUTF(certPath);
	jstring jcertPassword = (env)->NewStringUTF(certPassword);
	jstring jsingStr = (env)->NewStringUTF(singStr);
	bool flag = env->CallObjectMethod(object, signString, jcertPath,
			jcertPassword, jsingStr);
	if (flag) {
		jvm->AttachCurrentThread((void **) &env, NULL);
		jmethodID sign = env->GetMethodID(clazz, "getSignature",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		const char* rtnstr = env->GetStringUTFChars(msg, 0);
		char* tmp = (char*) malloc(strlen(rtnstr) + 1);
		strcpy(tmp, rtnstr);
		this->signatureStr = tmp;
	} else {
		jvm->AttachCurrentThread((void **) &env, NULL);
		jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		const char* rtnstr = env->GetStringUTFChars(msg, 0);
		char* tmp = (char*) malloc(strlen(rtnstr) + 1);
		strcpy(tmp, rtnstr);
		this->errMsg = tmp;
	}
	return flag;
}

bool SignatureBridge::sign(int invoiceCount, char* format, char* migVer,
		char* json, char* certPath, char* certPassword, char* fromPartyId,
		char* fromRoutingId, char* fromVacDescription, char* toPartyId,
		char* toRoutingId, char* toVacDescription) {
	JNIEnv *env;
	jvm->AttachCurrentThread((void **) &env, NULL);
	jclass clazz = env->FindClass("com/tradevan/api/Signature");
	jobject object = env->AllocObject(clazz);
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
	bool flag = env->CallObjectMethod(object, sign, invoiceCount, jformat,
			jmigVer, jjson, jcertPath, jcertPassword, jfromPartyId,
			jfromRoutingId, jfromVacDescription, jtoPartyId, jtoRoutingId,
			jtoVacDescription);

	if(flag) {
		jvm->AttachCurrentThread((void **) &env, NULL);
		jmethodID sign = env->GetMethodID(clazz, "getSignature",
					"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);

		const char* rtnstr = env->GetStringUTFChars(msg, 0);
		char* tmp = (char*) malloc(strlen(rtnstr) + 1);
		strcpy(tmp, rtnstr);
		this->signatureStr = tmp;

	} else {
		jvm->AttachCurrentThread((void **) &env, NULL);
		jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
					"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		const char* rtnstr = env->GetStringUTFChars(msg, 0);
		char* tmp = (char*) malloc(strlen(rtnstr) + 1);
		strcpy(tmp, rtnstr);
		this->errMsg = tmp;
	}

//	flag = this->exception(env);

	return flag;
}
bool SignatureBridge::exception(JNIEnv *env){
	jthrowable excp = 0;
	excp = env->ExceptionOccurred();
	if(excp)
	{
		jclass cls = env->GetObjectClass(excp);
		env->ExceptionClear();
		jmethodID mid = env->GetMethodID(cls, "toString","()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(excp, mid);
		const char* rtnstr = env->GetStringUTFChars(msg, 0);
		char* tmp = (char*) malloc(strlen(rtnstr) + 1);
		strcpy(tmp, rtnstr);
		this->exceptionMsg = tmp;
		env->ExceptionClear();
		return false;
	}
	return true;
}

char* SignatureBridge::getExceptionMsg(){
	return this->exceptionMsg;
};

bool SignatureBridge::unSign(char* unSignature, bool isJSON) {
	JNIEnv *env;
	jvm->AttachCurrentThread((void **) &env, NULL);
	jclass clazz;
	jobject object;
	clazz = env->FindClass("com/tradevan/api/Signature");
	object = env->AllocObject(clazz);
	jmethodID unsign = env->GetMethodID(clazz, "unSing",
			"(Ljava/lang/String;Z)Z");
	jstring junSignature = (env)->NewStringUTF(unSignature);
	bool flag = env->CallObjectMethod(object, unsign, junSignature, isJSON);
	if(flag) {
		jvm->AttachCurrentThread((void **) &env, NULL);
		jmethodID sign = env->GetMethodID(clazz, "getMigMsg",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		const char* rtnstr = env->GetStringUTFChars(msg, 0);
		char* tmp = (char*) malloc(strlen(rtnstr) + 1);
		strcpy(tmp, rtnstr);
		this->migMsg = tmp;
	} else {
		jvm->AttachCurrentThread((void **) &env, NULL);
		jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
					"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		const char* rtnstr = env->GetStringUTFChars(msg, 0);
		char* tmp = (char*) malloc(strlen(rtnstr) + 1);
		strcpy(tmp, rtnstr);
		this->errMsg = tmp;
	}
	return flag;
}

char* SignatureBridge::getSignature() {
	return this->signatureStr;
}

char* SignatureBridge::getErrMsg() {
	return this->errMsg;
}

char* SignatureBridge::getMigMsg() {
	return this->migMsg;
}
;

} /* namespace jvm */
