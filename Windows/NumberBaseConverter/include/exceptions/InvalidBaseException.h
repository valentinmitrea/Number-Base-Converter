#pragma once

#include <exception>
#include <string>


class InvalidBaseException : public std::exception
{

	std::string information;


public:
	InvalidBaseException();

	virtual const char* what() const throw();

};
