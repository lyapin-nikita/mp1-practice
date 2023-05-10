#include "func.h"

int main() {
	system("chcp 1251");
	  	
	string path;
	path = input_path();

	try
	{
		vacancyLib VacancyBase(path);
		vacancyLib srchVacancy = VacancyBase.search_vacancy();

		if (srchVacancy.countVacancy == 0) {
			cerr << "�������� �� ���� �������!";
			return 1;
		}
	
		cout << "\n�� ����� �������� �� ������ �������:" << "\n\n";
		cout << srchVacancy << endl;
	}
	catch (const int ex) 
	{
		cout << "���� ��� ������ ������� ��� ����� �� ����������!" << endl;
		return 1;			
	}
	


	system("pause");
	return 0;
}
