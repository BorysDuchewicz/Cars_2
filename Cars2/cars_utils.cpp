#include "cars_utils.h"

std::vector<Car> CarsUtils::from_unique_pointers_to_cars(const std::vector<std::unique_ptr<Car>>& cars_up)
{
	std::vector<Car> cars(cars_up.size());
	std::transform(cars_up.begin(), cars_up.end(), cars.begin(), [](const auto& car_up) { return *car_up; });
	return cars;
}

std::vector<std::unique_ptr<Car>> CarsUtils::from_cars_to_unique_pointers(const std::vector<Car>& cars)
{
	std::vector<std::unique_ptr<Car>> cars_up(cars.size());
	std::transform(cars.begin(), cars.end(), cars_up.begin(),
	               [](const auto& car) { return std::make_unique<Car>(car); });
	return cars_up;
}

CarsUtils::CarsUtils(const std::string& file_name)
{	
	this->cars = CarUtils::read_cars_from_file(file_name);
}

CarsUtils::CarsUtils(const CarsUtils& cars_utils)
{
	for (auto& c : cars_utils.cars)
	{
		this->cars.emplace_back(std::make_unique<Car>(*c));
	}
}

CarsUtils::CarsUtils(CarsUtils&& cars_utils)
{
	this->cars = std::move(cars_utils.cars);
}


std::vector <std::unique_ptr<Car>> CarsUtils::sort_by(const std::string& sort_element, const std::string& sort_met) const
{
	auto cars = from_unique_pointers_to_cars(this->cars);
	std::vector<Car> desc_cars(cars.size());
	bool ok = false;

	std::unordered_map<std::string, std::function<bool(Car, Car)>> comparators;
	comparators.emplace(std::make_pair("model", [](const Car& c1, const Car& c2) {return c1.model < c2.model; }));
	comparators.emplace(std::make_pair("body components", [](const Car& c1, const Car& c2) {return c1.car_body.components.size() < c2.car_body.components.size(); }));
	comparators.emplace(std::make_pair("engine power", [](const Car& c1, const Car& c2) {return c1.engine.power < c2.engine.power; }));
	comparators.emplace(std::make_pair("price", [](const Car& c1, const Car& c2) {return c1.price < c2.price; }));
	comparators.emplace(std::make_pair("mileage", [](const Car& c1, const Car& c2) {return c1.mileage < c2.mileage; }));
	comparators.emplace(std::make_pair("engine type", [](const Car& c1, const Car& c2) {return c1.engine.type < c2.engine.type; }));
	comparators.emplace(std::make_pair("body color", [](const Car& c1, const Car& c2) {return c1.car_body.color < c2.car_body.color; }));
	comparators.emplace(std::make_pair("wheel type", [](const Car& c1, const Car& c2) {return c1.wheel.type < c2.wheel.type; }));
	comparators.emplace(std::make_pair("wheel model", [](const Car& c1, const Car& c2) {return c1.wheel.model < c2.wheel.model; }));
	comparators.emplace(std::make_pair("wheel size", [](const Car& c1, const Car& c2) {return c1.wheel.size < c2.wheel.size; }));
	comparators.emplace(std::make_pair("body type", [](const Car& c1, const Car& c2) {return c1.car_body.type < c2.car_body.type; }));

	for(const auto& c:comparators)
	{
		if(c.first==sort_element)		
			ok = true;		
	}

	if (ok)
	{
		std::sort(cars.begin(), cars.end(), comparators[sort_element]);
		if (sort_met == "descending")
		{
			std::reverse_copy(cars.begin(), cars.end(), desc_cars.begin());
			return from_cars_to_unique_pointers(desc_cars);
		}
		else if (sort_met == "ascending")
			return from_cars_to_unique_pointers(cars);
		else
			throw AppException("Wrong parameter");
	}
	else
		throw AppException("Wrong element");
}

std::vector<std::unique_ptr<Car>> CarsUtils::cars_with_car_body_type(const std::string& car_body_type,
	const double& min_price, const double& max_price)
{
	std::vector <std::unique_ptr<Car>> new_cars;

	for (int i = 0; i < cars.size(); ++i)
	{
		new_cars.emplace_back(std::make_unique<Car>(Car{}));
		
			new_cars[i]->model = cars[i]->model;
			new_cars[i]->price = cars[i]->price;
			new_cars[i]->mileage = cars[i]->mileage;
			new_cars[i]->engine.type = cars[i]->engine.type;
			new_cars[i]->engine.power = cars[i]->engine.power;
			new_cars[i]->car_body.type = cars[i]->car_body.type;
			new_cars[i]->car_body.color = cars[i]->car_body.color;
			for (const auto& cc : cars[i]->car_body.components)
				new_cars[i]->car_body.components.emplace_back(cc);
			new_cars[i]->wheel.type = cars[i]->wheel.type;
			new_cars[i]->wheel.model = cars[i]->wheel.model;
			new_cars[i]->wheel.size = cars[i]->wheel.size;		
	}

	for(int i=0;i<new_cars.size();)
	{
		if(!(body_type_to_string(new_cars[i]->car_body.type) == car_body_type) || new_cars[i]->price < min_price || new_cars[i]->price > max_price)
		{	
			new_cars.erase(new_cars.begin() + i);
		}
		else
		{
			++i;
		}
	}

	return new_cars;
}

