#ifndef __MYMODULE_H__
#define __MYMODULE_H__

#include <string>
#include <xs/XSModule.hpp>

// name: MyModule ģ��
// desp: ģ����ϸ�������ݡ�����
struct MyModule: xs::XSModule {
	MyModule ();

	// name: hello ����
	// desp: ������ϸ�������ݡ�����
	// return: �к���
	static std::string hello ();

	// name: world ����
	// desp: ������ϸ�������ݡ�����
	// param:
	//     name: ����
	// return: �к���
	static std::string world (std::string name);
};

#endif //__MYMODULE_H__
