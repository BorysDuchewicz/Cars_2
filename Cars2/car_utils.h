#pragma once
#include "car.h"


//klasa sluzaca to zczytania danych z pliku json
class CarUtils final
{

public:

	static std::vector<std::unique_ptr<Car>> read_cars_from_file(const std::string& file_name);

	CarUtils() = delete;
	~CarUtils() = delete;
};