std::vector<std::unique_ptr<Car>> CarsUtils::cars_with_engine_type(const std::string& engine_type)
{
	std::vector <std::unique_ptr<Car>> new_cars;

	for (int i = 0; i < cars.size(); ++i)
	{
		new_cars.emplace_back(std::make_unique<Car>(Car{}));
		
			new_cars[i]->model = cars[i]->model;
			new_cars[i]->price = cars[i]->price;
			new_cars[i]->mileage = cars[i]->mileage;
			new_cars[i]->engine.type = cars[i]->engine.type;
			new_cars[i]->engine.power = cars[i]->engine.power;
			new_cars[i]->car_body.type = cars[i]->car_body.type;
			new_cars[i]->car_body.color = cars[i]->car_body.color;
			for (const auto& cc : cars[i]->car_body.components)
				new_cars[i]->car_body.components.emplace_back(cc);
			new_cars[i]->wheel.type = cars[i]->wheel.type;
			new_cars[i]->wheel.model = cars[i]->wheel.model;
			new_cars[i]->wheel.size = cars[i]->wheel.size;
	
	}
	
	for(int i =0;i<new_cars.size();)
	{
		
		if(!(engine_type_to_string(new_cars[i]->engine.type)==(engine_type)))
		{		
			new_cars.erase(new_cars.begin()+i);
		}
		else
		{
			i++;
		}
		
	}
	std::sort(new_cars.begin(), new_cars.end());
	return new_cars;

}

void CarsUtils::statistics(const std::string& element)
{
	
	if (element == "price")
	{
		double price_sum = 0;
		for(const auto& i:cars)
		{
			price_sum += i->price;
		}
		const auto min_max = std::minmax_element(cars.begin(), cars.end(), [](const std::unique_ptr<Car>& car1, const std::unique_ptr<Car>& car2) {return car1->price < car2->price; });
		std::cout << "Min " << element << " " << (*min_max.first)->model<<" "<< (*min_max.first)->price<<std::endl;
		std::cout << "Max " << element << " " << (*min_max.second)->model<<" "<< (*min_max.second)->price <<std::endl;
		std::cout << "Average: " << price_sum / cars.size()<<std::endl;
	}
	else if(element=="mileage")
	{
		double mileage_sum = 0;
		for (const auto& i : cars)
		{
			mileage_sum += i->mileage;
		}
		const auto min_max = std::minmax_element(cars.begin(), cars.end(), [](const std::unique_ptr<Car>& car1, const std::unique_ptr<Car>& car2) {return car1->mileage < car2->mileage; });
		std::cout << "Min " << element << " " << (*min_max.first)->model << " " << (*min_max.first)->mileage << std::endl;
		std::cout << "Max " << element << " " << (*min_max.second)->model << " " << (*min_max.second)->mileage << std::endl;
		std::cout << "Average: " << mileage_sum / cars.size()<<std::endl;
	}
	else if(element=="engine power")
	{
		double engine_power_sum = 0;
		for (const auto& i : cars)
		{
			engine_power_sum += i->engine.power;
		}
		const auto min_max = std::minmax_element(cars.begin(), cars.end(), [](const std::unique_ptr<Car>& car1, const std::unique_ptr<Car>& car2) {return car1->engine.power < car2->engine.power; });
		std::cout << "Min " << element << " " << (*min_max.first)->model << " " << (*min_max.first)->engine.power << std::endl;
		std::cout << "Max " << element << " " << (*min_max.second)->model << " " << (*min_max.second)->engine.power << std::endl;
		std::cout << "Average: " << engine_power_sum / cars.size()<<std::endl;
	}
	else
	{
		std::cout << " wrong element"<<std::endl;
	}
}

std::map<std::unique_ptr<Car>, unsigned int> CarsUtils::cars_mileage()
{	
	std::map<std::unique_ptr<Car>, unsigned int> cars_mileage;
	
	for(const auto& i:cars)
	{
		cars_mileage.emplace(std::make_pair(std::make_unique<Car>(*i), i->mileage));
	}
	return cars_mileage;
}

