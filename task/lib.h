// Функция определяет и выводит на экран самое длинное слово в предложении 
void LongestWord(const char*);
// Функция проверяет корректность передаваемого символа (0...9, +, -)
bool Check(char symbol);
// Функция вычисляет результат арифметического выражения
bool Arithmetic(const char*, int&);

// Функция выводит русский текст в окно консоли
void RussianMessage(const char* s);

// Функция, которая удаляет из строки символ с заданным
// индексом. 
void RemovesCharWithGivenIndex(char* ptr1, char* ptr2, int index);

// Функция, удаляет из строки все вхождения в нее заданного символа.
char *  RemovesAllOccurOfCharFromString(char* ptr1, char symbol);

// Функция, принимает в качестве параметра строку
// символов. Проверяет является ли эта строка палиндромом.
bool IsPalindrome(char * ptr);

// Функция, вставляет заданный символ в строку в указанную позицию. 
char * InsertCharInStrAtGivenPos(char * ptr, char symbol, int index);