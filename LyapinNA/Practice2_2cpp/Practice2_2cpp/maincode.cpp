#include "func.h"

int main() {
	system("chcp 1251");
	  


	int count = 0, countVacancy = 0;
	string line;
	string path = "D:\\project_programming\\project_vs19\\homework\\Pracitce2_2cpp\\Pracitce2_2cpp\\list.txt";
	ifstream read;



	//Функция открытия потока 
	read = read_list(path);
	//Вывод количества строк
	while (getline(read, line))
		++count;


	//Определение числа вакансий
	countVacancy = count / N;
	if (countVacancy == 0) {
		cerr << "Error: Число вакансий не может быть равным 0!";
		return 1;
	}
	else
		cout << "Число найденных вакансий: " << countVacancy << endl;



	vacancy* Vacancy = new vacancy[countVacancy];
	
	//Заполнение массивы структур
	read.clear();
	read.seekg(0);
	string line2;
	int i = 0;
	for (; i < countVacancy; i++) {
		getline(read, Vacancy[i].employee);
		getline(read, Vacancy[i].nameCompany);
		getline(read, Vacancy[i].salary);
		getline(read, Vacancy[i].workCond);
		getline(read, Vacancy[i].request);
	}



	//int* ind = new int[countVacancy];
	//Поиск по названию
	if (!(search_vacancy(Vacancy, countVacancy))) {
		cerr << "Вакансий не было найдено!";
	}



	read.close();
	delete [] Vacancy;
	return 0;
}
