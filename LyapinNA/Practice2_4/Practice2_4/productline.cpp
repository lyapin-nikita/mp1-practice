#include "stdafx.h"

productline::productline()
{
	count = 0;
	string str;
	fstream read;
	read.open("list.txt");


	if (!read) 
	{
		cout << "���� �� ��� ������!" << endl;
	}
	else 
	{
		cout << "���� ��� ������� ������!" << endl;

		while (read.eof() == false)
		{
			getline(read, str);
			count++;
		}
	}


	read.close();
}



productline::~productline()
{
	delete[] Products;
}
