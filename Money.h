#pragma once
#include <string>
using namespace std;

class Money {
	long hrn;	//	�����
	unsigned short kop;	//	������

public:
	Money();
	Money Read();	//	�������� � ���������
	Money(long h, unsigned short k);
	void Display();
	string toString();	//	������������ �� �����
	Money operator+(Money obj);
	friend double operator-(Money obj1, Money obj2);
	friend double operator*(Money obj1, Money obj2);
	friend double operator/(Money obj1, Money obj2);
	friend bool operator==(Money obj1, Money obj2);
};
