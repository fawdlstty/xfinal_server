#include <string>

#include "MyModule.h"



MyModule::MyModule () {
	register_func ("hello", &MyModule::hello);
}

std::string MyModule::hello () {
	return "";
}

std::string MyModule::world (std::string name) {
	return "";
}
