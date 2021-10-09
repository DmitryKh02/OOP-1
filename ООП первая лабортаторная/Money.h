#pragma once
#include <string>
class Money
{
	long rubles;
	unsigned short penny;
public:
	Money(long x,unsigned short y);
	~Money();

	void setRubles(long rubles_);
	void setPenny(unsigned short penny_);

	long getRubles();
	unsigned short getPenny();

	int  Translate(); //превращает в единую сумму 
	std::string  toString();

	Money * SumMoney(Money *second);
	Money * SubtractionMoney(Money *second);
	Money *FractionalMultiplication(double part);
	Money* MultiplyMoney(double part);
	int CompareMoney(Money *second);
};


