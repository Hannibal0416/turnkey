#include <string>
#include "SignatureBridge.h"
#ifndef SIGNATURE_H_
#define SIGNATURE_H_

#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllexport) bool __stdcall unSign(char* unSignature,bool isJSON);
__declspec(dllexport) bool __stdcall signString(char* certPath, char* certPassword,char* singStr);
__declspec(dllexport) bool __stdcall sign( int invoiceCount,char* format,char* migVer,char* json , char* certPath,char* certPassword , char* fromPartyId
		,char* fromRoutingId,char* fromVacDescription,char* toPartyId,char* toRoutingId,char* toVacDescription);
__declspec(dllexport) char* __stdcall testString(char* str);
__declspec(dllexport) char* __stdcall getSignature();
__declspec(dllexport) char* __stdcall getErrMsg();
__declspec(dllexport) char* __stdcall getMigMsg();
__declspec(dllexport) bool __stdcall initJVM();
__declspec(dllexport) bool __stdcall destroyJVM();
#ifdef __cplusplus
}
#endif
#endif /* SIGNATURE_H_ */
