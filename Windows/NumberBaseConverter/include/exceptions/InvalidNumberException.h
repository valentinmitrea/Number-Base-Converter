#pragma once

#include <exception>
#include <string>


class InvalidNumberException : public std::exception
{

	std::string information;


public:
	InvalidNumberException();

	virtual const char* what() const throw();

};
