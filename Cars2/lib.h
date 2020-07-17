#pragma once
#include<iostream>
#include<memory>
#include<fstream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<regex>
#include"json.hpp"
#include "app_exception.h"

using json = nlohmann::json;

enum class EngineType{DIESEL,GASOLINE,LPG};
enum class TyreType{WINTER,SUMMER};
enum class CarBodyColor{ BLACK,SILVER,WHITE,RED,BLUE,GREEN };
enum class CarBodyType{SEDAN,HATCHBACK,COMBI};

static const std::vector<std::string> EngineTypeValues = { "DIESEL","GASOLINE","LPG" };
static const std::vector<std::string> TyreTypeValues = { "WINTER","SUMMER" };
static const std::vector<std::string> CarBodyColorValues = { "BLACK","SILVER","WHITE"," RED","BLUE","GREEN" };
static const std::vector<std::string> CarBodyTypeValues = { "SEDAN","HATCHBACK","COMBI" };

inline EngineType str_to_engine_type(const std::string& txt)
{
	if(txt=="DIESEL")
	{
		return EngineType::DIESEL;
	}
	else if (txt == "GASOLINE")
	{
		return EngineType::DIESEL;
	}
	else if (txt == "LPG")
	{
		return EngineType::LPG;
	}
	throw AppException("no engine type for value");
}
inline std::string engine_type_to_string(EngineType engine_type)
{
	return EngineTypeValues[static_cast<int>(engine_type)];
}

inline TyreType str_to_tyre_type(const std::string& txt)
{
	if (txt == "WINTER")
	{
		return TyreType::WINTER;
	}
	else if (txt == "SUMMER")
	{
		return TyreType::SUMMER;
	}
	throw AppException("no tyre type for value" + txt);
}

inline std::string tyre_type_to_string(TyreType tyre_type)
{
	return TyreTypeValues[static_cast<int>(tyre_type)];
}

inline  CarBodyColor str_to_body_color(const std::string& txt)
{
	if (txt == "BLACK")
	{
		return CarBodyColor::BLACK;
	}
	else if (txt == "SILVER")
	{
		return CarBodyColor::SILVER;
	}
	else if (txt == "WHITE")
	{
		return CarBodyColor::WHITE;
	}
	else if (txt == "RED")
	{
		return CarBodyColor::RED;
	}
	else if (txt == "BLUE")
	{
		return CarBodyColor::BLUE;
	}
	else if (txt == "GREEN")
	{
		return CarBodyColor::GREEN;
	}

	throw AppException("no color for value" + txt);
}
inline std::string color_to_string(CarBodyColor color_type)
{
	return CarBodyColorValues[static_cast<int>(color_type)];
}


inline CarBodyType str_to_body_type(const std::string& txt)
{
	if (txt == "SEDAN")
	{
		return CarBodyType::SEDAN;
	}
	else if (txt == "HATCHBACK")
	{
		return CarBodyType::HATCHBACK;
	}
	else if (txt == "COMBI")
	{
		return CarBodyType::COMBI;
	}
	throw AppException("no body type for value" + txt);
	
}
inline std::string body_type_to_string(CarBodyType body_type)
{
	return CarBodyTypeValues[static_cast<int>(body_type)];
}

