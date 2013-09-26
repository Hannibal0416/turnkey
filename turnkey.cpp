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
#include <locale.h>
#include "GatewayBridge.h"
using namespace std;

int main(void) {

	//setlocale(LC_CTYPE, "");

	if(initJVM()) {
		wprintf(L"%s\n",testString(L"功蓋"));
		testFile(L"功蓋許",L"c:/ttt.txt");
//		ifstream infile("d:/example.txt");
//		string line;
//		string json;
//		while (std::getline(infile, line)) {
//			json += line;
//		}
		wstring type = L"C0401";
		wstring format = L"v30";
		wstring pfx = L"D:/0001_00002222.pfx";
		wstring psw = L"00002222";
		wstring json = L"[{ \"CancelInvoiceNumber\": \"VN28775601\", \"InvoiceDate\": \"2013-08-20\", \"BuyerId\": \"0000000000\", \"SellerId\": \"00008000\", \"CancelDate\": \"2013-09-10\", \"CancelTime\": \"2013-09-10T08:22:26\", \"CancelReason\": \"資料錯誤\" }]";
		wstring fromPartyId = L"fromPartyId";
		wstring fromRoutingId = L"fromRoutingId";
		wstring fromVacDescription = L"fromVacDescription";
		wstring toPartyId = L"toPartyId";
		wstring toRoutingId = L"toRoutingId";
		wstring toVacDescription = L"toVacDescription";

		bool flag = sign(1, (wchar_t*)type.c_str(),(wchar_t*) format.c_str(), (wchar_t*)json.c_str(),
				(wchar_t*)pfx.c_str(),(wchar_t*) psw.c_str(), (wchar_t*)fromPartyId.c_str(),
				(wchar_t*)fromRoutingId.c_str(), (wchar_t*)fromVacDescription.c_str(), (wchar_t*)toPartyId.c_str(), (wchar_t*)toRoutingId.c_str(),
				(wchar_t*)toVacDescription.c_str());
		wchar_t* sigStr;
		if (flag) {
			sigStr = getSignature();
			std::wcout << sigStr << std::endl;
		} else {
			std::wcout << getErrMsg() << std::endl;
		}
//		flag = signString((wchar_t*)pfx.c_str(),(wchar_t*) psw.c_str(),(wchar_t*) fromPartyId.c_str());
//		if (flag) {
//			wcout << getSignature() << endl;
//		} else {
//			wcout << getErrMsg() << endl;
//		}
	}

//	flag = unSign(sigStr,true);
//
//	if (flag) {
//		sigStr = (char*)getMigMsg().c_str() ;
//		std::cout << sigStr << std::endl;
//	} else {
//		std::cout << getErrMsg() << std::endl;
//	}
//
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
