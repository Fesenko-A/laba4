#include "Money.h"
#include <iostream>
#include <string>
using namespace std;

Money::Money(long h, unsigned short k)	//	Введення значень (вручну)
{
	hrn = h;
	kop = k;
	cout << "\nГрн: " << h << endl;
	cout << "Коп: " << k << endl;
	if (k >= 100) {
		while (k >= 100) {
			k -= 100;
			h++;
		}
	}
}

Money::Money()	//	Конструктор по замовченню
{
	hrn = 0;
	kop = 0;
}

Money Money::Read()
{
	cout << "\nГрн: ";
	cin >> this->hrn;
	cout << "Коп: ";
	cin >> this->kop;
	if (this->kop >= 100) {
		while (this->kop >= 100) {
			this->kop -= 100;
			this->hrn++;
		}
	}
	else return *this;
}

string Money::toString()
{
	string res(to_string(hrn) + "." + to_string(kop));	//	З'єднуємо гривні з копійками
	return res;
}

Money Money::operator+(Money obj)
{
	Money tmp;
	tmp.hrn = hrn + obj.hrn;
	tmp.kop = kop + obj.kop;
	while (tmp.kop >= 100) {
		tmp.kop -= 100;
		tmp.hrn++;
	}
	cout << "\nСума: " << tmp.hrn << "." << tmp.kop << endl;

	return tmp;
}

Money Money::operator-(Money obj)
{
	Money tmp;
	tmp.hrn = hrn - obj.hrn;
	tmp.kop = kop - obj.kop;
	cout << "\nРізниця: " << tmp.hrn << "." << tmp.kop << endl;

	return tmp;
}

Money Money::operator*(Money obj)
{
	Money tmp;
	tmp.hrn = hrn * obj.hrn;
	tmp.kop = kop * obj.kop;
	cout << "\nМноження: " << tmp.hrn << "." << tmp.kop << endl;

	return tmp;
}

Money Money::operator/(Money obj)
{
	Money tmp;
	if (obj.kop != 0 || obj.hrn != 0) {
		tmp.hrn = hrn / obj.hrn;
		tmp.kop = kop / obj.kop;
	}
	cout << "\nДілення: " << tmp.hrn << "." << tmp.kop << endl;

	return tmp;
}

void Money::Display()
{
	cout << "\nВведено: " << toString() << " грн." << endl;
}

bool operator==(Money obj1, Money obj2)
{
	if (obj1.hrn == obj2.hrn && obj1.kop == obj2.kop) {
		cout << "\nПорівняння: " << obj1.hrn << "." << obj1.kop << " дорівнює " << obj2.hrn << "." << obj2.kop << endl;
		return true;
	}
	else {
		cout << "\nПорівняння: " << obj1.hrn << "." << obj1.kop << " не дорівнює " << obj2.hrn << "." << obj2.kop << endl;
		return false;
	}
}