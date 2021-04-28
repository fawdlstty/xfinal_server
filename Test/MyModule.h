#ifndef __MYMODULE_H__
#define __MYMODULE_H__

#include <string>
#include <xs/XSModule.hpp>

// name: MyModule 模块
// desp: 模块详细描述内容。。。
struct MyModule: xs::XSModule {
	MyModule ();

	// name: hello 方法
	// desp: 方法详细描述内容。。。
	// return: 招呼语
	static std::string hello ();

	// name: world 方法
	// desp: 方法详细描述内容。。。
	// param:
	//     name: 名称
	// return: 招呼语
	static std::string world (std::string name);
};

#endif //__MYMODULE_H__
