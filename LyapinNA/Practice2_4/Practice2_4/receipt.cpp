#include "stdafx.h"





int Creceipt::sum = 0;

Creceipt::Creceipt()
{
	sum++;
	num = sum;
}



ostream& operator << (ostream& os, const Creceipt& cl) {
	os << "��� #" << cl.num << endl;
	os << cl.day << " " << cl.mon << " " << cl.year << " " << endl;
	os << cl.hour << " ���, " << cl.min << " ������, " << cl.sec << " �������." << endl;
	return os;
}
