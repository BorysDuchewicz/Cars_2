
#pragma once
#include"car_body.h"
#include "wheel.h"
#include"engine.h"

//struktura przechowujaca informacje o calym samochodzie
struct Car
{
	std::string model;
	double price;
	unsigned int mileage;
	Engine engine;
	CarBody car_body;
	Wheel wheel;

	

	Car()=default;
	Car(const std::string& model, double price, unsigned int mileage, Engine engine, CarBody car_body, Wheel wheel)
		: model{ model }, price{ price }, mileage{ mileage }, engine{ engine }, car_body{ car_body }, wheel{ wheel } {}
		
};

inline std::ostream& operator<<(std::ostream& out, const Car& car)
{
	return out <<"Model: "<< car.model<< "\nPrice: "<<car.price<<"\nMileage: "<<car.mileage<<std::endl<<car.engine<<car.car_body<<car.wheel<<std::endl;
}


