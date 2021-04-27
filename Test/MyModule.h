#define HEADER2STR(x) #x
#ifdef __XS_HEADER2STR__
HEADER2STR (
#endif

#ifndef __MYMODULE_H__
#define __MYMODULE_H__



#include <string>
#include <xs/HttpModule.hpp>

/* MyModule */
struct MyModule: public xs::XSModule {
	MyModule ();

	// func hello
	std::string hello ();

	// func world
	std::string world (std::string name);
};



#endif //__MYMODULE_H__

#ifdef __XS_HEADER2STR__
)
#endif
