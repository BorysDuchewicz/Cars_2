#include "car_validator.h"
#include "wheel_validator.h"
#include "car_body_validator.h"


bool CarValidator::is_model_valid(const Car& car)
{
	return std::regex_match(car.model,std::regex("[A-Z ]+"));
}

bool CarValidator::is_price_valid(const Car& car)
{
	return car.price >= 0;
}

bool CarValidator::is_mileage_valid(const Car& car)
{
	return car.mileage>=0;
}

std::unordered_map<std::string, std::string> CarValidator::validator(const Car& car)
{
	errors.clear();
	if (!is_model_valid(car))
	{
		errors.insert(std::make_pair("model", "is not valid: " + car.model));
	}
	if (!is_price_valid(car))
	{
		errors.insert(std::make_pair("price", "is not valid: " + std::to_string(car.price)));
	}
	if (!is_price_valid(car))
	{
		errors.insert(std::make_pair("mileage", "is not valid: " + std::to_string(car.mileage)));
	}

	EngineValidator engine_validator{};
	auto engine_validator_errors = engine_validator.validator(car.engine);
	errors.insert(engine_validator_errors.begin(), engine_validator_errors.end());

	WheelValidator wheel_validator{};
	auto wheel_validator_errors = wheel_validator.validator(car.wheel);
	errors.insert(wheel_validator_errors.begin(), wheel_validator_errors.end());

	CarBodyValidator car_body_validator{};
	auto car_body_errors = car_body_validator.validator(car.car_body);
	errors.insert(car_body_errors.begin(), car_body_errors.end());


	return errors;
}

std::ostream& operator<<(std::ostream& out, const CarValidator& val)
{
	for(const auto& car:val.errors)
	{
		out << car.first << " " << car.second << std::endl;
	}
	return out;
}
