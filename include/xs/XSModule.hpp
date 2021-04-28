#ifndef __XS_MODULE_HPP__
#define __XS_MODULE_HPP__



#include <string>



namespace xs {
	struct XSModule {
		template<typename F>
		void register_func (std::string func_name, const F &f) {

		}
	};
}



#endif //__XS_MODULE_HPP__
