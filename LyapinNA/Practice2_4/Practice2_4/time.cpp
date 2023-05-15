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
	os << cl.hour << " ���, " << cl.min << " ������, " << cl.sec << " �������." << endl;
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
	case 0: return "������"; break;
	case 1: return "�������"; break;
	case 2: return "����"; break;
	case 3: return "������"; break;
	case 4: return "���"; break;
	case 5: return "����"; break;
	case 6: return "����"; break;
	case 7: return "������"; break;
	case 8: return "��������"; break;
	case 9: return "�������"; break;
	case 10: return "������"; break;
	case 11: return "�������"; break;
	}

}

ostream& operator<<(ostream& os, const CData& cl)
{
	os << cl.day << " " << cl.mon << " " << cl.year << " ";
	return os;
}

