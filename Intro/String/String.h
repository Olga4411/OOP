#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
class String
{
	unsigned int size;// размер строки в байтах
	char* str;//указатель на строку в динамической памяти
	// Строка-массив

public:
	unsigned int get_size()const;
	const char* get_str()const;
	char* get_str();
	explicit String(unsigned int size = 80);
	String(const char* str);
	String(const String& other);
	~String();

	//Operators
	String& operator=(const String& other);
	String& operator+=(const String& other);
	// оператор квадратные скобки (Оператор индексирования)- [] Subcribe operator возвращает значение по индексу
	const char& operator[](unsigned int i)const;

	char& operator[](unsigned int i);
	// Methods:
	void print()const;
};