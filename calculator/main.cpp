#include<iostream>
#include<string>
#include"calculator.h"

int main()
{
	fy::Calculator calculator;
	std::string buf;
	while (1)
	{
		std::cout << ">>";
		std::getline(std::cin, buf);
		if (!buf.empty())
			std::cout << calculator.calculate(buf) << std::endl;
		else if (std::cin.eof())
			break;
	}
}
