#include <iostream>
#include "Money.h"
#include <Windows.h>


using std::cin;
using std::cout;
using std::string;

int Check(int chose, int range);

void MainMenu();

void Filing(Money *anything);

void OperationMenu(Money* first, Money* second, int choseOperation);

int main()
{
	SetConsoleOutputCP(1251);

	int chose;

	Money* First = new Money(0, 0);
	Money* Second = new Money(0, 0);

	do
	{
		MainMenu();

		chose = Check(0, 4);

		switch (chose)
		{
		case 1: //Ввести монеты
		{
			cout << "\nПервая: ";
			Filing(First);

			cout << "\nВторая: ";
			Filing(Second);

		} break;
		case 2://Просмотр номинала
		{
			cout << "\nПервая: \n";
			
			cout <<First->toString();

			cout << "\nВторая: \n";
			cout << Second->toString();
		} break;
		case 3: //Дейтсвия
		{
			int choseOperation;

			cout << "\nЧто вы хотите сделать с монетами:";
			cout << "\n1)Сложить";
			cout << "\n2)Вычесть";
			cout << "\n3)Поделить сумму монет";
			cout << "\n4)Поделить сумму на дробное число";
			cout << "\n5)Умножить на дробное число";
			cout << "\n6)Сравнить";
			cout << "\n7)Вернуться к предыдущему пункту\n";

			choseOperation = Check(0, 7);

			OperationMenu(First, Second,choseOperation);
		} break;
		}
	} while (chose != 4);

	delete First;
	delete Second;

	return 0;
}

int Check(int left, int right)
{
	int chose = 0;

	cout << "\nВведите значение: от " << left << " до " << right << "\n";
	cin >> chose;

	while ((chose < left) || (chose > right))
	{
		cin.ignore();
		cout << "\nЗничение не в заданном диапазоне!\nВведите верное значение:";
		cin >> chose;
	}
	cout << "----------------------------------------------------------------------";
	return chose;
}

void MainMenu()
{
	cout << "\n----------------------------------------------------------------------";
	cout << "\nПрограмма для работы с деньгами предлогает вам варианты меню:";
	cout << "\n1)Внести монеты";
	cout << "\n2)Посмотреть номинал монет";
	cout << "\n3)Посмотреть возможные действия с монетами";
	cout << "\n4)Выйти из программы\n";
}

void Filing(Money *any)
{
	int rubles, penny;

	cout << "\nВведите рубли: ";
	rubles = Check(0, 100000000);

	cout << "\nВведите копейки: ";
	penny = Check(0, 100000000);

	if (penny > 99)
	{
		rubles += penny / 100;
		penny = penny % 100;
	}

	any->setRubles(rubles);
	any->setPenny(penny);	
}

void OperationMenu(Money* first, Money* second, int choseOperation)
{
	Money* result = nullptr;
	switch (choseOperation)
	{
	case 1: //сложение
	{
		result = first->SumMoney(second);
		cout << "\nРезультат сложения монет: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 2: //вычитание
	{
		result = first->SubtractionMoney(second);
		cout << "\nРезультат вычитания монет: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 3: //деление суммы на целое число
	{
		int part;

		cout << "\nВведите на какое количество частей вы хотите разделить сумму: ";
		cin >> part;
		part = trunc(abs(part));

		result = first->SumMoney(second);

		result = result->FractionalMultiplication(part);

		cout << "\nРезультат деления монет: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 4: //деление суммы на дробное число
	{
		double part;

		cout << "\nВвведите дробное число, на которое надо разделить сумму: ";

		cin >> part;
		part = abs(part);

		result = first->SumMoney(second);
		result = result->FractionalMultiplication(part);

		cout << "\nРезультат деления монет на дробное число: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 5: //умножение на дробное число
	{
		int chose;
		cout << "\nКакую монету вы хотите умножить:\n1)Первую \n2)Вторую\n";
		cin >> chose;

		if (chose >= 2) chose = 2; //округление результата выбора
		else chose = 1;

		double part;
		cout << "\nВвведите дробное число, на которое надо умножить число: ";
		cin >> part;
		part = abs(part);

		if (part == 0) part += 1; //изменяем если 0 на 1

		if (chose == 1)	result = first->MultiplyMoney(part);
		else result = second->MultiplyMoney(part);

		cout << "\nРезультат умножения монет на дробное число: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 6://сравнение
	{
		int compareresult = first->CompareMoney(second);
		if (compareresult == 0) cout << "\nОни равны!\n";
		else if (compareresult == 1) cout << "\nПеравя больше!\n";
		else cout << "\nВторая больше!\n";
	}break;
	}
}
