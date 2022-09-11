#include "Money.h"
#include <iostream>
#include <string>
using namespace std;

Money::Money(long h, unsigned short k, double n) //	Ініціалізатор
{
	hrn = h;
	kop = k;
	num = n;
}

Money::Money()	//	Зчитування (аналог методу Read)
{
	cout << "\nГрн: ";
	cin >> hrn;
	cout << "Коп: ";
	cin >> kop;
	cout << "Число: ";
	cin >> num;
	if (kop >= 100)
		cout << "Помилка - копійок не може бути більше 99" << endl;
}

string Money::toString()
{
	string res(to_string(hrn) + "." + to_string(kop));	//	З'єднуємо гривні з копійками
	return res;
}

Money Money::operator+(Money obj)
{
	Money tmp(0, 0, 0);
	tmp.hrn = hrn + obj.hrn;
	tmp.kop = kop + obj.kop;
	cout << "\nСума гривень і копійок об'єктів класу: " << tmp.hrn << "." << tmp.kop;
	return tmp;
}

Money Money::operator-(Money obj)
{
	Money tmp(0, 0, 0);
	tmp.hrn = hrn - obj.hrn;
	tmp.kop = kop - obj.kop;
	cout << "\nРізниця гривень і копійок об'єктів класу: " << tmp.hrn << "." << tmp.kop;
	return tmp;
}

void Money::Display()
{
	cout << "\nВведено: " << toString() << " грн." << endl;
	double s = stod(toString());	//	Перетворюємо рядок у числовий тип double
	double sum = s + num;
	double minus = s - num;
	double mn = s * num;
	bool equal = s == num;	//	Операція порівняння
	cout << endl;
	if (num != 0) {	//	Перерівка ділення на 0
		double dil = s / num;
		cout << "Ділення: " << dil << endl;
	}
	else cout << "Ділення на 0 неможливе!" << endl;

	cout << "Сума: " << sum << endl;
	cout << "Різниця: " << minus << endl;
	cout << "Множення: " << mn << endl;
	cout << "Порівняння: ";
	if (equal == 1) cout << s << " == " << num << endl;	//	Порівняння двох чисел
	else cout << s << " != " << num << endl;
}

bool operator==(Money obj1, Money obj2)
{
	if (obj1.hrn == obj2.hrn && obj1.kop == obj2.kop) {
		cout << "\nОб'єкти рівні один між одним (грн == коп)" << endl;
		return true;
	}
	else { 
		cout << "\nОб'єкти не рівні один між одним (грн != коп)" << endl;
		return false; 
	}
}
