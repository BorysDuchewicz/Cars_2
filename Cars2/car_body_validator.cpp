#include "car_body_validator.h"


bool CarBodyValidator::is_components_validate(const std::string& comp)
{
	return std::regex_match(comp, std::regex("[A-Z ]+"));
}

bool CarBodyValidator::is_color_value(const std::string& value)
{
	return std::find(CarBodyColorValues.begin(), CarBodyColorValues.end(), value) != CarBodyColorValues.end();
}

bool CarBodyValidator::is_body_type_value(const std::string& value)
{
	return std::find(CarBodyTypeValues.begin(), CarBodyTypeValues.end(), value) != CarBodyTypeValues.end();
}


std::unordered_map<std::string, std::string> CarBodyValidator::validator(const CarBody& car_body)
{
	for(int i=0;i<car_body.components.size();++i)
	{
		if(!is_components_validate(car_body.components[i]))
		{
			errors.insert(std::make_pair("component " + car_body.components[i], " is valid"));
		}
	}
	if(!is_color_value(color_to_string(car_body.color)))
	{
		errors.insert(std::make_pair("color", "is not valid" + color_to_string(car_body.color)));
	}
	if(!is_body_type_value(body_type_to_string(car_body.type)))
	{
		errors.insert(std::make_pair("type", "is not valid" + body_type_to_string(car_body.type)));
	}

	return errors;
}
