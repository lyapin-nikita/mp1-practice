#pragma once


class productline : public Creceipt{
protected:
	product* Products; // ������� ���������� ������� �������
public:
	int count;
	productline();
	~productline();
};