#include "func.h"

int main() {
	system("chcp 1251");
	  


	int countVacancy = 0;
	string path = "list.txt";
	ifstream read;




	//������� �������� ������, �������� �������� � ���������� �������� 
	read = read_list(path);
	countVacancy = count_vacancy(read);
	vacancy* Vacancy = new vacancy[countVacancy];
	Vacancy = fill_struct(read, countVacancy);
	
	



	//����� �� ��������
	if (!(search_vacancy(Vacancy, countVacancy))) {
		cerr << "�������� �� ���� �������!";
	}



	read.close();
	delete [] Vacancy;
	system("pause");
	return 0;
}
