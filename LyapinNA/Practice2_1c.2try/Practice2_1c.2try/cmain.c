#include "func.h"



void main() {
	system("chcp 1251");
	vacancy* Vacancy;
	char* path = "list.txt";
	FILE* file = open_stream(path);
	int countVacancy = count_vacancy(file);
	int* a = (int*)malloc(4 * countVacancy);
	allocate_memory(&Vacancy, countVacancy);
	Vacancy = fill_structures(file, countVacancy);
	a = search_employee(Vacancy, countVacancy);
	output_info(Vacancy, a, countVacancy);
	free_memory(Vacancy);
}