#include "List.h"
#include "Node.h"

List::List():m_size(0)
{
	Head.pNext = &Tail;
	Head.pPrev = nullptr; //����� �� ���������
	Tail.pNext = nullptr;
	Tail.pPrev = &Head;
	m_size = 0;
}
List::List(const List&& other) :m_size(other.m_size)   //����������� �����������
{
	//���������� � �����������
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	//�����������
	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		//pThis = new Node(pThis, pOther->m_data);
		pOther = pOther->pNext;
	}
}
List::List(List&& other) :m_size(other.m_size)    //Move ����������� �����������
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
		//if (p->m_data == pc)   //����� ����������� �������� �� ��������� � ������ Circle
		//{
		//	m_size--;
		//	delete p;
		//	return true;
		//}
		//p = p->pNext;

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
//��� ��� ����� �� ��������, ������ ���� ������ �� ���������, ���� ������� ���� ���� ������� public))
//�� ���� �� ��� ������
//std::ostream& operator<< (std::ostream& out, const List &list)
//{
//	Node* p = list.Head.pNext;
//
//	while (p != &list.Tail)
//	{
//		//out << p->m_data.Circle::GetX() << " " << p->m_data.Circle::GetY() << p->m_data.Circle::GetR();
//		out << p->m_data;
//		p = p->pNext;
//	}
//
//	return out;
//}
std::ifstream& operator>> (std::ifstream& in, List& list)
{
	in >> list;
	return in;
}
//����������� ��� �������� � �������� ���� � ����� �������� ������
//������
