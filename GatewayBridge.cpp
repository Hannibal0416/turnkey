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

__declspec(dllexport) bool __stdcall unSign(char* unSignature, bool isJSON) {
	return signBridge.unSign(unSignature, isJSON);
}
;
__declspec(dllexport) bool __stdcall signString(char* certPath, char* certPassword, char* singStr) {
	return signBridge.signString(certPath, certPassword,singStr);
}
;
__declspec(dllexport) bool __stdcall sign(int invoiceCount, char* format, char* migVer, char* json,
		char* certPath, char* certPassword, char* fromPartyId,
		char* fromRoutingId, char* fromVacDescription, char* toPartyId,
		char* toRoutingId, char* toVacDescription) {
	return signBridge.sign(invoiceCount, format, migVer, json, certPath,
			certPassword, fromPartyId, fromRoutingId, fromVacDescription,
			toPartyId, toRoutingId, toVacDescription);

}
;
//JNIEXPORT char* testFile(char* str){
//	signBridge.testFile(str);
//};

__declspec(dllexport) char* __stdcall testString(char* str) {
	return signBridge.testString(str);
}
;

__declspec(dllexport) char* __stdcall getSignature() {
	return signBridge.getSignature();
}
;
__declspec(dllexport) char* __stdcall getErrMsg() {
	return signBridge.getErrMsg();
}
;
__declspec(dllexport) char* __stdcall getMigMsg() {
	return signBridge.getMigMsg();
}
;
//JNIEXPORT char* getExceptionMsg(){
//	return signBridge.getExceptionMsg();
//};
