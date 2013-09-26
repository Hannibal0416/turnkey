
#include "JVMLoader.h"

namespace jvm {

JVMLoader::JVMLoader() {
}

JVMLoader::~JVMLoader() {
}

JavaVM* JVMLoader::jvm = NULL;
HINSTANCE JVMLoader::hInstance = NULL;

bool JVMLoader::StartJVM() {
	std::cout << "JVMLoader::StartJVM()" << std::endl;
	JavaVMOption options[5];
	JavaVMInitArgs vm_args;
	JNIEnv* env = NULL;
	std::string jreHome;
	std::string libDir;
	std::string dllDir = "-Djava.library.path=";
	//char* pathvar = getenv("GATEWAY_HOME");
	LPTSTR lpszBuffer = (LPTSTR)calloc(4096,sizeof(TCHAR));
	DWORD dwRet = GetEnvironmentVariable(TEXT("GATEWAY_HOME"),lpszBuffer,4096);
	std::cout << lpszBuffer << std::endl;
	if(dwRet != 0) {
		libDir = lpszBuffer;
		dllDir += lpszBuffer;
		libDir += "/lib/";
		dllDir += "\\dll\\";
	} else {
		//libDir = "D:/APICSharp/lib/";
		std::cout << "GATEWAY_HOME未設定" << std::endl;
		return false;
	}
	dwRet = GetEnvironmentVariable(TEXT("JVM_LOC"),lpszBuffer,4096);
	if(dwRet != 0) {
		jreHome = lpszBuffer;
		jreHome += "/jvm.dll";
	} else {
		//jreHome = "./jre6/bin/client/jvm.dll";
		std::cout << "JVM_LOC未設定" << std::endl;
		return false;
	}
	free(lpszBuffer);

	std::string libs = "-Djava.class.path=./;";

	std::vector<std::string> files = std::vector<std::string>();
	getdir(libDir, files);
	for (int i = 0; i < files.size(); i++) {
		if (! (files[i] == ".") && !(files[i] == "..")) {
			libs += libDir + files[i] + ";";
		}
	}
	std::cout << dllDir << std::endl;
	options[0].optionString = const_cast<char*>("-Djava.compiler=NONE");
	options[1].optionString = const_cast<char*>(libs.c_str());
	options[2].optionString = const_cast<char*>("-verbose:NONE");
	options[3].optionString = const_cast<char*>("-Dfile.encoding=UTF-8");
	options[4].optionString = const_cast<char*>(dllDir.c_str());

	vm_args.version = JNI_VERSION_1_6;
	vm_args.options = options;
	vm_args.nOptions = 5;

	hInstance = ::LoadLibrary(jreHome.c_str());
	if (hInstance == NULL)
	{
		return false;
	}

	PFunCreateJavaVM funCreateJavaVM = (PFunCreateJavaVM)::GetProcAddress(hInstance, "JNI_CreateJavaVM");
	int res = (*funCreateJavaVM)(&jvm, reinterpret_cast<void**>(&env), &vm_args);
	if(res >= 0 ){
		return true;
	} else {
		return false;
	}
}

bool JVMLoader::DestroyJVM() {
	JNIEnv *env = NULL;
	jvm->AttachCurrentThread(reinterpret_cast<void**>(&env) , NULL);
	jvm->DestroyJavaVM();
	::FreeLibrary(hInstance);
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
	DIR *dp = NULL;
	struct dirent *dirp = NULL;
	if ((dp = opendir(dir.c_str())) == NULL) {
		std::cout << "Error(" << errno << ") opening " << dir << std::endl;
		return errno;
	}
	while ((dirp = readdir(dp)) != NULL) {
		files.push_back(std::string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}
} /* namespace jvm */
