#include "exceptions/InvalidNumberException.h"


InvalidNumberException::InvalidNumberException()
{
	this->information = "The introduced number has an invalid value!";
}


const char* InvalidNumberException::what() const throw()
{
	return information.c_str();
}
