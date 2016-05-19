#include "exceptions/InvalidBaseException.h"


InvalidBaseException::InvalidBaseException()
{
	this->information = "Invalid base value! You must introduce a numerical value between 2 and 36.";
}


const char* InvalidBaseException::what() const throw()
{
	return information.c_str();
}
