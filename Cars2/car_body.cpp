#include "car_body.h"

std::ostream& operator<<(std::ostream& out, const CarBody& w)
{
	out <<color_to_string(w.color) << " " << body_type_to_string(w.type) << " ";
	for (int i=0;i<w.components.size();++i)
	{
		out << w.components[i] << " ";
	}
	out << std::endl;
	return out;
}
