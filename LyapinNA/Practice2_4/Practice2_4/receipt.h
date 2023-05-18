#pragma once


class Creceipt : public Ctime, public CData {
protected:
	int num;
	//ListContainer <product> Products;
public:
	static int sum;
	Creceipt();
};