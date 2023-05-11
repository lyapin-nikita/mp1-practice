#pragma once


class productline : public Creceipt{
protected:
	product* Products; // сделать заполнение массива данными
public:
	int count;
	productline();
	~productline();
};