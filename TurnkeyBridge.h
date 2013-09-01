#include <string>
#include "JVMService.h"
#ifndef SIGNATURE_H_
#define SIGNATURE_H_

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT std::string testString(char* str);
#ifdef __cplusplus
}
#endif
#endif /* SIGNATURE_H_ */
