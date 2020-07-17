#include "car_utils.h"
#include "car_validator.h"



std::vector<std::unique_ptr<Car>> CarUtils::read_cars_from_file(const std::string& file_name)
{
	std::vector<std::unique_ptr<Car>> car_utils;
	CarValidator validator{};
	std::ifstream reader;
	reader.open(file_name + ".json");

	if (reader.is_open())
	{
		json j;
		reader >> j;
		
		for (const auto& cars : j)
		{
			Car car;
		
				car.model = cars["model"].get<std::string>();
				car.price = cars["price"].get<unsigned long>();
				car.mileage = cars["mileage"].get<unsigned int>();

				std::string engine_type_str_from_json = cars["engine"]["type"].get<std::string>();
				car.engine.type = str_to_engine_type(engine_type_str_from_json);
				car.engine.power = cars["engine"]["power"].get<unsigned long>();

				std::string color_str_from_json = cars["carBody"]["color"].get<std::string>();
				car.car_body.color = str_to_body_color(color_str_from_json);
				std::string body_type_str_from_json = cars["carBody"]["type"].get<std::string>();
				car.car_body.type = str_to_body_type(body_type_str_from_json);
				auto components_from_json = cars["carBody"]["components"].get<std::vector<std::string>>();
				for (const auto& component : components_from_json)
				{
					car.car_body.components.emplace_back(component);
				}

				std::string tyre_type_str_from_json = cars["wheel"]["type"].get<std::string>();
				car.wheel.type = str_to_tyre_type(tyre_type_str_from_json);
				car.wheel.model = cars["wheel"]["model"].get<std::string>();
				car.wheel.size = cars["wheel"]["size"].get<unsigned int>();
				if (validator.validator(car).empty())
					car_utils.emplace_back(std::make_unique<Car>(car));
				else
					std::cout << validator;				
		}
		reader.close();
	}
	else
	{
		std::cout << "Reader error" << std::endl;
	}

	return car_utils;
}
