#include "number_utils/Number.h"
#include "exceptions/InvalidBaseException.h"
#include "exceptions/InvalidNumberException.h"

#include <iostream>
#include <limits>


#ifdef __linux__

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

char getch()
{
	struct termios oldattr, newattr;
	char ch;

	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	//set attributes of terminal to non-echo mode
	newattr.c_lflag &= ~ICANON;
	newattr.c_lflag &= ~ECHO;
	//wait with no timeout until at least one keystroke is available
	newattr.c_cc[VMIN] = 1;
	newattr.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	read(STDIN_FILENO, &ch, 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

	return ch;
}

#elif _WIN32

#include <windows.h>
#include <conio.h>

//undefine max macro in windows.h
#undef max

#else
#error Platform not supported!
#endif


void promptExit()
{
	std::cout << "To exit the application press 'x'." << std::endl;
	std::cout << "Press any other key for another number conversion." << std::endl;

#ifdef __linux__ 
	//wait for key pressed in Linux
	if (getch() == 'x')
		exit(0);
#elif _WIN32
	//wait for key pressed in Windows
	_getch();
	if (GetAsyncKeyState('X') & 0x8000)
		exit(0);
#else
#error Platform not supported!
#endif
}


void readAndConvertNumber()
{
	std::string numberValue;
	int currentBase, newBase;

	std::cout << "Number to convert: ";
	std::cin >> numberValue;


	//read the base of the number to convert
	std::cout << "        From base: ";
	std::cin >> currentBase;

	//test if numeric base value is correct
	if (std::cin.fail() || currentBase < 2 || currentBase > 36)
		throw InvalidBaseException();


	//read the base in which we want to convert the number
	std::cout << "          To base: ";
	std::cin >> newBase;

	//test if numeric base value is correct
	if (std::cin.fail() || newBase < 2 || newBase > 36)
		throw InvalidBaseException();


	//compute the conversion
	Number *number = Number::create(numberValue, currentBase);

	std::cout << std::endl << "           Result: " << number->convertTo(newBase) << std::endl << std::endl << std::endl;
	std::cout << "Convertion finished succesfully!" << std::endl << std::endl;

	//TODO -> solve memory leak when exception
	delete number;
}


int main()
{
	for (;;)
	{
#ifdef __linux__ 
		//clear the screen in Linux
		system("clear");
#elif _WIN32
		//clear the screen in Windows
		system("cls");
#else
#error Platform not supported!
#endif

		std::cout << "Welcome to Number Base Converter!" << std::endl << std::endl;
		std::cout << "Numerical bases supported range from 2 to 36." << std::endl << std::endl << std::endl;

		//perform a numerical conversion and catch the exceptions that can occur
		try
		{
			readAndConvertNumber();
		}
		catch (InvalidBaseException& e)
		{
			std::cout << std::endl << e.what() << std::endl << std::endl << std::endl;
			//reset failbit
			std::cin.clear();
			//skip bad input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (InvalidNumberException& e)
		{
			std::cout << std::endl << e.what() << std::endl << std::endl << std::endl;
		}

		//prompt user for exit or continue
		promptExit();
	}

	return 0;
}
