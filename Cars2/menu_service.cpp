
#include "menu_service.h"
#include "user_data_service.h"


int MenuService::choose_option()
{
	
	std::cout << "MENU" << std::endl;
	std::cout << "Choose option:" << std::endl;
	std::cout << "1 - show cars" << std::endl;
	std::cout << "2 - sorting" << std::endl;
	std::cout << "3 - find car body type in price range" << std::endl;
	std::cout << "4 - find car engine type" << std::endl;
	std::cout << "5 - show statistics " << std::endl;
	std::cout << "6 - show cars mileage" << std::endl;
	std::cout << "7 - find cars with special components" << std::endl;
	std::cout << "8 - cars tyre type" << std::endl;
	std::cout << "9 - exit" << std::endl;
	const int choice = UserDataService::get_int("");
	return choice;
}

void MenuService::option1() const
{
	std::cout << *cars_utils << std::endl;
	std::cin.get();
	system("cls");
}

void MenuService::option2() const
{
	const std::string sort_by = UserDataService::get_string("Enter sorting item: \n[model][body components][power][price][mileage][engine type][body color][body type][wheel type][wheel model][wheel size]");
	const std::string sort_met = UserDataService::get_string("Enter sorting method [ascending][descending]: ");
	auto sorted_cars = cars_utils->sort_by(sort_by, sort_met);
	for(const auto& c:sorted_cars)
	{
		std::cout << *c<<std::endl;
	}
	std::cin.get();
	system("cls");
}

void MenuService::option3() const
{
	const std::string text = UserDataService::get_string("Enter body type [HATCHBACK][SEDAN][COMBI]: ");
	const int from = UserDataService::get_int("Enter range from: ");
	const int to = UserDataService::get_int("to: ");
	auto body_car_from_price_range = cars_utils->cars_with_car_body_type(text, from, to);
	if (body_car_from_price_range.empty())
	{
		std::cout << "No cars.";
	}
	for (const auto& c : body_car_from_price_range)
	{
		std::cout << *c << std::endl;
	}
	std::cin.get();
	system("cls");
}

void MenuService::option4() const
{
	const std::string text = UserDataService::get_string("Enter engine type [LPG][DIESEL][GASOLINE]: ");
	auto engine_type = cars_utils->cars_with_engine_type(text);
	for (const auto& c : engine_type)
	{
		std::cout << *c << std::endl;
	}
	std::cin.get();
	system("cls");
}

void MenuService::option5() const
{
	const std::string text = UserDataService::get_string("Enter parameter [mileage][price][engine power]: ");
	cars_utils->statistics(text);
	std::cin.get();
	system("cls");
}

void MenuService::option6() const
{
	for(const auto& cars:cars_utils->cars_mileage())
	{
		std::cout << *cars.first << "Mileage: " << cars.second << std::endl;
	}
	std::cin.get();
	system("cls");
}

void MenuService::option7() const
{
	const auto components = UserDataService::get_vector("Enter components, write exit when u finish.");
	auto cars_with_components=cars_utils->cars_with_components(components);
	if(cars_with_components.empty())
	{
		std::cout << "No cars with this components"<<std::endl;
	}
	for (const auto& c : cars_with_components)
	{
		std::cout << *c << std::endl;
	}
	std::cin.get();
	system("cls");
}

void MenuService::option8() const
{
	for (const auto& i : cars_utils->cars_tyre_type())
	{
		std::cout << i.first << std::endl;
		for (const auto& j : i.second)
		{
			std::cout << *j;
		}
		std::cout << std::endl;
	}
	std::cin.get();
	system("cls");
}


MenuService::MenuService(const CarsUtils& cars_utils)
{
	this->cars_utils = std::make_unique<CarsUtils>(cars_utils);
}


void MenuService::main_menu() const
{
	try
	{
		while(true)
		{
			const int option = choose_option();
			switch (option)
			{
			case 1:
				option1();
				break;
			case 2:
				option2();
				break;
			case 3:
				option3();
				break;
			case 4:
				option4();
				break;
			case 5:
				option5();
				break;
			case 6:
				option6();
				break;
			case 7:
				option7();
				break;
			case 8:
				option8();
				break;
			case 9:
				std::cout << "Have a nice day!";
				std::cin.get();
				return;
			default:
				std::cout << "No option with number " << option << std::endl;
				std::cin.get();
				system("cls");
			}
		}
	} 
	catch(const AppException& exception)
	{
		std::cout << exception.error_message()<< std::endl;
		std::cin.get();
		system("cls");
		main_menu();
		
	}
}

