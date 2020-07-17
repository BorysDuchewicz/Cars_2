#pragma once

#include <string>
#include <exception>

//klasa obslugujaca wyjatki
class AppException: public std::exception
{
private:
	std::string message;
public:
	AppException(const std::string& message);

	std::string error_message() const;
};

