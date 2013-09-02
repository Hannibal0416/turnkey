#include <string>
#include "JVMService.h"
#ifndef SIGNATURE_H_
#define SIGNATURE_H_

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT  bool unSign(char* unSignature,bool isJSON);
JNIEXPORT bool sign( int invoiceCount,char* format,char* migVer,char* json , char* certPath,char* certPassword , char* fromPartyId
		,char* fromRoutingId,char* fromVacDescription,char* toPartyId,char* toRoutingId,char* toVacDescription);
JNIEXPORT std::string testString(char* str);
JNIEXPORT std::string getSignature();
JNIEXPORT std::string getErrMsg();
JNIEXPORT std::string getMigMsg();
#ifdef __cplusplus
}
#endif
#endif /* SIGNATURE_H_ */
