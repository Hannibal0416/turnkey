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
	this->errMsg = NULL;
	this->migMsg = NULL;
	this->signatureStr = NULL;
	this->exceptionMsg = NULL;
};

std::wstring jstringToWindows(JNIEnv *env, jstring jstr);
jstring WindowsTojstring(JNIEnv* env, wchar_t* str) ;

void SignatureBridge::testFile(wchar_t* str,wchar_t* path) {
	JNIEnv *env = NULL;
	jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	jclass clazz = env->FindClass("com/tradevan/api/Signature");
	jobject object = env->AllocObject(clazz);
	jmethodID mid = env->GetMethodID(clazz, "testFile",
			"(Ljava/lang/String;Ljava/lang/String;)V");
	jstring jstr = WindowsTojstring(env, str);
	jstring jpath = WindowsTojstring(env, path);
	jstring msg = (jstring) env->CallObjectMethod(object, mid, jstr ,jpath);
	jvm->DetachCurrentThread();
}

wchar_t* SignatureBridge::testString(wchar_t* str) {
	JNIEnv *env = NULL;
	jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	jclass clazz = env->FindClass("com/tradevan/api/Signature");
	jobject object = env->AllocObject(clazz);
	jmethodID mid = env->GetMethodID(clazz, "testString",
			"(Ljava/lang/String;)Ljava/lang/String;");
	jstring arg = WindowsTojstring(env, str);
	jstring msg = (jstring) env->CallObjectMethod(object, mid, arg);
	std::wstring rtnstr = jstringToWindows(env, msg);
	jvm->DetachCurrentThread();
	return const_cast<wchar_t*>(rtnstr.c_str());
}

