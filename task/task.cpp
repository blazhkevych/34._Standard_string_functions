#include <iostream>
#include "lib.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
	char answer{ 0 }; // Do you want to continue?
	int choice{ 0 }; // ����� �������

	char str1[100], str2[100], * p;
	int number{ 0 };

	do
	{
		cout << "Enter task number:: "
			<< "\nTask 1."
			<< "\nTask 2."
			<< "\nTask 3."
			<< "\nTask 4."
			<< "\nTask 5."
			<< "\nTask 6."
			<< "\nTask 7."
			<< endl;
		cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1:
		{
			/*
			1. �������� �������, ������� ������� �� ������ ������ � ��������
			��������. ������ � ������ ���������� �������� � ������� �����
			������� ���������.
			*/
		}
		break;

		case 2:
		{
			/*
			2. �������� �������, ������� ������� �� ������ ��� ��������� � ���
			��������� �������. ������ � ������ ���������� �������� � �������
			����� ������� ���������.
			*/

		}
		break;

		case 3:
		{
			/*
			3. �������� �������, ������� ��������� � �������� ��������� ������
			��������. ���������� ��������� �������� �� ��� ������ �����������.
			*/

		}
		break;

		case 4:
		{
			/*
			4. �������� �������, ������� ��������� �������� ������ � ������ �
			��������� �������. ������, ������ � ������� ���������� �������� �
			������� ����� ������� ���������.
			*/

		}
		break;
		}

		cout << endl;
		cout << "Do you want to continue? ( y (yes) / n (no) )\n";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

	return 0;
}