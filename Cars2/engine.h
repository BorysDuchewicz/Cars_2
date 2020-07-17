#pragma once
#include"lib.h"

//struktura przechowujaca informacje o silniku
struct Engine
{
	EngineType type;
	unsigned long power;

};

inline std::ostream& operator<<(std::ostream& out, const Engine& w)
{
	 return out << "Engine type: "<<engine_type_to_string(w.type) << "\nEngine power: " << w.power<<std::endl;		
}

