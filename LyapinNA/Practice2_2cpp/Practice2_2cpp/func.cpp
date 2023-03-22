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