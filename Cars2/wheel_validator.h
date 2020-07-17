#pragma once
#include "validator.h"
#include "wheel.h"

class WheelValidator : public Validator<Wheel>
{
private:
	static bool is_model_valid(const Wheel& wheel);
	static bool is_size_valid(const Wheel& wheel);
	static bool is_tyre_type_value(const std::string& value);

public:
	std::unordered_map<std::string, std::string> validator(const Wheel& wheel) override;
	WheelValidator()=default;
	~WheelValidator()=default;
};

