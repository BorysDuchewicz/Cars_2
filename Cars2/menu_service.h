
#pragma once
#include "cars_utils.h"

//klasa pozwalajaca uzytkownikowi na wybor poszczegolnych opcji
class MenuService
{
private:

	std::unique_ptr<CarsUtils> cars_utils;

	static int choose_option();
	void option1() const;
	void option2()const;
	void option3() const;
	void option4() const;
	void option5() const;
	void option6() const;
	void option7() const;
	void option8() const;
public:
	MenuService(const CarsUtils& cars_utils);
	
	void main_menu() const;
	
	~MenuService()=default;
};
 

