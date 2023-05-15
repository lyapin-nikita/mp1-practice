#include "stdafx.h"


Ctime::Ctime()
{
	sec = 0;
	min = 0;
	hour = 0;

	time_t valueTime = time(0);
	tm* tmptr = localtime(&valueTime);
	sec = tmptr->tm_sec;
	min = tmptr->tm_min;
	hour = tmptr->tm_hour;
}


ostream& operator<<(ostream& os, const Ctime& cl)
{
	os << cl.hour << " час, " << cl.min << " минута, " << cl.sec << " секунда." << endl;
	return os;
}










CData::CData()
{
	year = 1900;
	mon = "January";
	day = 1;
	
	time_t valueTime = time(0);
	tm* tmptr = localtime(&valueTime);
	year = 1900 + tmptr->tm_year;
	mon = mon_to_string(tmptr);
	day = tmptr->tm_mday;
}

string CData::mon_to_string(tm* tmptr)
{
	string month;
	
	switch (tmptr->tm_mon) {
	case 0: return "Январь"; break;
	case 1: return "Февраль"; break;
	case 2: return "Март"; break;
	case 3: return "Апрель"; break;
	case 4: return "Май"; break;
	case 5: return "Июнь"; break;
	case 6: return "Июль"; break;
	case 7: return "Август"; break;
	case 8: return "Сентябрь"; break;
	case 9: return "Октябрь"; break;
	case 10: return "Ноябрь"; break;
	case 11: return "Декабрь"; break;
	}

}

ostream& operator<<(ostream& os, const CData& cl)
{
	os << cl.day << " " << cl.mon << " " << cl.year << " ";
	return os;
}

