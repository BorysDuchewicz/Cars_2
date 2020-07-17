#include "user_data_service.h"


int UserDataService::get_int(const std::string& message)
{
	std::cout << message << std::endl;
	std::string text;
	std::getline(std::cin, text);

	if (!std::regex_match(text, std::regex("\\d+")))
	{
		throw AppException("incorrect int value");
	}

	return std::stoi(text);
}

std::string UserDataService::get_string(const std::string& message)
{
	std::cout << message << std::endl;
	std::string text;
	std::getline(std::cin, text);

	return text;
}

std::vector<std::string> UserDataService::get_vector(const std::string& message)
{
	std::cout << message << std::endl;
	std::string component;
	std::vector<std::string> components;
	while (true)
	{
		std::getline(std::cin, component);
		if (component == "exit")
		{
			return components;
		}
		components.emplace_back(component);
	}
}

CarBodyColor UserDataService::get_car_body_color(const std::string& message)
{
	std::cout << message << std::endl;
	std::string txt;
	std::getline(std::cin, txt);
	return str_to_body_color(txt);
	
}

EngineType UserDataService::get_engine_type(const std::string& message)
{
	std::cout << message << std::endl;
	std::string txt;
	std::getline(std::cin, txt);
	return str_to_engine_type(txt);

}

CarBodyType UserDataService::get_car_body_type(const std::string& message)
{
	std::cout << message << std::endl;
	std::string txt;
	std::getline(std::cin, txt);
	return str_to_body_type(txt);

}

TyreType UserDataService::get_tyre_type(const std::string& message)
{
	std::cout << message << std::endl;
	std::string txt;
	std::getline(std::cin, txt);
	return str_to_tyre_type(txt);

}


