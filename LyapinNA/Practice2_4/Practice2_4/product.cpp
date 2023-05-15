#include "stdafx.h"


//Конструкторы
product::product()
{
	name = "NONAME";
	barcode = "0000";
	price = 0;
}

product::product(string name, string barcode, uint16_t price)
{
	string res(barcode, 0, 4);
	this->name = name;
	this->barcode = res;
	this->price = price;
}



//Сеттеры
void product::setName(string name)
{
	this->name = name;
}

void product::setBarcode(string barcode)
{
	string res(barcode, 0, 4);
	this->barcode = res;
}

void product::setPrice(uint16_t price)
{
	this->price = price;
}



//Геттеры
string product::getName()
{
	return name;
}

string product::getBarcode()
{
	return barcode;
}

uint16_t product::getPrice()
{
	return price;
}





