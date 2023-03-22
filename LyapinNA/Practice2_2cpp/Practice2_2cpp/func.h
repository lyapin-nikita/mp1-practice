#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#define N 5
using namespace std;


struct vacancy {
	string employee;
	string nameCompany;
	string salary;
	string workCond;
	string request;
};


ifstream read_list(string path); 
int search_vacancy(vacancy* Vacancy, int countVacancy);
void print_info(vacancy* Vacancy, int countSearchedVacancy, int* indexes, int countVacancy);
