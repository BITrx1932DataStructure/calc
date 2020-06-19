#pragma once
#include<string>
#include<exception>

using std::string;

namespace fy
{
	double add(double a, double b);
	double subtract(double a, double b);
	double multiply(double a, double b);
	double divide(double a, double b);
	double power(double a, double b);

	class NODE
	{
	public:
		NODE();
		NODE(const NODE&) = delete;
		NODE(const NODE&&) = delete;

		double calc();
	public:
		string data;
		NODE* l_child, * r_child, * fa;

	};

	class Calculator
	{
	public:

		Calculator();
		Calculator(const Calculator&) = delete;
		Calculator(const Calculator&&) = delete;
		~Calculator();

		double calculate(string exp);
		void clear();

	private:
		void clear(NODE* p);
		void build_tree(NODE*& root, string& exp, int l, int r);
		NODE* __root;
	};

	namespace error
	{
		class syntax_error :public std::exception
		{
			const char* what() const throw ();
		};

		class math_error :public std::exception
		{
			const char* what() const throw ();
		};
	}

	double to_double(string s);
}