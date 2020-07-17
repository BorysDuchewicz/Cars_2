#include "engine.h"

std::ostream& operator<<(std::ostream& out, const Engine& w)
{
	return out << engine_type_to_string(w.type) << " " << w.power << std::endl;
}
