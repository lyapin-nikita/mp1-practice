#pragma once


class productline{
protected:
	int count;
	product* Products = new product[count]; // ������� ���������� ������� �������
public:
	productline();
	~productline();
};