#include "appdata.hpp"

Appdata& Appdata::get_instance() {
	static Appdata appdata;
	return appdata;
}
