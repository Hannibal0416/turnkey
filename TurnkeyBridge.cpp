/*
 * TurnkeyBridge.cpp
 *
 *  Created on: 2013/9/1
 *      Author: Hannibal
 */

#include "TurnkeyBridge.h"

static SignatureBridge *sign;
JNIEXPORT std::string testString(char* str) {
	sign->instance((char*) "com/test/StringTest");
	sign->testString(str);
	return "ok";
}
;

JNIEXPORT void init() {
	if (*sign == NULL) {
		*sign = new jvm::SignatureBridge();
		cout << "init()" << endl;
	}
	if (!sign->isJVMAlive()) {
		sign->StartJVM();
		cout << "StartJVM()" << endl;
	}
}
;

JNIEXPORT bool unSign(char* unSignature, bool isJSON) {
	return sign->unSign(unSignature, isJSON);
}
;

JNIEXPORT bool sign(int invoiceCount, char* format, char* migVer, char* json,
		char* certPath, char* certPassword, char* fromPartyId,
		char* fromRoutingId, char* fromVacDescription, char* toPartyId,
		char* toRoutingId, char* toVacDescription) {
	return sign->sign(invoiceCount, format, migVer, json, certPath,
			certPassword, fromPartyId, fromRoutingId, fromVacDescription,
			toPartyId, toRoutingId, toVacDescription);

}
;
JNIEXPORT std::string testString(char* str) {
	return sign->testString(str);
}
;
JNIEXPORT std::string getSignature() {
	return sign->getSignature();
}
;
JNIEXPORT std::string getErrMsg() {
	return sign->getErrMsg();
}
;
JNIEXPORT std::string getMigMsg() {
	return sign->getMigMsg();
}
;

