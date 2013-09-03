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
	bool instance();
	bool sign(int invoiceCount, char* format, char* migVer, char* json,
			char* certPath, char* certPassword, char* fromPartyId,
			char* fromRoutingId, char* fromVacDescription, char* toPartyId,
			char* toRoutingId, char* toVacDescription);
	bool unSign(char* unSignature, bool isJSON);
	std::string getSignature();
	std::string getErrMsg();
	std::string getMigMsg();
	std::string testString(char* str);
private :
	std::string errMsg;
	std::string migMsg;
	std::string signatureStr;
};

} /* namespace jvm */
#endif /* JVMSERVICE_H_ */
