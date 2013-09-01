/*
 * TurnkeyBridge.cpp
 *
 *  Created on: 2013/9/1
 *      Author: Hannibal
 */

#include "TurnkeyBridge.h"

JNIEXPORT std::string testString(char* str){
	jvm::SignatureBridge *sign = new jvm::SignatureBridge();
	if(!sign->isJVMAlive()) {
		sign->BeginJVM();
	}
	sign->instance((char*)"com/test/StringTest");
	sign->testString(str);
	return "ok";
};
