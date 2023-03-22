#include "func.h"





//Функция открытия потока для чтения
ifstream read_list(string path) {
	ifstream read(path);

	if (!read)
		cerr << "Произошла ошибка при открытия файла для чтения!" << endl;
	else
		cout << "Поток был успешно открыт!" << endl;

	return read;
}






int search_vacancy(vacancy* Vacancy, int countVacancy) {
	int j = 0, k = 0;
	string search;
	int* index = new int[countVacancy];
	cout << "Введите название профессии, которую вы ищете: " << endl;
	cin >> search;


	for (; j < countVacancy; j++) {
		index[j] = -1;
		if (Vacancy[j].employee.compare(search) == 0) {
			index[k] = j;
			k++;
		}
	}

	if (index[0] == -1) {
		return NULL;
	}

	print_info(Vacancy, k, index, countVacancy);
	return 1;
}






void print_info(vacancy* Vacancy, int countSearchedVacancy, int* indexes, int countVacancy) {
	int j = 0;
	cout << "\nМы нашли вакансии (" << countSearchedVacancy << "шт) по Вашему запросу:" << "\n\n";
	for (j = 0; (indexes[j] != -1) && (j < countVacancy); j++) {
		cout << "\n-----------------------------------\n";
		cout << "Профессия: " << Vacancy[indexes[j]].employee << endl;
		cout << "Название компании: " << Vacancy[indexes[j]].nameCompany << endl;
		cout << "Зарплата: " << Vacancy[indexes[j]].salary << endl;
		cout << "Условия труда: " << Vacancy[indexes[j]].workCond << endl;
		cout << "Требования к соискателю: " << Vacancy[indexes[j]].request << endl;
	}
		
}