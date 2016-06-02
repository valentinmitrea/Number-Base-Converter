#include "number_utils/NumberInBase2.h"
#include "exceptions/InvalidNumberException.h"

#include <sstream>


NumberInBase2::NumberInBase2(std::string number) : allowedCharacters({ '0', '1' })
{
	this->number = number;

	if (isValid(allowedCharacters) == false)
		throw InvalidNumberException();
}


std::string NumberInBase2::convertToBase10()
{
	int result = 0, numberValue, value;

	std::stringstream stream(number);
	stream >> numberValue;

	for (unsigned int i = 0; i < number.size(); i++)
	{
		result += (numberValue % 10) * pow(2, i);
		numberValue /= 10;
	}

	return std::to_string(result);
}
