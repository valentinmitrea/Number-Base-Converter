#pragma once

#include <string>
#include <vector>


class Number
{

protected:
	std::string number;

	bool isValid(const std::vector<char> &allowedCharacters);
	int pow(int number, int power);

public:
	static Number* create(std::string number, int base);

	virtual std::string convertToBase10() = 0;
	virtual std::string convertTo(int newBase);

	void print();

};
