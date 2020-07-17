#include "wheel.h"


std::ostream& operator<<(std::ostream& out, const Wheel& w)
{
	 out << w.model << " " << w.size << " " << tyre_type_to_string(w.type) << std::endl;
	 return out;
}
