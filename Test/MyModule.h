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

XS_T ("MyModule ģ��");
XS_D ("ģ����ϸ�������ݡ�����");
struct MyModule: public xs::XSModule {
	MyModule ();

	XS_T ("hello ����");
	XS_D ("������ϸ�������ݡ�����");
	std::string hello ();

	XS_T ("world ����");
	XS_D ("������ϸ�������ݡ�����");
	XS_P ("name", "����")
	std::string world (std::string name);
};



#endif //__MYMODULE_H__

#ifdef __XS_HEADER2STR__
)
#endif
