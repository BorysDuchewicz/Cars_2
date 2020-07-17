#pragma once
#include "validator.h"
#include "car_body.h"

class CarBodyValidator:public Validator<CarBody>
{
private:
	static bool is_components_validate(const std::string& comp);
	static bool is_color_value(const std::string& value);
	static bool is_body_type_value(const std::string& value);
public:
	std::unordered_map<std::string, std::string> validator(const CarBody& car_body) override;
	CarBodyValidator()=default;
	~CarBodyValidator()=default;
};

