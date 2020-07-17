#pragma once
#include "lib.h"


//struktura przechowujaca informacje ogolne informacje o samochodzie (typ kolor komponenty)
struct CarBody
{
	CarBodyColor color;
	CarBodyType type;
	std::vector<std::string> components;
	
};

inline std::ostream& operator<<(std::ostream& out, const CarBody& w)
{
	out <<"Body color: "<< color_to_string(w.color) << "\nBody type: " << body_type_to_string(w.type) << std::endl;
	out << "Car components: ";
	for (const auto& v:w.components)
	{
		out << v << " ";
	}
	out << std::endl;
	return out;
}
