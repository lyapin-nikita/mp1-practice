#include "function.h"


void random_vacancy(info* Infostruct) {
	srand(time(NULL));
	int a = rand() % 5;
	int b = rand() % 4;
	int c = rand() % 3;
	strcpy(Infostruct->name1, corporation[a]);//Не присваивается значение 
	strcpy(Infostruct->employee1, employee[b]);
	strcpy(Infostruct->working_conditions1, working_conditions[c]);
	//Infostruct->working_conditions1 = working_conditions[1];
}

void inference(info Infostruct) {

}
/*
info* search() {
	
}
*/