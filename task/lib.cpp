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

// Функция, удаляет из строки все вхождения в нее заданного символа.
char* RemovesAllOccurOfCharFromString(char* ptr1, char symbol)
{
	// a b b b b b b r a a a  a  c  a  d  a  b  r  a
	// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
	int i{ 0 };
	int lenght{ 0 };
	char* strNew{ nullptr };

	for (int j = 0; ptr1[j] != '\0'; j++) // подсчет размера массива под обработанную строку
	{
		if (ptr1[j] != symbol)
		{
			lenght++;
		}
	}

	strNew = new char[lenght + 1]{ '\0' }; // кол-во копируемых символов 11, + 1 нуль терм. = 12.
	while (true)
	{
		while (ptr1[i] != symbol)
		{
			strncat_s(strNew, lenght + 1, (ptr1 + i), 1);
			i++;
		}
		i++;
		if (ptr1[i] == '\0')
			break;
	}

	return strNew;
}

// Функция, принимает в качестве параметра строку
// символов. Проверяет является ли эта строка палиндромом.
bool IsPalindrome(char* ptr)
{
	int len = strlen(ptr) + 1;
	char* original = new char[len] { '\0' }; // Создаем динам. массив "original" для последующей работы с реверсированной строкой из "ptr"
	char* originalCleared = new char[len] { '\0' };
	char* reverse = new char[len] { '\0' }; // Создаем динам. массив "reverse" для последующей работы с реверсированной строкой из "ptr"

	strcpy_s(original, len, ptr); // Копируем из "ptr" в дин. массив "original"
	_strlwr_s(original, len); // Переводим в нижний регистр дин. строку "original"
	int i{ 0 }, count{ 0 };
	char* from{ nullptr };
	while (true)
	{
		if (char(*(original + i)) >= 'a' && char(*(original + i)) <= 'z')
		{
			from = original + i; // начало строки для копирования
			count = 0;
			while (char(*(original + i)) >= 'a' && char(*(original + i)) <= 'z')
			{
				count++; // подсчет кол-ва символов для копирования
				i++;
			}
			strncat_s(originalCleared, len, from, count);
		}
		i++;
		if (original[i] == '\0')
			break;
	}

	strcpy_s(reverse, len, originalCleared); // Копируем из "originalCleared" (уже в нижнем регистре и наличии только букв) в "reverse"
	_strrev(reverse); // Реверсируем строку 
	if (strcmp(originalCleared, reverse) == 0)
	{
		delete[] original;
		delete[] originalCleared;
		delete[] reverse;
		return true;
	}
	else
	{
		delete[] original;
		delete[] originalCleared;
		delete[] reverse;
		return false;
	}
}

// Функция, вставляет заданный символ в строку в указанную позицию. 
char* InsertCharInStrAtGivenPos(char* ptr, char symbol, int index)
{
	int len = strlen(ptr) + 1; // Длина входящей строки.
	int lenRes = len + 1; // Размер итоговой строки (+ 1 новый символ).
	char* result = new char[lenRes] { '\0' }; // Итоговая строка + 1 новый символ.

	strncat_s(result, lenRes, ptr, index); // Конкатенируем левую часть, до индекса
	//char* ptrSymbol = &symbol;
	strncat_s(result, lenRes, &symbol, 1); // Конкатенируем в заданный индекс символ
	strncat_s(result, lenRes, ptr + index, len - index); // Конкатенируем правую часть 

	return result;
}