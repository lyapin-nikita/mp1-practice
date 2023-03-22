#include "func.h"

int main() {
	system("chcp 1251");
	  


	int count = 0, countVacancy = 0;
	string line;
	string path = "D:\\project_programming\\project_vs19\\homework\\Pracitce2_2cpp\\Pracitce2_2cpp\\list.txt";
	ifstream read;



	//������� �������� ������ 
	read = read_list(path);
	//����� ���������� �����
	while (getline(read, line))
		++count;


	//����������� ����� ��������
	countVacancy = count / N;
	if (countVacancy == 0) {
		cerr << "Error: ����� �������� �� ����� ���� ������ 0!";
		return 1;
	}
	else
		cout << "����� ��������� ��������: " << countVacancy << endl;



	vacancy* Vacancy = new vacancy[countVacancy];
	
	//���������� ������� ��������
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
	//����� �� ��������
	if (!(search_vacancy(Vacancy, countVacancy))) {
		cerr << "�������� �� ���� �������!";
	}



	read.close();
	delete [] Vacancy;
	return 0;
}
