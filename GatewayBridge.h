#include <string>
#include "SignatureBridge.h"
#ifndef SIGNATURE_H_
#define SIGNATURE_H_

#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllexport) bool __stdcall unSign(wchar_t* unSignature,bool isJSON);
__declspec(dllexport) bool __stdcall signString(wchar_t* certPath, wchar_t* certPassword,wchar_t* singStr);
__declspec(dllexport) bool __stdcall sign( int invoiceCount,wchar_t* format,wchar_t* migVer,wchar_t* json , wchar_t* certPath,wchar_t* certPassword , wchar_t* fromPartyId
		,wchar_t* fromRoutingId,wchar_t* fromVacDescription,wchar_t* toPartyId,wchar_t* toRoutingId,wchar_t* toVacDescription);
__declspec(dllexport) wchar_t* __stdcall testString(wchar_t* str);
__declspec(dllexport) void __stdcall testFile(wchar_t* str,wchar_t* path);
__declspec(dllexport) wchar_t* __stdcall getSignature();
__declspec(dllexport) wchar_t* __stdcall getErrMsg();
__declspec(dllexport) wchar_t* __stdcall getMigMsg();
__declspec(dllexport) bool __stdcall initJVM();
__declspec(dllexport) bool __stdcall destroyJVM();
#ifdef __cplusplus
}
#endif
#endif /* SIGNATURE_H_ */
