#include "stdafx.h"





int Creceipt::sum = 0;

Creceipt::Creceipt()
{
	sum++;
	num = sum;
}



ostream& operator << (ostream& os, const Creceipt& cl) {
	os << "Чек #" << cl.num << endl;
	os << cl.day << " " << cl.mon << " " << cl.year << " " << endl;
	os << cl.hour << " час, " << cl.min << " минута, " << cl.sec << " секунда." << endl;
	return os;
}
