
#include "menu_service.h"
#include "user_data_service.h"


int main()
{

	try {
		const std::string FILENAME = "cars";
		//const std::string FILENAME = UserDataService::get_string("Enter file name");
		CarsUtils cars_utils{ FILENAME };
		MenuService menu_service{ cars_utils };
		menu_service.main_menu();
	} catch (const AppException& e)
	{
		std::cout << e.error_message();
	}

	return 0;
}
