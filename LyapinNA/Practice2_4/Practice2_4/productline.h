#pragma once


class productline{
protected:
	int count;
	product* Products = new product[count]; // сделать заполнение массива данными
public:
	productline();
	~productline();
};