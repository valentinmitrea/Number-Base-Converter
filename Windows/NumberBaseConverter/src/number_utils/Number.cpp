#include "number_utils/Number.h"
#include "number_utils/NumberInBase2.h"
#include "number_utils/NumberInBase10.h"

#include <iostream>
#include <sstream>


bool Number::isValid(const std::vector<char> &allowedCharacters)
{
	bool found;

	for (unsigned int i = 0; i < number.size(); i ++)
	{
		found = false;

		//check if current character in the number is one of the allowed characters for this number
		for (unsigned int j = 0; j < allowedCharacters.size(); j ++)
			if (number[i] == allowedCharacters[j])
			{
				found = true;
				break;
			}

		//if the current character in the number is not an allowed character
		if (!found)
			return false;
	}

	return true;
}


int Number::pow(int number, int power)
{
	if (power == 0)
		return 1;

	int temp = pow(number, power / 2);

	if (power % 2 == 0)
		return temp * temp;
	else
		return number * temp * temp;
}


Number* Number::create(std::string number, int base)
{
	switch (base)
	{
		case 2:
			return new NumberInBase2(number);

		case 10:
			return new NumberInBase10(number);
	}

	return nullptr;
}


std::string Number::convertTo(int newBase)
{
	int index = 1, result = 0, numberValue;
	std::string temp = convertToBase10();

	std::stringstream stream(temp);
	stream >> numberValue;

	switch (newBase)
	{
		case 2:
			while (numberValue != 0)
			{
				result += numberValue % 2 * index;

				index *= 10;
				numberValue /= 2;
			}

			return std::to_string(result);

		case 10:
			return temp;
	}

	return nullptr;
}


void Number::print()
{
	for (unsigned int i = 0; i < number.size(); i++)
		std::cout << number[i];
	std::cout << std::endl;
}
