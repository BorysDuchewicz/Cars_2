
#pragma once

#include "lib.h"


//klasa pobierajaca dane od uzytkownika
class UserDataService final
{
public:
	UserDataService() = delete;

	static int get_int(const std::string& message);
	static std::string get_string(const std::string& message);
	static std::vector<std::string> get_vector(const std::string& message);
	static CarBodyColor get_car_body_color(const std::string& message);
	static TyreType get_tyre_type(const std::string& message);
	static EngineType get_engine_type(const std::string& message);
	static CarBodyType get_car_body_type(const std::string& message);
	~UserDataService() = delete;
};


