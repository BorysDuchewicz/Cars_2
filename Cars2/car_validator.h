#pragma once


#include "engine_validator.h"
#include "car.h"

class CarValidator: public Validator<Car>
{

private:
	static bool is_model_valid(const Car& car);
	static bool is_price_valid(const Car& car);
	static bool is_mileage_valid(const Car& car);
public:
	 std::unordered_map<std::string, std::string> validator(const Car& car) override;
	 friend std::ostream& operator<<(std::ostream& out, const CarValidator& val);
	CarValidator() = default;
	~CarValidator() = default;
};

