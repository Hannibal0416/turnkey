/*
 * TurnkeyBridge.cpp
 *
 *  Created on: 2013/9/1
 *      Author: Hannibal
 */

#include "TurnkeyBridge.h"

jvm::SignatureBridge signBridge;

JNIEXPORT void initJVM() {
	if (!signBridge.isJVMAlive()) {
		signBridge.StartJVM();
		std::cout << "StartJVM()" << std::endl;
	}
}
;

JNIEXPORT void instance() {
	signBridge.instance();
}
;


JNIEXPORT bool unSign(char* unSignature, bool isJSON) {
	return signBridge.unSign(unSignature, isJSON);
}
;

JNIEXPORT bool sign(int invoiceCount, char* format, char* migVer, char* json,
		char* certPath, char* certPassword, char* fromPartyId,
		char* fromRoutingId, char* fromVacDescription, char* toPartyId,
		char* toRoutingId, char* toVacDescription) {
	return signBridge.sign(invoiceCount, format, migVer, json, certPath,
			certPassword, fromPartyId, fromRoutingId, fromVacDescription,
			toPartyId, toRoutingId, toVacDescription);

}
;
JNIEXPORT std::string testString(char* str) {
	return signBridge.testString(str);
}
;
JNIEXPORT std::string getSignature() {
	return signBridge.getSignature();
}
;
JNIEXPORT std::string getErrMsg() {
	return signBridge.getErrMsg();
}
;
JNIEXPORT std::string getMigMsg() {
	return signBridge.getMigMsg();
}
;

