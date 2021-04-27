#ifdef __XS_HEADER2STR__
R"(
#endif

#ifndef __MYMODULE_H__
#define __MYMODULE_H__



#include <string>
#include <xs/HttpModule.hpp>

// 我的Web服务模块
// 用于提供web服务的控制器模块
struct MyModule: public xs::XSModule {
	MyModule ();

	// [GET] 你好
	// 此函数为测试接口，用于测试调用1
	std::string hello ();

	// [GET] 你好
	// 此函数为测试接口，用于测试调用2
	// @s: 用户名
	std::string world (std::string name);
};



#endif //__MYMODULE_H__

#ifdef __XS_HEADER2STR__
)"
#endif
