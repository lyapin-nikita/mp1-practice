#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

extern const char* corporation[5];
extern const char* employee[4];
extern const char* working_conditions[3];
extern const char* request[4];

struct info {
	char name1[15];
	char employee1[20];
	char working_conditions1[150];
	char request[150];
	unsigned int solary;
};


void random_vacancy(info* Infostruct);
void inference(info Infostruct);
info* search();