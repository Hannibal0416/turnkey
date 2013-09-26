/*
 * TurnkeyBridge.cpp
 *
 *  Created on: 2013/9/1
 *      Author: Hannibal
 */

#include "GatewayBridge.h"

jvm::SignatureBridge signBridge;

__declspec(dllexport) bool __stdcall initJVM() {
	if (!signBridge.isJVMAlive()) {
		std::cout << "==Starting JVM==" << std::endl;
		if (signBridge.StartJVM()) {
			std::cout << "==JVM is Running==" << std::endl;
			return true;
		} else {
			std::cout << "==Init JVM fail==" << std::endl;
			return false;
		}
	} else {
		std::cout << "==JVM is alive==" << std::endl;
		return true;
	}
}
;
__declspec(dllexport) bool __stdcall destroyJVM() {
	if (signBridge.isJVMAlive()) {
		std::cout << "==destroying JVM==" << std::endl;
		return signBridge.DestroyJVM();
	} else {
		std::cout << "==JVM is down==" << std::endl;
		return true;
	}
}
;

__declspec(dllexport) bool __stdcall unSign(wchar_t* unSignature, bool isJSON) {
	return signBridge.unSign(unSignature, isJSON);
}
;
__declspec(dllexport) bool __stdcall signString(wchar_t* certPath,
		wchar_t* certPassword, wchar_t* singStr) {
	return signBridge.signString(certPath, certPassword, singStr);
}
;
__declspec(dllexport) bool __stdcall sign(int invoiceCount, wchar_t* format,
		wchar_t* migVer, wchar_t* json, wchar_t* certPath, wchar_t* certPassword,
		wchar_t* fromPartyId, wchar_t* fromRoutingId, wchar_t* fromVacDescription,
		wchar_t* toPartyId, wchar_t* toRoutingId, wchar_t* toVacDescription) {
	return signBridge.sign(invoiceCount, format, migVer, json, certPath,
			certPassword, fromPartyId, fromRoutingId, fromVacDescription,
			toPartyId, toRoutingId, toVacDescription);

}
;
__declspec(dllexport) void __stdcall testFile(wchar_t* str,wchar_t* path){
	signBridge.testFile(str,path);
};

__declspec(dllexport) wchar_t* __stdcall testString(wchar_t* str) {
	return signBridge.testString(str);
}
;
__declspec(dllexport) wchar_t* __stdcall getSignature() {
	return signBridge.getSignature();
}
;
__declspec(dllexport) wchar_t* __stdcall getErrMsg() {
	return signBridge.getErrMsg();
}
;
__declspec(dllexport) wchar_t* __stdcall getMigMsg() {
	return signBridge.getMigMsg();
}
;
//JNIEXPORT char* getExceptionMsg(){
//	return signBridge.getExceptionMsg();
//};
