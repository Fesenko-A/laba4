#pragma once
#include <string>
using namespace std;

class Money {
	long hrn;	//	�����
	unsigned short kop;	//	������
	double num;	//	�����, �� ��� �������, ������ �� ���� �� ��.

public:
	Money();
	Money(long h, unsigned short k, double n);
	void Display();
	string toString();	//	������������ �� �����
	Money operator +(Money obj);	//	���� ��� �� ��� ��'���� �����
	Money operator -(Money obj);	//	г����� ��� �� ��� ��'���� �����
	friend bool operator ==(Money obj1, Money obj2);	//	��������� ���� ��'����
};