bool SignatureBridge::signString(wchar_t* certPath, wchar_t* certPassword,
		wchar_t* singStr) {
	JNIEnv *env = NULL;
	jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	jclass clazz = env->FindClass("com/tradevan/api/Signature");
	jobject object = env->AllocObject(clazz);
	jmethodID signString = env->GetMethodID(clazz, "signString",
			"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z");
	jstring jcertPath = WindowsTojstring(env,certPath);
	jstring jcertPassword = WindowsTojstring(env,certPassword);
	jstring jsingStr = WindowsTojstring(env,singStr);
	bool flag = env->CallObjectMethod(object, signString, jcertPath,
			jcertPassword, jsingStr);
	if (flag) {
		jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
		jmethodID sign = env->GetMethodID(clazz, "getSignature",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		std::wstring rtnstr = jstringToWindows(env,msg);
		this->signatureStr = const_cast<wchar_t*>(rtnstr.c_str());
	} else {
		jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
		jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		std::wstring rtnstr = jstringToWindows(env,msg);
		this->errMsg = const_cast<wchar_t*>(rtnstr.c_str());
	}
	jvm->DetachCurrentThread();
	return flag;
}

bool SignatureBridge::sign(int invoiceCount, wchar_t* format, wchar_t* migVer,
		wchar_t* json, wchar_t* certPath, wchar_t* certPassword, wchar_t* fromPartyId,
		wchar_t* fromRoutingId, wchar_t* fromVacDescription, wchar_t* toPartyId,
		wchar_t* toRoutingId, wchar_t* toVacDescription) {
	JNIEnv *env = NULL;
	jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	jclass clazz = env->FindClass("com/tradevan/api/Signature");
	jobject object = env->AllocObject(clazz);
	jmethodID sign =
			env->GetMethodID(clazz, "sign",
					"(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z");

	jstring jformat =WindowsTojstring(env,format);
	jstring jmigVer = WindowsTojstring(env,migVer);
	jstring jjson = WindowsTojstring(env,json);
	jstring jcertPath = WindowsTojstring(env,certPath);
	jstring jcertPassword = WindowsTojstring(env,certPassword);
	jstring jfromPartyId = WindowsTojstring(env,fromPartyId);
	jstring jfromRoutingId = WindowsTojstring(env,fromRoutingId);
	jstring jfromVacDescription = WindowsTojstring(env,fromVacDescription);
	jstring jtoPartyId = WindowsTojstring(env,toPartyId);
	jstring jtoRoutingId = WindowsTojstring(env,toRoutingId);
	jstring jtoVacDescription = WindowsTojstring(env,toVacDescription);
	bool flag = env->CallObjectMethod(object, sign, invoiceCount, jformat,
			jmigVer, jjson, jcertPath, jcertPassword, jfromPartyId,
			jfromRoutingId, jfromVacDescription, jtoPartyId, jtoRoutingId,
			jtoVacDescription);

	if (flag) {
		jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
		jmethodID sign = env->GetMethodID(clazz, "getSignature",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		std::wstring rtnstr = jstringToWindows(env,msg);
		this->signatureStr = const_cast<wchar_t*>(rtnstr.c_str());

	} else {
		jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
		jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		std::wstring rtnstr = jstringToWindows(env,msg);
		this->errMsg = const_cast<wchar_t*>(rtnstr.c_str());
	}

//	flag = this->exception(env);
	jvm->DetachCurrentThread();
	return flag;
}
bool SignatureBridge::exception(JNIEnv *env) {
	jthrowable excp = 0;
	excp = env->ExceptionOccurred();
	if (excp) {
		jclass cls = env->GetObjectClass(excp);
		env->ExceptionClear();
		jmethodID mid = env->GetMethodID(cls, "toString",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(excp, mid);
		std::wstring rtnstr = jstringToWindows(env,msg);
		this->exceptionMsg = const_cast<wchar_t*>(rtnstr.c_str());
		env->ExceptionClear();
		return false;
	}
	return true;
}

wchar_t* SignatureBridge::getExceptionMsg() {
	return this->exceptionMsg;
}
;

bool SignatureBridge::unSign(wchar_t* unSignature, bool isJSON) {
	JNIEnv *env = NULL;
	jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
	jclass clazz;
	jobject object;
	clazz = env->FindClass("com/tradevan/api/Signature");
	object = env->AllocObject(clazz);
	jmethodID unsign = env->GetMethodID(clazz, "unSing",
			"(Ljava/lang/String;Z)Z");
	jstring junSignature = WindowsTojstring(env,unSignature);
	bool flag = env->CallObjectMethod(object, unsign, junSignature, isJSON);
	if (flag) {
		jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
		jmethodID sign = env->GetMethodID(clazz, "getMigMsg",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		std::wstring rtnstr = jstringToWindows(env,msg);
		this->migMsg = const_cast<wchar_t*>(rtnstr.c_str());
	} else {
		jvm->AttachCurrentThread(reinterpret_cast<void**>(&env), NULL);
		jmethodID sign = env->GetMethodID(clazz, "getErrMsg",
				"()Ljava/lang/String;");
		jstring msg = (jstring) env->CallObjectMethod(object, sign);
		std::wstring rtnstr = jstringToWindows(env,msg);
		this->errMsg = const_cast<wchar_t*>(rtnstr.c_str());
	}
	jvm->DetachCurrentThread();
	return flag;
}

wchar_t* SignatureBridge::getSignature() {
	return this->signatureStr;
}

wchar_t* SignatureBridge::getErrMsg() {
	return this->errMsg;
}

wchar_t* SignatureBridge::getMigMsg() {
	return this->migMsg;
}
;


jstring WindowsTojstring(JNIEnv* env, wchar_t* str) {
	jstring objectName = NULL;
	unsigned int len = wcslen(str);
	objectName = (env)->NewString( (jchar*)str, len);
	return objectName;
}

std::wstring jstringToWindows(JNIEnv *env, jstring jstr) {
	std::wstring value;
	const jchar *raw = env->GetStringChars(jstr, 0);
	jsize len = env->GetStringLength(jstr);
	const jchar *temp = raw;
	while (len > 0) {
		value += *(temp++);
		len--;
	}
	env->ReleaseStringChars(jstr, raw);
	return value;

}


/*
 *

char* SignatureBridge::WcharToChar(wchar_t* wc)
{
    Release();
    int len= WideCharToMultiByte(CP_ACP,0,wc,wcslen(wc),NULL,0,NULL,NULL);
    m_char=new char[len+1];
    WideCharToMultiByte(CP_ACP,0,wc,wcslen(wc),m_char,len,NULL,NULL);
    m_char[len]='\0';
    return m_char;
}
wchar_t* SignatureBridge::CharToWchar(char* c)
{
    Release();
    int len = MultiByteToWideChar(CP_ACP,0,c,strlen(c),NULL,0);
    m_wchar=new wchar_t[len+1];
    MultiByteToWideChar(CP_ACP,0,c,strlen(c),m_wchar,len);
    m_wchar[len]='\0';
    return m_wchar;
}
void SignatureBridge::Release()
{
    if(m_char)
    {
        delete m_char;
        m_char=NULL;
    }
    if(m_wchar)
    {
        delete m_wchar;
        m_wchar=NULL;
    }
}

char* jstringToWindows(JNIEnv *env, jstring jstr) { //UTF8/16转换成gb2312
	int length = (env)->GetStringLength(jstr);
	const jchar* jcstr = (env)->GetStringChars(jstr, 0);
	char* rtn = (char*) malloc(length * 2 + 1);
	int size = 0;
	size = WideCharToMultiByte( CP_ACP, 0, (LPCWSTR) jcstr, length, rtn,
			(length * 2 + 1), NULL, NULL);
	if (size <= 0)
		return NULL;
	(env)->ReleaseStringChars(jstr, jcstr);
	rtn[size] = 0;
	return rtn;
}



jstring WindowsTojstring(JNIEnv* env, const char* str) { //gb2312转换成utf8/16
	jstring rtn = 0;
	int slen = strlen(str);
	unsigned short * buffer = 0;
	if (slen == 0)
		rtn = (env)->NewStringUTF(str);
	else {
		int length = MultiByteToWideChar( CP_ACP, 0, (LPCSTR) str, slen, NULL,
				0);
		buffer = (unsigned short *) malloc(length * 2 + 1);
		if (MultiByteToWideChar( CP_ACP, 0, (LPCSTR) str, slen, (LPWSTR) buffer,
				length) > 0)
			rtn = (env)->NewString((jchar*) buffer, length);
	}
	if (buffer)
		free(buffer);
	return rtn;
}

*/



} /* namespace jvm */
