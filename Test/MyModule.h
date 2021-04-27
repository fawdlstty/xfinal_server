#define HEADER2STR(x) #x
#ifdef __XS_HEADER2STR__
HEADER2STR (
#endif

#ifndef __MYMODULE_H__
#define __MYMODULE_H__



#include <string>
#include <xs/HttpModule.hpp>

#define XS_T(a)
#define XS_D(a)
#define XS_P(a,b)

XS_T ("MyModule 模块");
XS_D ("模块详细描述内容。。。");
struct MyModule: public xs::XSModule {
	MyModule ();

	XS_T ("hello 方法");
	XS_D ("方法详细描述内容。。。");
	std::string hello ();

	XS_T ("world 方法");
	XS_D ("方法详细描述内容。。。");
	XS_P ("name", "名称")
	std::string world (std::string name);
};



#endif //__MYMODULE_H__

#ifdef __XS_HEADER2STR__
)
#endif
