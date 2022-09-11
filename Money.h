#pragma once
#include <string>
using namespace std;

class Money {
	long hrn;	//	Гривні
	unsigned short kop;	//	Копійки
	double num;	//	Число, на яке множимо, додаємо до суми та ін.

public:
	Money();
	Money(long h, unsigned short k, double n);
	void Display();
	string toString();	//	Перетворення на рядок
	Money operator +(Money obj);	//	Сума грн та коп об'єктів класу
	Money operator -(Money obj);	//	Різниця грн та коп об'єктів класу
	friend bool operator ==(Money obj1, Money obj2);	//	Порівняння двох об'єктів
};
