#pragma once


class Ctime {
public: 
	int sec;
	int min;
	int hour;

	Ctime();

	friend ostream& operator << (ostream& os, const Ctime& cl);
};


class CData {
private:
	string mon_to_string(tm* tmprt);
public: 
	int year;
	string mon;
	int day;

	CData();

	friend ostream& operator << (ostream& os, const CData& cl);
};