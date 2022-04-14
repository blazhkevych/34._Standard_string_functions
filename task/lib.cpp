#include<iostream>
#include<windows.h>

using namespace std;

// Функция определяет и выводит на экран самое длинное слово в предложении 
void LongestWord(const char* text)
{
	char word[100] = { };
	const char* begin = text, * end = nullptr;
	int length = 0;
	while (true)
	{
		while (*begin == ' ')
			begin++;
		end = strchr(begin, ' ');
		if (end != nullptr)
		{
			if (length < end - begin)
			{
				length = end - begin;
				strncpy_s(word, sizeof(word), begin, length);
				word[length] = '\0';
			}
			begin = end + 1;
		}
		else
		{
			if (strlen(begin) > length)
			{
				length = strlen(begin);
				strcpy_s(word, sizeof(word), begin);
			}
			break;
		}
	}
	cout << "\nThe longest word: " << word;
}

// Функция проверяет корректность передаваемого символа (0...9, +, -)
bool Check(char symbol)
{
	if (symbol >= '0' && symbol <= '9' || symbol == '+' || symbol == '-')
		return true;
	else
		return false;
}

// Функция вычисляет результат арифметического выражения
bool Arithmetic(const char* str, int& result)
{
	bool incorrect = true;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (Check(str[i]))
			continue;
		else
		{
			cout << "\nIncorrect symbol \'" << str[i] << "\' in position " << i;
			incorrect = false;
		}
	}
	if (!incorrect)
		return false;
	result = 0;
	while (*str != '\0')
	{
		result += atoi(str);
		str++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return true;
}

// Функция выводит русский текст в окно консоли
void RussianMessage(const char* s)
{
	char* buf = new char[strlen(s) + 1];
	CharToOemA(s, buf);
	cout << buf;
	delete[] buf;
}

// Функция, которая удаляет из строки символ с заданным
// индексом. 
void RemovesCharWithGivenIndex(char* ptr1, char* ptr2, int index)
{
	int strSize = strlen(ptr1);
	int sizeofPtr1 = sizeof(ptr1);
	char left[50]{ 0 }, right[50]{ 0 };
	if (index == 0) // удаляем 1 букву, нету левой части
		strncat_s(ptr2, sizeof(ptr2), ptr1 + index + 1, strSize - index);
	else if (index > 0 && index < strSize) // центральная часть
	{
		strncpy_s(left, sizeof(left), ptr1, index);
		strncpy_s(right, sizeof(right), ptr1 + index + 1, strSize - index);
		strcat_s(ptr2, sizeof(ptr2), left);
		strcat_s(ptr2, sizeof(ptr2), right);
	}
	else if (index == strSize - 1) // удаляем последнюю букву, правой части нету
		strncpy_s(ptr2, sizeof(ptr2), ptr1, strSize - 1);
}