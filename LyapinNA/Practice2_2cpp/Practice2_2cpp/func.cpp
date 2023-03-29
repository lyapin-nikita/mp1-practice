#include "func.h"





//������� �������� ������ ��� ������
ifstream read_list(string path) {
	ifstream read(path);

	if (!read)
		cerr << "��������� ������ ��� �������� ����� ��� ������!" << endl;
	else
		cout << "����� ��� ������� ������!" << endl;

	return read;
}





int count_vacancy(ifstream& read) {
	string line;
	int count = 0, countVacancy = 0;

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

	return countVacancy;
}





vacancy* fill_struct(ifstream& read, int countVacancy) {
	vacancy* Vacancy = new vacancy[countVacancy];

	read.clear();
	read.seekg(0);
	int i = 0;
	for (; i < countVacancy; i++) {
		getline(read, Vacancy[i].employee);
		getline(read, Vacancy[i].nameCompany);
		getline(read, Vacancy[i].salary);
		getline(read, Vacancy[i].workCond);
		getline(read, Vacancy[i].request);
	}

	return Vacancy;
}





int search_vacancy(vacancy* Vacancy, int countVacancy) {
	int j = 0, k = 0;
	string search;
	int* index = new int[countVacancy];
	cout << "������� �������� ���������, ������� �� �����: " << endl;
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
	cout << "\n�� ����� �������� (" << countSearchedVacancy << "��) �� ������ �������:" << "\n\n";
	for (j = 0; (indexes[j] != -1) && (j < countVacancy); j++) {
		cout << "\n-----------------------------------\n";
		cout << "���������: " << Vacancy[indexes[j]].employee << endl;
		cout << "�������� ��������: " << Vacancy[indexes[j]].nameCompany << endl;
		cout << "��������: " << Vacancy[indexes[j]].salary << endl;
		cout << "������� �����: " << Vacancy[indexes[j]].workCond << endl;
		cout << "���������� � ����������: " << Vacancy[indexes[j]].request << endl;
	}
		
}