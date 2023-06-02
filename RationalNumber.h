#pragma once
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
class RationalNumbers
{
public:
	int numerator;
	int denominator;
	RationalNumbers(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			throw int ("zero division error");
		}
		this->numerator = numerator;
		this->denominator = denominator;
	}
	void Print()
	{
		std::cout << numerator << "/" << denominator << endl;
	}
	void reduction()
	{
		for (int i = 2; i < sqrt(max(denominator, numerator))+1;i++)
		{
			if ((denominator % i == 0)&&(numerator % i == 0))
			{
				denominator = denominator / i;
				numerator = numerator / i;
			}
		}
	}
	RationalNumbers& operator+(RationalNumbers summand)
	{
		int nok = 0;
		int maxDenominatorRemember = max(denominator, summand.denominator);
		int maxDenominator = max(denominator, summand.denominator);
		int minDenominator = min(denominator, summand.denominator);
		while (true) 
		{
			if (maxDenominator % minDenominator == 0)
			{
				nok = maxDenominator;
				break;
			}
			else
			{
				maxDenominator += maxDenominatorRemember;
			}
		}
		numerator = numerator * (nok / denominator);
		summand.numerator = summand.numerator * (nok / summand.denominator);
		numerator += summand.numerator;
		denominator = nok;
		RationalNumbers returnValue(numerator, denominator);
		returnValue.reduction();
		return returnValue;
	}
	RationalNumbers& operator*(RationalNumbers prod)
	{
		numerator *= prod.numerator;
		denominator *= prod.denominator;
		RationalNumbers returnValue(numerator, denominator);
		returnValue.reduction();
		return returnValue;
	}
	RationalNumbers& operator/(RationalNumbers prod) 
	{
		int reserv = prod.denominator;
		prod.denominator = prod.numerator;
		prod.numerator = reserv;
		numerator *= prod.numerator;
		denominator *= prod.denominator;
		RationalNumbers returnValue(numerator, denominator);
		returnValue.reduction();
		return returnValue;
	}
	RationalNumbers operator-(RationalNumbers summand)
	{
		int nok = 0;
		int maxDenominatorRemember = max(denominator, summand.denominator);
		int maxDenominator = max(denominator, summand.denominator);
		int minDenominator = min(denominator, summand.denominator);
		while (true)
		{
			if (maxDenominator % minDenominator == 0)
			{
				nok = maxDenominator;
				break;
			}
			else
			{
				maxDenominator += maxDenominatorRemember;
			}
		}
		numerator = numerator * (nok / denominator);
		summand.numerator = summand.numerator * (nok / summand.denominator);
		numerator -= summand.numerator;
		denominator = nok;
		RationalNumbers returnValue(numerator, denominator);
		returnValue.reduction();
		return returnValue;
	}
	bool operator!=(RationalNumbers summand)
	{
		RationalNumbers forDel(numerator, denominator);
		if ((forDel - summand).numerator == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator==(RationalNumbers summand)
	{
		RationalNumbers forDel(numerator, denominator);
		if ((forDel - summand).numerator == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(RationalNumbers summand)
	{
		RationalNumbers forDel(numerator, denominator);
		if ((forDel - summand).numerator> 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(RationalNumbers summand)
	{
		RationalNumbers forDel(numerator, denominator);
		if ((forDel - summand).numerator < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(RationalNumbers summand)
	{
		RationalNumbers forDel(numerator, denominator);
		if ((forDel - summand).numerator >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(RationalNumbers summand)
	{
		RationalNumbers forDel(numerator, denominator);
		if ((forDel - summand).numerator <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};