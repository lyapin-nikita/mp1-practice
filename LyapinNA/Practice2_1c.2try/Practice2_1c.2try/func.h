#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char employee[20], name_company[20], salary[10], work_cond[100], request[100];
	unsigned char ind;
}vacancy;

FILE* open_stream(const char* path);
int count_vacancy(FILE* read);
void allocate_memory(vacancy** Vacancy, int countVacancy);
vacancy* fill_structures(FILE* file, int vacancyCount);
int* search_employee(vacancy* Vacancy, int countVacancy);
void output_info(vacancy* Vacancy, int* ind, int countVacancy);
void free_memory(vacancy* Vacancy);

