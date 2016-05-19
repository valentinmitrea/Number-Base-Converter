#pragma once

#include "Number.h"


class NumberInBase10 : public Number
{

	std::vector<char> allowedCharacters;


public:
	NumberInBase10(std::string number);

	virtual std::string convertToBase10();

};
