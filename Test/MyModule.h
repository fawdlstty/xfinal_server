#ifdef __XS_HEADER2STR__
R"(
#endif

#ifndef __MYMODULE_H__
#define __MYMODULE_H__



#include <string>
#include <xs/HttpModule.hpp>

// �ҵ�Web����ģ��
// �����ṩweb����Ŀ�����ģ��
struct MyModule: public xs::XSModule {
	MyModule ();

	// [GET] ���
	// �˺���Ϊ���Խӿڣ����ڲ��Ե���1
	std::string hello ();

	// [GET] ���
	// �˺���Ϊ���Խӿڣ����ڲ��Ե���2
	// @s: �û���
	std::string world (std::string name);
};



#endif //__MYMODULE_H__

#ifdef __XS_HEADER2STR__
)"
#endif
