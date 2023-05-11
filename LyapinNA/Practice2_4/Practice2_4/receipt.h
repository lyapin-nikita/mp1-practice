#pragma once


class Creceipt : public Ctime, public CData {

protected:
	product* Products;
	int num;
public:
	static int sum;
	Creceipt();
	~Creceipt(); 


	friend ostream& operator << (ostream& os, const Creceipt& cl);
};