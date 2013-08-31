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
class JVMService: public jvm::JVMLoader {
public:
	JVMService();
	bool instance(char* className);
	char* testString (char* str);
};

} /* namespace jvm */
#endif /* JVMSERVICE_H_ */
