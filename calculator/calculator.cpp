#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<cmath>
#include<assert.h>
#include "calculator.h"

namespace fy
{
	Calculator::Calculator() :__root(0)
	{
	}

	Calculator::~Calculator()
	{
		clear();
	}

	double Calculator::calculate(string exp)
	{
		build_tree(__root, exp, 0, exp.size() - 1);
		if (__root == nullptr)
			throw(error::syntax_error());
		return __root->calc();
	}

	void Calculator::clear()
	{
	}

	void Calculator::build_tree(NODE*& root, string& exp, int l, int r)
	{
		if (l > r)
			throw(error::syntax_error());
		else
		{
			int flag = 0;//记录括号层级
			int pos[2] = { -1,-1 };//pos[0]表示最后一个加减号的位置，pos[1]为乘除
			for (int i = l; i <= r; i++)
			{
				if (exp[i] == '(')
					flag++;
				else if (exp[i] == ')')
					flag--;
				if (flag == 0)
				{
					if (exp[i] == '+' || exp[i] == '-')
						pos[0] = i;
					if (exp[i] == '*' || exp[i] == '/')
						pos[1] = i;
				}
			}
			if (flag != 0)//如果括号不匹配
				throw(error::syntax_error());

			if (pos[0] == -1 && pos[1] == -1)//没有运算符，那就一定是一个数或这最外面一层括号
			{
				if (exp[l] == '(' && exp[r] == ')')//如果最外面是一层括号
					build_tree(root, exp, l + 1, r - 1);
				else
				{
					root = new NODE;
					root->data = exp.substr(l, (size_t)r - l + 1);
				}
			}
			else//有运算符
			{
				int t_pos = -1;
				root = new NODE;
				if (pos[0] > -1)//有加减
					t_pos = pos[0];
				else if (pos[1] > -1)//没有加减，有乘除
					t_pos = pos[1];
				assert(t_pos != -1);
				root->data = exp[t_pos];
				build_tree(root->l_child, exp, l, t_pos - 1);
				build_tree(root->r_child, exp, t_pos + 1, r);
			}
		}
	}

	double add(double a, double b)
	{
		return a + b;
	}

	double subtract(double a, double b)
	{
		return a - b;
	}

	double multiply(double a, double b)
	{
		return a * b;
	}

	double divide(double a, double b)
	{
		if (b == 0)
			throw(error::math_error());
		return a / b;
	}

	double power(double a, double b)
	{
		if (a == 0 && b == 0)
			throw(error::math_error());
		return std::pow(a, b);
	}

	inline NODE::NODE() : l_child(0), r_child(0), fa(0)
	{
	}

	double NODE::calc()
	{
		if (data == "+")
			return add(l_child->calc(), r_child->calc());
		else if (data == "-")
			return subtract(l_child->calc(), r_child->calc());
		else if (data == "*")
			return multiply(l_child->calc(), r_child->calc());
		else if (data == "/")
			return divide(l_child->calc(), r_child->calc());
		else if (data == "^")
			return power(l_child->calc(), r_child->calc());
		else
			return to_double(data);
	}

	double to_double(string s)
	{
		double ret;
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '.')
				count++;
			else if (s[i] < '0' || s[i]>'9')
				throw(error::syntax_error());
		}
		if (count > 1 || s[0] == '.' || s[s.size() - 1] == '.')
			throw(error::syntax_error());

		sscanf(s.c_str(), "%lf", &ret);
		return ret;
	}

	namespace error
	{
		const char* syntax_error::what() const throw()
		{
			return "syntax_error";
		}
		const char* math_error::what() const throw()
		{
			return "math_error";
		}
	}
}
