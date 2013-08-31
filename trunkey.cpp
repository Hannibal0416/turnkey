//============================================================================
// Name        : trunkey.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "JVMService.h"
using namespace std;
using namespace jvm;
int main(void) {
	JVMService *jvmInstance = new JVMService();
	cout << "jvmInstance" << endl;
	cout <<"好";
	jvmInstance->BeginJVM();
	jvmInstance->instance((char*)"com/test/StringTest");
	jvmInstance->testString((char*)"功蓋許");
	jvmInstance->testString((char*)"123");
	jvmInstance->testString((char*)"測試");
	jvmInstance->testString((char*)"檔案");
	return EXIT_SUCCESS;
}
