#include "List.h"
#include "Node.h"

List::List():m_size(0)
{
	Head.pNext = &Tail;
	Head.pPrev = nullptr; //Можно не указывать
	Tail.pNext = nullptr;
	Tail.pPrev = &Head;
	m_size = 0;
}
List::List(const List&& other) :m_size(other.m_size)   //конструктор копирования
{
	//Подготовка к копированию
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	//Копирование
	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;
	for (size_t i = 0; i < m_size; i++)
	{
	//	pThis = new Node(pThis, pOther->m_data);  //Очень странно, ведь конструктор в классе Node реализован верно
		pOther = pOther->pNext;					  //Должен принимать указатель на предыдущий элемент и данные
	}											//Чего ругается не пойму
}
List::List(List&& other) :m_size(other.m_size)    //Move конструктор копирования
{
	Head.pNext = other.Head.pNext;
	Tail.pPrev = other.Tail.pPrev;
	Head.pNext->pPrev = &Head;
	Tail.pPrev->pNext = &Tail;
	other.Head.pNext = &other.Tail;
	other.Tail.pPrev = &other.Head;
	other.m_size = 0;
}
List::~List()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
}

void List::push_front(const Circle *pc)
{
	Node* ptr = new Node(&Head,pc);    
	this->m_size++;
}

void List::push_back(const Circle& pc)
{
	
	Node* ptr = new Node(Tail.pPrev, &pc);   
	this->m_size++;
}
bool List::RemoveOne(const Circle& pc)
{
	Node* p = Head.pNext;
	while (p != &Tail)
	{
		if (p->m_data == pc)   //Нужно перегрузить оператор на равенство в классе Circle
		{
			m_size--;
			delete p;
			return true;
		}
		p = p->pNext;

	}
	return false;
}
//std::ostream& List::operator<< (std::ostream& out)
//{
//	Node* p = Head.pNext;	
//	
//	while (p != &Tail)
//	{
//		out << p->m_data.Circle::GetX()<<" "<< p->m_data.Circle::GetY()<< p->m_data.Circle::GetR();
//		p=p->pNext;
//	}
//	
//	return out;
//}
//Оно все равно не работает, однако хоть ошибок не возникает, если сделать поля всех классов public))
//Но вряд ли это хорошо
std::ostream& operator<< (std::ostream& out, const List &list)
{
	Node* p = list.Head.pNext;

	while (p != &list.Tail)
	{
		//out << p->m_data.Circle::GetX() << " " << p->m_data.Circle::GetY() << p->m_data.Circle::GetR();
		out << p->m_data;
		p = p->pNext;
	}

	return out;
}
//std::ifstream& operator>> (std::ifstream& in, List& list)
//
//	in >> list;
//	return in;
//
//Разобраться как передать и получить дата и тогда доделать методы
//поиска
