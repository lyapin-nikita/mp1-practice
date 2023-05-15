#pragma once


class Creceipt : public Ctime, public CData {
protected:
	int num;
public:
	static int sum;
	Creceipt();
};