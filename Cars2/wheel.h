#pragma once
#include"lib.h"

//struktura przechowujaca informacje o kolach
struct Wheel
{
	std::string model;
	unsigned int size;
	TyreType type;

};

inline std::ostream& operator<<(std::ostream& out, const Wheel& w)
{
	return out <<"Wheel model: "<< w.model << "\nWheel size: " << w.size << "\nTyre type: " << tyre_type_to_string(w.type)<<std::endl;
}

