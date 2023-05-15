//Товарный чек содержит список товаров, полученных при покупке в магазине. Один элемент - class товар, колво товаров и сумма.
//Товар - класс с полями название, цена и код товара.
//Для создания товарного чека используется также класс с полями номер чека, дата и время создания, список товаров.
//В классе реализовать методы добавления, удаления и изменения, метод поиска товара по его коду, а также метод подсчета общей суммы чека.
//Методы добавления и изменения принмиает обьект класса товар, метод поиска возвращает обьект класса товар.



#include "stdafx.h"

template <typename T>
class test_list
{
private:
	
	//one element
	template <typename T>
	struct node
	{
		node* node_next;
		T data;
		//constructor
		node(T data = T(), node* node_next = nullptr)
		{
			this->data = data;
			this->node_next = node_next;
		}
	};


	node<T>* Head;
	int size; 

public:


	test_list();
	~test_list();

	void push_back(T data);
	void push_front(T data);
	void push_indexN(T data, int ind);
	void push_indexE(T data, int ind);
	void pop_back();
	void pop_front();
	void pop_index(int ind);
	int get_size();
	void output_elements();
	void clear();

	T& operator [](const int index);
	
};



int main(void) {
	system("chcp 1251");

	Ctime test1;
	cout << test1 << endl;

	CData test2;
	cout << test2 << endl;

	Creceipt test3;
	Creceipt test4;
	Creceipt test5;
	cout << test3.sum << endl; //3

	test_list<Ctime> test6;
	cout << test6.get_size() << endl;
	test6.push_back(test1);
	test6.output_elements();

	return 0;
}


template<typename T>
test_list<T>::test_list()
{
	size = 0;
	Head = nullptr;
}

template<typename T>
test_list<T>::~test_list()
{
	clear();
}

template<typename T>
void test_list<T>::push_back(T data)
{
	if (Head == nullptr) 
	{
		Head = new node<T>(data);
	}
	else 
	{
		node<T>* Current = this->Head;
		while (Current->node_next != nullptr) Current = Current->node_next;
		Current->node_next = new node<T>(data);
	}
	size++;
}

template<typename T>
void test_list<T>::push_front(T data)
{
	if (Head == nullptr) Head = new node<T>(data);	
	else Head = new node<T>(data, Head);
	size++;
}

template<typename T>
void test_list<T>::push_indexN(T data, int ind)
{
	if ((ind < 0) || (ind >= size)) throw - 1;
	if (Head == nullptr) Head = new node<T>(data);
	else
	{
		int i = 0;
		node<T>* Current = this->Head;
		node<T>* New_Node = new node<T>(data);
		for (; (i != ind); i++)
		{
			Current = Current->node_next;
		}
		New_Node->node_next = Current->node_next;
		Current->node_next = New_Node;
	}
	size++;
}

template<typename T>
void test_list<T>::push_indexE(T data, int ind)
{
	if ((ind < 0) || (ind > size)) throw - 1;
	if (Head == nullptr) Head = new node<T>(data);
	else 
	{
		if (ind == 0)
		{
			node<T>* New_Node = new node<T>(data);
			New_Node->node_next = Head;
			Head = New_Node;
		}
		else
		{
			
			int i = 0;
			node<T>* Current = this->Head;
			node<T>* New_Node = new node<T>(data);
			for (; (i != ind - 1); i++)
			{
				Current = Current->node_next;
			}
			New_Node->node_next = Current->node_next;
			Current->node_next = New_Node;
			
		}
	}
	size++;
}

template<typename T>
void test_list<T>::pop_back()
{
	if (Head == nullptr) throw - 2;
	if (Head->node_next == nullptr) 
	{
		Head = nullptr;
		delete Head;
	}
	else
	{
		node<T>* Current = this->Head;
		while (Current->node_next->node_next != nullptr) Current = Current->node_next;
		Current->node_next = nullptr;
		delete Current->node_next;
	}
	size--;
}

template<typename T>
void test_list<T>::pop_front()
{
	if (Head == nullptr) throw - 2;
	node<T>* Current = this->Head;
	Head = Head->node_next;
	delete Current;
	size--;
}

template<typename T>
void test_list<T>::pop_index(int ind)
{
	int i = 0;
	if ((ind < 0) || (ind >= size)) throw - 1;
	node<T>* Current = this->Head;
	for (; (i != ind-1); i++)
	{
		Current = Current->node_next;
	}
	node<T>* Delete_Node = Current->node_next;
	Current->node_next = Current->node_next->node_next;
	delete Delete_Node;
	size--;
}

template<typename T>
int test_list<T>::get_size()
{
	return this->size;
}

template<typename T>
void test_list<T>::output_elements()
{
	node<T>* Current = this->Head;
	for (int count = 0; count < size; count++)
	{
		cout << Current->data << "  ";
		Current = Current->node_next;
	}
	cout << endl;
}

template<typename T>
void test_list<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
T& test_list<T>::operator[](const int index)
{
	if ((index >= size) || (index < 0)) throw -1;

	int count = 0;
	node<T>* Current = this->Head;
	for (; count != index; count++) Current = Current->node_next;
	return Current->data;
}