#include <iostream>

#include "../taskpool/taskpool_t.hpp"
#include <xs/XSServer.hpp>
#include "MyModule.h"

#include "embed/resource_holder.hpp"
namespace rh {
	std::string_view embed (const char *_file) {
		static ResourceHolder r {};
		auto _t = r.FindByFilename (_file) [0].GetArray ();
		return std::string_view ((const char *) _t.begin (), (const char *) _t.end ());
	}
}



int main () {
	xs::XSServer _server;
	_server.register_module<MyModule> (rh::embed ("MyModule.h"));
	std::cin.get ();
	return 0;
}
