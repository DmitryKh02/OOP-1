#include "Money.h"
#include <iostream>
#include<string>
#include <ostream>

using std::cin;
using std::cout;
using std::string;

Money::Money(long x, unsigned short y)
{
	rubles = x;
	penny = y;

	if (penny > 99)
	{
		rubles += penny / 100;
		penny = penny % 100;
	}
}

Money::~Money()
{
}

void Money::setRubles(long rubles_)
{
	rubles = rubles_;
} //считывание рублей

void Money::setPenny(unsigned short penny_)
{
	penny = penny_;
} //считывание копеек в исходном виде

long Money::getRubles()
{
	return rubles;
}

unsigned short Money::getPenny()
{
	return penny;
}

int Money::Translate()
{
	return rubles*100+penny;
}

string  Money::toString()
{
	string s = "\nМонет: ";
	s+=std::to_string(getRubles());

	s += "  Копеек: ";
	s+=std::to_string(getPenny());
	s += "\n";

	return s;
}

Money* Money::SumMoney(Money *second)
{
	Money* result= new Money(rubles + second->rubles, penny + second->penny);

	return result;
}

Money* Money::SubtractionMoney(Money* second)
{
	int substraction = abs(Translate() - second->Translate());
	
	Money *result = new Money(substraction / 100, substraction % 100);

	return result;
}

Money* Money::FractionalMultiplication(double part)
{
	double allofsum = Translate();

	double resultMult= allofsum / part;

	int residue = trunc(resultMult);

	cout << "\nСтолько монет не попало ни в одну кучу:" << (allofsum - part * residue);

	Money* result = new Money(residue / 100, residue % 100);

	return result;
}

Money* Money::MultiplyMoney(double part)
{
	double allofsum= Translate();

	allofsum *= part;

	int resultof = trunc(allofsum);

	Money* result = new Money(resultof / 100, resultof % 100);
	return result; 
}

int Money::CompareMoney(Money* second)
{
	int result = 0; 
	if ((rubles > second->rubles) || ((rubles == second->rubles) && (penny > second->penny))) result = 1;
	else
		if ((rubles == second->rubles) && (penny == second->penny)) result = 0;
		else result = 2;

	return result;
} 


