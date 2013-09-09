/*
 * JVMService.h
 *
 *  Created on: 2013/8/31
 *      Author: Hannibal
 */

#ifndef JVMSERVICE_H_
#define JVMSERVICE_H_

#include "JVMLoader.h"

namespace jvm {
class SignatureBridge: public jvm::JVMLoader {
public:
	SignatureBridge();
	bool sign(int invoiceCount, char* format, char* migVer, char* json,
			char* certPath, char* certPassword, char* fromPartyId,
			char* fromRoutingId, char* fromVacDescription, char* toPartyId,
			char* toRoutingId, char* toVacDescription);
	bool unSign(char* unSignature, bool isJSON);
	bool signString(char* certPath, char* certPassword,char* singStr);
	char* getSignature();
	char* getErrMsg();
	char* getMigMsg();
	char* testString(char* str);
	char* testFile(char* str);
	char* getExceptionMsg();
private :
	char* errMsg;
	char* migMsg;
	char* signatureStr;
	char* exceptionMsg;
	bool exception(JNIEnv *env);
};

} /* namespace jvm */
#endif /* JVMSERVICE_H_ */
