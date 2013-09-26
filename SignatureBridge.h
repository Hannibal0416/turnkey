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
	bool sign(int invoiceCount, wchar_t* format, wchar_t* migVer, wchar_t* json,
			wchar_t* certPath, wchar_t* certPassword, wchar_t* fromPartyId,
			wchar_t* fromRoutingId, wchar_t* fromVacDescription, wchar_t* toPartyId,
			wchar_t* toRoutingId, wchar_t* toVacDescription);
	bool unSign(wchar_t* unSignature, bool isJSON);
	bool signString(wchar_t* certPath, wchar_t* certPassword,wchar_t* singStr);
	wchar_t* getSignature();
	wchar_t* getErrMsg();
	wchar_t* getMigMsg();
	wchar_t* testString(wchar_t* str);
    void testFile(wchar_t* str,wchar_t* path);
	wchar_t* getExceptionMsg();
//	char* WcharToChar(wchar_t* wc);
//	wchar_t* CharToWchar(char* c);
//	void Release();
private :
	wchar_t* errMsg;
	wchar_t* migMsg;
	wchar_t* signatureStr;
	wchar_t* exceptionMsg;
	bool exception(JNIEnv *env);
//    char* m_char;
//    wchar_t* m_wchar;
};

} /* namespace jvm */
#endif /* JVMSERVICE_H_ */