std::map<std::string, std::vector<std::unique_ptr<Car>>> CarsUtils::cars_tyre_type()
{
	std::map<std::string, std::vector<std::unique_ptr<Car>>> cars_tyre_type;
	std::vector<std::unique_ptr<Car>> winter_wheels;
	std::vector<std::unique_ptr<Car>>  summer_wheels;
	int j=0;
	int k=0;
	for (int i = 0; i < cars.size(); ++i)
	{
		if (tyre_type_to_string(cars[i]->wheel.type) == "WINTER")
		{
			winter_wheels.emplace_back(std::make_unique<Car>(Car{}));
			winter_wheels[j]->model = cars[i]->model;
			winter_wheels[j]->price = cars[i]->price;
			winter_wheels[j]->mileage = cars[i]->mileage;
			winter_wheels[j]->engine.type = cars[i]->engine.type;
			winter_wheels[j]->engine.power = cars[i]->engine.power;
			winter_wheels[j]->car_body.type = cars[i]->car_body.type;
			winter_wheels[j]->car_body.color = cars[i]->car_body.color;
			for (const auto& cc : cars[i]->car_body.components)
				winter_wheels[j]->car_body.components.emplace_back(cc);
			winter_wheels[j]->wheel.type = cars[i]->wheel.type;
			winter_wheels[j]->wheel.model = cars[i]->wheel.model;
			winter_wheels[j]->wheel.size = cars[i]->wheel.size;
			j++;
		}
		else if (tyre_type_to_string(cars[i]->wheel.type) == "SUMMER")
		{
			summer_wheels.emplace_back(std::make_unique<Car>(Car{}));
			summer_wheels[k]->model = cars[i]->model;
			summer_wheels[k]->price = cars[i]->price;
			summer_wheels[k]->mileage = cars[i]->mileage;
			summer_wheels[k]->engine.type = cars[i]->engine.type;
			summer_wheels[k]->engine.power = cars[i]->engine.power;
			summer_wheels[k]->car_body.type = cars[i]->car_body.type;
			summer_wheels[k]->car_body.color = cars[i]->car_body.color;
			for (const auto& cc : cars[i]->car_body.components)
				summer_wheels[k]->car_body.components.emplace_back(cc);
			summer_wheels[k]->wheel.type = cars[i]->wheel.type;
			summer_wheels[k]->wheel.model = cars[i]->wheel.model;
			summer_wheels[k]->wheel.size = cars[i]->wheel.size;
			
			k++;
		}
	}
	
	cars_tyre_type.emplace(std::make_pair("SUMMER:", std::move(summer_wheels)));
	cars_tyre_type.emplace(std::make_pair("WINTER:",std::move(winter_wheels)));
	return cars_tyre_type;
}

std::vector<std::unique_ptr<Car>> CarsUtils::cars_with_components(std::vector<std::string> components)
{
	std::vector <std::unique_ptr<Car>> new_cars;

	for (int i = 0; i < cars.size(); ++i)
	{
		new_cars.emplace_back(std::make_unique<Car>(Car{}));

		new_cars[i]->model = cars[i]->model;
		new_cars[i]->price = cars[i]->price;
		new_cars[i]->mileage = cars[i]->mileage;
		new_cars[i]->engine.type = cars[i]->engine.type;
		new_cars[i]->engine.power = cars[i]->engine.power;
		new_cars[i]->car_body.type = cars[i]->car_body.type;
		new_cars[i]->car_body.color = cars[i]->car_body.color;
		for (const auto& cc : cars[i]->car_body.components)
			new_cars[i]->car_body.components.emplace_back(cc);
		new_cars[i]->wheel.type = cars[i]->wheel.type;
		new_cars[i]->wheel.model = cars[i]->wheel.model;
		new_cars[i]->wheel.size = cars[i]->wheel.size;

	}
	
	
	for(int i=0;i<new_cars.size();)
	{

		if(components.size()==new_cars[i]->car_body.components.size())
		{
			
			std::sort(components.begin(), components.end());
			
			std::sort(new_cars[i]->car_body.components.begin(), new_cars[i]->car_body.components.end());
		
			
			for(int j=0;j<new_cars[i]->car_body.components.size() ;++j)
			{
				if(components[j]!=new_cars[i]->car_body.components[j])
				{
					new_cars.erase(new_cars.begin() + i);
					break;
				}
				else if(j==components.size()-1)
				{
					
					++i;
				}
			}
		}
		else
		{
			new_cars.erase(new_cars.begin() + i);
		}
	}
	return new_cars;
}

std::ostream& operator<<(std::ostream& out, const CarsUtils& cars_utils)
{
	for(const auto& car:cars_utils.cars)
	{
		out << *car << std::endl;
	}
	return out;
}
