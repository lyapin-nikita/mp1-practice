#include "func.h"

int main() {
	system("chcp 1251");
	  


	int countVacancy = 0;
	string path = "list.txt";
	ifstream read;




	//Функции открытия потока, подсчета вакансий и заполнения структур 
	read = read_list(path);
	countVacancy = count_vacancy(read);
	vacancy* Vacancy = new vacancy[countVacancy];
	Vacancy = fill_struct(read, countVacancy);
	
	



	//Поиск по названию
	if (!(search_vacancy(Vacancy, countVacancy))) {
		cerr << "Вакансий не было найдено!";
	}



	read.close();
	delete [] Vacancy;
	system("pause");
	return 0;
}
