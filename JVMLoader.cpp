/*
 * JVMLoader.cpp
 *
 *  Created on: 2013/8/31
 *      Author: Hannibal
 */

#include "JVMLoader.h"

namespace jvm {


JVMLoader::JVMLoader() {
}

JVMLoader::~JVMLoader() {
}


JavaVM* JVMLoader::jvm = NULL;

bool JVMLoader::StartJVM() {
	JavaVMOption options[4];
	JavaVMInitArgs vm_args;
	JNIEnv* env = NULL;
	LPSTR lpszBuffer = (LPSTR)calloc(4096,sizeof(TCHAR));
	DWORD dwRet = GetEnvironmentVariable(TEXT("TURNKEY_HOME"),lpszBuffer,4096);
	std::string jreHome;
	std::string libDir;
	//資料夾路徑(絕對位址or相對位址)
	if(dwRet != 0) {
		libDir = lpszBuffer;
		libDir += "/lib/";
	} else {
		libDir = "./lib/";
	}
	dwRet = GetEnvironmentVariable(TEXT("JRE_HOME"),lpszBuffer,4096);
	if(dwRet != 0) {
		jreHome = lpszBuffer;
		jreHome += "/bin/server/jvm.dll";
	} else {
		jreHome = "./jre7/bin/server/jvm.dll";
	}
	free(lpszBuffer);

	std::string libs = "-Djava.class.path=./;";

	std::vector<std::string> files = std::vector<std::string>();
	getdir(libDir, files);
	//輸出資料夾和檔案名稱於螢幕
	for (int i = 0; i < files.size(); i++) {
		if (! (files[i] == ".") && !(files[i] == "..")) {
			libs += libDir + files[i] + ";";
		}
	}

	options[0].optionString = "-Djava.compiler=NONE";
	options[1].optionString = (char*) libs.c_str();
	options[2].optionString = "-verbose:NONE";
	options[3].optionString = "-Dfile.encoding=UTF-8";

	vm_args.version = JNI_VERSION_1_6;
	vm_args.options = options;
	vm_args.nOptions = 4;

	HINSTANCE hInstance = ::LoadLibrary(jreHome.c_str());

	if (hInstance == NULL)
	{
		return false;
	}
	PFunCreateJavaVM funCreateJavaVM = (PFunCreateJavaVM)::GetProcAddress(hInstance, "JNI_CreateJavaVM");
	int res = (*funCreateJavaVM)(&jvm, (void**)&env, &vm_args);
	if(res >= 0 ){
		return true;
	} else {
		return false;
	}
}

bool JVMLoader::DestroyJVM() {
	jvm->DestroyJavaVM();
	return true;
}

bool JVMLoader::isJVMAlive() {
	if(jvm != NULL) {
		return true;
	} else {
		return false;
	}
}
int getdir(std::string dir, std::vector<std::string> &files) {
	DIR *dp; //創立資料夾指標
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL) {
		std::cout << "Error(" << errno << ") opening " << dir << std::endl;
		return errno;
	}
	while ((dirp = readdir(dp)) != NULL) { //如果dirent指標非空
		files.push_back(std::string(dirp->d_name)); //將資料夾和檔案名放入vector
	}
	closedir(dp); //關閉資料夾指標
	return 0;
}
} /* namespace jvm */
