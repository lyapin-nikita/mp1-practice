#include "func.h"






FILE* open_stream(const char* path) {
	FILE* read;
	read = fopen(path, "r");

	if (read == NULL) {
		printf("Файл не найден!");
		return 0;
	}
	return read;
}






int count_vacancy(FILE* read) {
	int vacancy_count = 0, lines_count = 1;

	while (feof(read) == 0)
	{
		if (fgetc(read) == '\n')
			lines_count++;
	}

	vacancy_count = (lines_count + 1) / 5;
	printf("%d\n\n", vacancy_count);
	return vacancy_count;
}






void allocate_memory(vacancy** Vacancy, int countVacancy) {
	(*Vacancy) = (vacancy*)malloc(sizeof(vacancy) * countVacancy);
}






vacancy* fill_structures(FILE* file, int vacancyCount) {
	vacancy* Vacancy;
	allocate_memory(&Vacancy, vacancyCount);
	int stringCount = vacancyCount * 5, j = 0, positionOnList = 1, v = 0, i = 1;
	char* text = (char*)malloc(100);
	fseek(file, 0, SEEK_SET);
	while ( j < stringCount ) {

		if (i > 5) {
			i = 1;
			v++;
		}

		fgets(text, 100, file);

		if (i == 1) {
			strcpy(Vacancy[v].employee, text);
			Vacancy[v].ind = v + 1;
		}
		else if (i == 2)
			strcpy(Vacancy[v].name_company, text);
		else if (i == 3)
			strcpy(Vacancy[v].salary, text);
		else if (i == 4)
			strcpy(Vacancy[v].work_cond, text);
		else
			strcpy(Vacancy[v].request, text);

		//printf("\n %s", text);
		j++; i++; 
	}

	//printf("%s", text);
	free(text);
	return Vacancy;
}






int* search_employee(vacancy* Vacancy, int countVacancy) {
	int i = 0, j = 0;
	int* res;
	res = (int*)malloc(4 * countVacancy);
	char str[20];
	char* str2;
	printf("Какую должность вы ищете?\t");
	gets(str);
	str2 = strcat(str, "\n");
	for (; i < countVacancy; i++) {
		if (strcmp(str2, Vacancy[i].employee) == 0)
		{
			res[j] = Vacancy[i].ind;
			j++;
		}
	}

	
	return res;
}






void output_info(vacancy* Vacancy, int* ind, int countVacancy) {
	int sizeMas = 0;

	for (int i = 0; i < countVacancy; i++) {
		if ((ind[i] > 0) && (ind[i] <= Vacancy[countVacancy - 1].ind)) {
			sizeMas++;
		}
		else
			break;
	}
	printf("\n\nКоличество найденных вакансий: %d", sizeMas);
	for (int i = 0; i < sizeMas; i++) {
		printf("\nДолжность: %s Компания: %s Заработная плата: %s ", Vacancy[ind[i] - 1].employee, Vacancy[ind[i] - 1].name_company, Vacancy[ind[i] - 1].salary);
		printf("Условия работы: %s Требования к вакансии: %s \n", Vacancy[ind[i] - 1].work_cond, Vacancy[ind[i] - 1].request);
	}
}





void free_memory(vacancy* Vacancy) {
	free(Vacancy);
}







