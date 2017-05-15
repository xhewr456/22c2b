
#ifndef CURRENCY_H
#define CURRENCY_H
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

class Currency
{
private:
	string currencyName;
	string fractionalName;
	int wholeValue = 0;
	int fractionalValue = 0;
public:
	// constructor
	Currency()
	{
		currencyName = "whole";
		fractionalName = "partial";
		int wholeValue = 0;
		int fractionalValue = 0;
	}

	Currency(string wholeValueName, string partialValueName)
	{
		currencyName = wholeValueName;
		fractionalName = partialValueName;
	}
	//Currency();
	//Currency()
	//{
	//setName("wholeBlank", "partialBlank");
	//setWholeValue(0);
	//setFractionalValue(0);
	//}


	Currency(string, string, int, int);
	Currency(Currency &right)
	{
		currencyName = right.getWholeName();
		fractionalName = right.getFractionalName();
		wholeValue = right.getWholeValue();
		fractionalValue = right.getFractionalValue();
	}
	// virtual destructor
	virtual ~Currency();


	void setName(string wholeName, string partialName);
	void setWholeValue(int wv)
	{
		wholeValue = wv;
	}
	void setFractionalValue(int fv)
	{
		fractionalValue = fv;
	}

	string getWholeName()
	{
		return currencyName;
	}
	string getFractionalName()
	{
		return fractionalName;
	}
	int getWholeValue()
	{
		return wholeValue;
	}
	int getFractionalValue()
	{
		return fractionalValue;
	}

	void setFundsToZero();
	double getCurrentFundsValue();
	void balanceFraction();


	//This function takes a single value, i.e. "11.99" and adds to its appropriate collection.
	friend void operator + (Currency &refCurrencyObject, double number)
	{
		refCurrencyObject.wholeValue += static_cast<int>(number);
		double x = number * 100;
		int y = (static_cast<int>(x) % 100);
		refCurrencyObject.fractionalValue += y;
		refCurrencyObject.balanceFraction();
	}

	//This function takes a single value, i.e. "11.99" and takes away from it's appropriate collection.
	friend void operator - (Currency &refCurrencyObject, double number)
	{
		refCurrencyObject.wholeValue -= static_cast<int>(number);
		double x = number * 100;
		int y = (static_cast<int>(x) % 100);
		refCurrencyObject.fractionalValue -= y;
		refCurrencyObject.balanceFraction();
	}

	// output stream overloading
	friend ostream& operator << (ostream &outputStream, Currency &refCurrencyObject)
	{
		cout << setprecision(2) << fixed;
		cout << refCurrencyObject.currencyName << ": " << refCurrencyObject.getCurrentFundsValue();
		return outputStream;
	}
	// less-than overloading
	bool operator < (Currency &right)
	{
		if (getCurrentFundsValue() < right.getCurrentFundsValue())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void operator= (Currency &right)
	{
		currencyName = right.getWholeName();
		fractionalName = right.getFractionalName();
		wholeValue = right.getWholeValue();
		fractionalValue = right.getFractionalValue();
	}
	bool operator== (Currency &right)
	{
		if (
			(currencyName == right.getWholeName()) &&
			(fractionalName == right.getFractionalName()) &&
			(wholeValue == right.getWholeValue()) &&
			(fractionalValue == right.getFractionalValue())
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!= (Currency &right)
	{
		if (
			(currencyName == right.getWholeName()) &&
			(fractionalName == right.getFractionalName()) &&
			(wholeValue == right.getWholeValue()) &&
			(fractionalValue == right.getFractionalValue())
			)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// make wallet class a friend
	friend class Wallet;
};

/*
Currency::Currency()
{
setName("wholeBlank", "partialBlank");
setWholeValue(0);
setFractionalValue(0);
}
*/

//Currency::Currency(string wholeName = "whole", string partialName = "partial", int wv = 0, int fv = 0)
Currency::Currency(string wholeName, string partialName, int wv, int fv)
{
	setName(wholeName, partialName);
	setWholeValue(wv);
	setFractionalValue(fv);
}

// virtual destructor
Currency::~Currency()
{
	//cout << "currency class Deconstructor\n";
}

void Currency::setName(string wholeName, string partialName)
{
	currencyName = wholeName;
	fractionalName = partialName;
}

void Currency::setFundsToZero()
{
	wholeValue = 0;
	fractionalValue = 0;
}


// converts the two seperate member varibles into a single double and returns that value
double Currency::getCurrentFundsValue()
{
	return (wholeValue + (fractionalValue / 100.0));
}

// reuduce fractional values
// Checks the values store in whole and fractional, and if both are less than zero, set both values to zero
// This is added to keep preven a situation of having negative funds, because the lab doesn't say to filter out 
// the chance that funds would go into negative numbers, and it stops the program from crashing
void Currency::balanceFraction()
{
	if (fractionalValue >= 100)
	{
		wholeValue += static_cast<int>(fractionalValue / 100);
		fractionalValue = fractionalValue % 100;
	}
	if ((wholeValue < 0) && (fractionalValue < 0))
	{
		wholeValue = 0;
		fractionalValue = 0;
	}
}


#endif