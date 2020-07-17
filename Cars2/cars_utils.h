#pragma once
#include"car_utils.h"

//przechowuje liste samochodów i pozwala na operowaniu na nich 
class CarsUtils
{
private:
	std::vector<std::unique_ptr<Car>> cars;

	static std::vector<Car> from_unique_pointers_to_cars(const std::vector<std::unique_ptr<Car>>& cars_up);
	static std::vector<std::unique_ptr<Car>> from_cars_to_unique_pointers(const std::vector<Car>& cars);


public:
	CarsUtils()=default;
	
	CarsUtils(const std::string& file_name);
	CarsUtils(const CarsUtils& cars_utils);
	CarsUtils(CarsUtils&& cars_utils);
	
	std::vector <std::unique_ptr<Car>> sort_by(const std::string& sort_element, const std::string& sort_met) const;//zwraca posortowane samochody wedlug podanego parametru i w podany sposob
	std::vector <std::unique_ptr<Car>> cars_with_car_body_type(const std::string& car_body_type, const double& min_price, const double& max_price );//znajduje samochody o podanym typie z przedzialu cenowego
	std::vector <std::unique_ptr<Car>> cars_with_engine_type(const std::string& engine_type);//zwraca samochody o podanym silniku
	void statistics(const std::string& element);//zwraca podane statystyki o samochodach 
	std::map<std::unique_ptr<Car>, unsigned int> cars_mileage();//zwraca ile dany samochod przejechal mil
	std::map<std::string, std::vector<std::unique_ptr<Car>>> cars_tyre_type();//zwraca rodzaje opon (zimowe,letnie) i wszystkei samochody ktore owe posiadaja
	std::vector <std::unique_ptr<Car>> cars_with_components(std::vector<std::string>components);//zwraca wszystkei samochody ktore posiadaja podany kompomnent
	friend std::ostream& operator<<(std::ostream&, const CarsUtils& cars_utils);
};

