#pragma once

#include <exception>
#include <string>


class InvalidNumberException : public std::exception
{

	std::string information;


public:
	InvalidNumberException();
	~InvalidNumberException() throw();

	virtual const char* what() const throw();

};
