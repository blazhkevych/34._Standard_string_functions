#include <iostream>
#include "lib.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
	char answer{ 0 }; // Do you want to continue?
	int choice{ 0 }; // Выбор задания

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
			1. Написать функцию, которая удаляет из строки символ с заданным
			индексом. Строку и индекс необходимо передать в функцию через
			входные параметры.
			*/
		}
		break;

		case 2:
		{
			/*
			2. Написать функцию, которая удаляет из строки все вхождения в нее
			заданного символа. Строку и символ необходимо передать в функцию
			через входные параметры.
			*/

		}
		break;

		case 3:
		{
			/*
			3. Написать функцию, которая принимает в качестве параметра строку
			символов. Необходимо проверить является ли эта строка палиндромом.
			*/

		}
		break;

		case 4:
		{
			/*
			4. Написать функцию, которая вставляет заданный символ в строку в
			указанную позицию. Строку, символ и позицию необходимо передать в
			функцию через входные параметры.
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