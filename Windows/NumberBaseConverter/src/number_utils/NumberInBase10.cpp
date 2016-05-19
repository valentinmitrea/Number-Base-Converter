#include "number_utils/NumberInBase10.h"
#include "exceptions/InvalidNumberException.h"


NumberInBase10::NumberInBase10(std::string number) : allowedCharacters({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' })
{
	this->number = number;

	if (isValid(allowedCharacters) == false)
		throw InvalidNumberException();
}


std::string NumberInBase10::convertToBase10()
{
	return number;
}
