#include "Money.h"
#include <iostream>
#include <string>
using namespace std;

Money::Money(long h, unsigned short k, double n) //	�����������
{
	hrn = h;
	kop = k;
	num = n;
}

Money::Money()	//	���������� (������ ������ Read)
{
	cout << "\n���: ";
	cin >> hrn;
	cout << "���: ";
	cin >> kop;
	cout << "�����: ";
	cin >> num;
	if (kop >= 100)
		cout << "������� - ������ �� ���� ���� ����� 99" << endl;
}

string Money::toString()
{
	string res(to_string(hrn) + "." + to_string(kop));	//	�'������ ����� � ��������
	return res;
}

Money Money::operator+(Money obj)
{
	Money tmp(0, 0, 0);
	tmp.hrn = hrn + obj.hrn;
	tmp.kop = kop + obj.kop;
	cout << "\n���� ������� � ������ ��'���� �����: " << tmp.hrn << "." << tmp.kop;
	return tmp;
}

Money Money::operator-(Money obj)
{
	Money tmp(0, 0, 0);
	tmp.hrn = hrn - obj.hrn;
	tmp.kop = kop - obj.kop;
	cout << "\nг����� ������� � ������ ��'���� �����: " << tmp.hrn << "." << tmp.kop;
	return tmp;
}

void Money::Display()
{
	cout << "\n�������: " << toString() << " ���." << endl;
	double s = stod(toString());	//	������������ ����� � �������� ��� double
	double sum = s + num;
	double minus = s - num;
	double mn = s * num;
	bool equal = s == num;	//	�������� ���������
	cout << endl;
	if (num != 0) {	//	�������� ������ �� 0
		double dil = s / num;
		cout << "ĳ�����: " << dil << endl;
	}
	else cout << "ĳ����� �� 0 ���������!" << endl;

	cout << "����: " << sum << endl;
	cout << "г�����: " << minus << endl;
	cout << "��������: " << mn << endl;
	cout << "���������: ";
	if (equal == 1) cout << s << " == " << num << endl;	//	��������� ���� �����
	else cout << s << " != " << num << endl;
}

bool operator==(Money obj1, Money obj2)
{
	if (obj1.hrn == obj2.hrn && obj1.kop == obj2.kop) {
		cout << "\n��'���� ��� ���� �� ����� (��� == ���)" << endl;
		return true;
	}
	else { 
		cout << "\n��'���� �� ��� ���� �� ����� (��� != ���)" << endl;
		return false; 
	}
}
