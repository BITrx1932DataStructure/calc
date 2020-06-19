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
		{
			try
			{
				std::cout << calculator.calculate(buf) << std::endl;
			}
			catch (fy::error::math_error)
			{
				std::cout << "math error" << std::endl;
			}
			catch (fy::error::syntax_error)
			{
				std::cout << "syntax error" << std::endl;
			}
			catch (...)
			{
				std::cout << "unknown error" << std::endl;
				std::cout << "the program will exit" << std::endl;
			}
		}
		if (std::cin.eof())
			break;
	}
}
