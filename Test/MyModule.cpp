#include <string>

#include "MyModule.h"



MyModule::MyModule () {
#define __XS_HEADER2STR__
	std::string _src_code =
#include "MyModule.h"
		;
	_src_code = _src_code;
#undef __XS_HEADER2STR__
}

std::string MyModule::hello () {
	return "";
}

std::string MyModule::world (std::string name) {
	return "";
}
