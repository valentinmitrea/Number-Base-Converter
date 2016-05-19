#pragma once

#include "Number.h"


class NumberInBase2 : public Number
{

	std::vector<char> allowedCharacters;


public:
	NumberInBase2(std::string number);

	virtual std::string convertToBase10();

};
