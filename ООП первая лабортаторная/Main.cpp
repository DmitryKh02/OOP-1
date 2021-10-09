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
		case 1: //������ ������
		{
			cout << "\n������: ";
			Filing(First);

			cout << "\n������: ";
			Filing(Second);

		} break;
		case 2://�������� ��������
		{
			cout << "\n������: \n";
			
			cout <<First->toString();

			cout << "\n������: \n";
			cout << Second->toString();
		} break;
		case 3: //��������
		{
			int choseOperation;

			cout << "\n��� �� ������ ������� � ��������:";
			cout << "\n1)�������";
			cout << "\n2)�������";
			cout << "\n3)�������� ����� �����";
			cout << "\n4)�������� ����� �� ������� �����";
			cout << "\n5)�������� �� ������� �����";
			cout << "\n6)��������";
			cout << "\n7)��������� � ����������� ������\n";

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

	cout << "\n������� ��������: �� " << left << " �� " << right << "\n";
	cin >> chose;

	while ((chose < left) || (chose > right))
	{
		cin.ignore();
		cout << "\n�������� �� � �������� ���������!\n������� ������ ��������:";
		cin >> chose;
	}
	cout << "----------------------------------------------------------------------";
	return chose;
}

void MainMenu()
{
	cout << "\n----------------------------------------------------------------------";
	cout << "\n��������� ��� ������ � �������� ���������� ��� �������� ����:";
	cout << "\n1)������ ������";
	cout << "\n2)���������� ������� �����";
	cout << "\n3)���������� ��������� �������� � ��������";
	cout << "\n4)����� �� ���������\n";
}

void Filing(Money *any)
{
	int rubles, penny;

	cout << "\n������� �����: ";
	rubles = Check(0, 100000000);

	cout << "\n������� �������: ";
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
	case 1: //��������
	{
		result = first->SumMoney(second);
		cout << "\n��������� �������� �����: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 2: //���������
	{
		result = first->SubtractionMoney(second);
		cout << "\n��������� ��������� �����: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 3: //������� ����� �� ����� �����
	{
		int part;

		cout << "\n������� �� ����� ���������� ������ �� ������ ��������� �����: ";
		cin >> part;
		part = trunc(abs(part));

		result = first->SumMoney(second);

		result = result->FractionalMultiplication(part);

		cout << "\n��������� ������� �����: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 4: //������� ����� �� ������� �����
	{
		double part;

		cout << "\n�������� ������� �����, �� ������� ���� ��������� �����: ";

		cin >> part;
		part = abs(part);

		result = first->SumMoney(second);
		result = result->FractionalMultiplication(part);

		cout << "\n��������� ������� ����� �� ������� �����: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 5: //��������� �� ������� �����
	{
		int chose;
		cout << "\n����� ������ �� ������ ��������:\n1)������ \n2)������\n";
		cin >> chose;

		if (chose >= 2) chose = 2; //���������� ���������� ������
		else chose = 1;

		double part;
		cout << "\n�������� ������� �����, �� ������� ���� �������� �����: ";
		cin >> part;
		part = abs(part);

		if (part == 0) part += 1; //�������� ���� 0 �� 1

		if (chose == 1)	result = first->MultiplyMoney(part);
		else result = second->MultiplyMoney(part);

		cout << "\n��������� ��������� ����� �� ������� �����: " << result->toString();

		delete result;
		result = nullptr;
	}break;
	case 6://���������
	{
		int compareresult = first->CompareMoney(second);
		if (compareresult == 0) cout << "\n��� �����!\n";
		else if (compareresult == 1) cout << "\n������ ������!\n";
		else cout << "\n������ ������!\n";
	}break;
	}
}
