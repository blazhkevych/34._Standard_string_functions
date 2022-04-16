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

	do
	{
		cout << "Enter task number:: "
			<< "\nTask 1."
			<< "\nTask 2."
			<< "\nTask 3."
			<< "\nTask 4."
			<< endl;
		//cin >> choice;
		//cin.get();

		switch (3)
			//switch (choice)
		{
		case 1:
		{
			/*
			1. Написать функцию, которая удаляет из строки символ с заданным
			индексом. Строку и индекс необходимо передать в функцию через
			входные параметры.
			*/
			//1:40:40 описание дз
			// Из функции должен возвращатся динам. массив с модиф. строкой. Переделать!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.
			int index{ 0 };
			char str1[] = "String"; // 6 символов (0,1,2,3,4,5 - возможные индексы)
			char* ptrStr1 = str1;
			char str2[]{ '\0' };
			char* ptrStr2 = str2;
			index = 2;
			RemovesCharWithGivenIndex(ptrStr1, ptrStr2, index);
			RussianMessage("Строка: ");
			cout << str1 << endl;
			RussianMessage("Модифицированная строка: ");
			cout << str2 << endl;
		}
		break;

		case 2:
		{
			/*
			2. Написать функцию, которая удаляет из строки все вхождения в нее
			заданного символа. Строку и символ необходимо передать в функцию
			через входные параметры.
			*/
			//1:40:40 описание дз
			char symbol{ 'a' };
			char str1[100] = "abzxcvnraaaacadabra"; // 19 символов
			char* ptrStr2{ nullptr };
			ptrStr2 = RemovesAllOccurOfCharFromString(str1, symbol);
			RussianMessage("Строка: ");
			cout << str1 << endl;
			RussianMessage("Модифицированная строка: ");
			cout << ptrStr2 << endl;
			delete[] ptrStr2;
		}
		break;

		case 3:
		{
			/*
			3. Написать функцию, которая принимает в качестве параметра строку
			символов. Необходимо проверить является ли эта строка палиндромом.
			*/
			char str1[100] = "okro"; // Was it a car or a cat I saw
			char* ptrStr2{ nullptr };
			RussianMessage("Строка: ");
			cout << str1 << endl;

			bool result = IsPalindrome(str1);
			if (result == true)
				cout <<"\Palindrome!" << endl;
			else
				cout << "\nNot a palindrome!" << endl;			
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