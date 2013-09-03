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
#include <sstream>
#include <fstream>
#include "TurnkeyBridge.h"
using namespace std;

int main(void) {
//	if (!SetConsoleCP(CP_UTF8))
//	{
//	    // An error occurred; handle it. Call GetLastError() for more information.
//	    // ...
//	}
//	if (!SetConsoleOutputCP(CP_UTF8))
//	{
//	    // An error occurred; handle it. Call GetLastError() for more information.
//	    // ...
//	}
	initJVM();
	instance();
	cout << testString((char*) "功蓋許") << endl;

//	ifstream infile("d:/example.txt");
//	string line;
//	string json;
//	while (std::getline(infile, line)) {
//		json += line;
//	}
//
//	bool flag = sign(1, (char*) "C0401", (char*) "v30", (char*) json.c_str(),
//			(char*) "D:/0001_00002222.pfx", (char*) "00002222", (char*) "fromPartyId",
//			(char*) "fromRoutingId", (char*) "fromVacDescription", (char*) "toPartyId", (char*) "toRoutingId",
//			(char*) "toVacDescription");
//	char* sigStr;
//	if (flag) {
//		sigStr = (char*)getSignature().c_str();
////		std::cout << sigStr << std::endl;
//	} else {
//		std::cout << getErrMsg() << std::endl;
//	}
//
//	flag = unSign(sigStr,true);
//
//	if (flag) {
//		sigStr = (char*)getMigMsg().c_str() ;
//		std::cout << sigStr << std::endl;
//	} else {
//		std::cout << getErrMsg() << std::endl;
//	}

//	bool flag = unSign((char*)json.c_str(),true);
//
//	if (flag) {
//		char* sigStr = (char*)getMigMsg().c_str() ;
//		std::cout << sigStr << std::endl;
//	} else {
//		std::cout << getErrMsg() << std::endl;
//	}
	return EXIT_SUCCESS;
}

//
