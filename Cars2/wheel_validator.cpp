#include "wheel_validator.h"


bool WheelValidator::is_model_valid(const Wheel& wheel)
{
	return std::regex_match(wheel.model,std::regex("[A-Z ]+"));
}

bool WheelValidator::is_size_valid(const Wheel& wheel)
{
	return wheel.size >= 0;
}

bool WheelValidator::is_tyre_type_value(const std::string& value)
{
	return std::find(TyreTypeValues.begin(), TyreTypeValues.end(), value) != TyreTypeValues.end();
}

std::unordered_map<std::string, std::string> WheelValidator::validator(const Wheel& wheel)
{
	if(!is_model_valid(wheel))
	{
		errors.insert(std::make_pair("model", "is not valid" + wheel.model));
	}
	if(!is_size_valid(wheel))
	{
		errors.insert(std::make_pair("size", "is not valid" + std::to_string(wheel.size)));
	}
	if(!is_tyre_type_value(tyre_type_to_string(wheel.type)))
	{
		errors.insert(std::make_pair("tyre type", "is not valid" + tyre_type_to_string(wheel.type)));
	}
	return errors;
}
