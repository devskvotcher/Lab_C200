#include "List.h"
#include "Node.h"
#include <string>
#include <sstream>
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
bool List::RemoveAll(const Circle& pc)
{
	int tmp = m_size;
	Node* p = Head.pNext;
	while (p != &Tail)
	{
		if (p->m_data == pc)   //Нужно перегрузить оператор на равенство в классе Circle
		{
			m_size--;
			p = p->pNext;
			delete p->pPrev;			
		}
		else
		{
			p = p->pNext;
		}
	}
	if (tmp>m_size)
	{
		return true;
	}
	else
	{
		return false;
	}	
}
void List::sort()
{
	Node* pT = &Tail;
	Node* p = Head.pNext;
	Node* max = nullptr;

	for (size_t i = m_size-1; i > 0; i--)
	{
		float MAX_area = 0;
			while (p != pT)
			{
				float area = 3.14*pow(p->m_data.GetR(),2);
				
				if (area > MAX_area)
				{
					MAX_area = area;
					max = p;
				}
				p = p->pNext;
			}
			Circle tmp = max->m_data;
			max->m_data = pT->pPrev->m_data;
			pT->pPrev->m_data = tmp;
			p = Head.pNext;

			pT = pT->pPrev;
	}
}
//Оно все равно не работает, однако хоть ошибок не возникает, если сделать поля всех классов public))
//Но вряд ли это хорошо
std::ostream& operator<< (std::ostream& out, const List &list)
{
	Node* p = list.Head.pNext;
	if (p == &list.Tail)
	{
		out << "Список пуст" << std::endl;
	}
	while (p != &list.Tail)
	{
		//out << p->m_data.Circle::GetX() << " " << p->m_data.Circle::GetY() << p->m_data.Circle::GetR();
		out << p->m_data;
		p = p->pNext;
	}

	return out;
}
void WriteFile(const List& list)
{
	std::string filename;
	std::cout << "Введите название файла=";
	std::cin >> filename;
	std::ofstream file(filename,std::ios::out);
	if (file.is_open())
	{
		//file << list.m_size << std::endl;
		Node* p = list.Head.pNext;

		while (p != &list.Tail)
		{
			file << p->m_data;
			p = p->pNext;
		}		
		file.close();
	}
	else
	{
		std::cout << "Неудачное открытие файла" << std::endl;
	}
}

std::istream& operator>> (std::istream& in, List& list)
{
	int x, y, r;
	std::cout << "Введите координату х точки=";
	in >> x;
	std::cout << "\nВведите координату y точки=";
	in >> y;
	std::cout << "\nВведите радиус круга=";
	in >> r;
	Point tmp1(x, y);
	//Circle* tmp = new Circle(tmp1, r);
	//list.push_back(*tmp);
	list.push_back(Circle(Point(x,y),r));
	std::cout << "\nОбъект успешно добавлен в список\n";
	return in;
}

List& ReadFromFile(List& list)
{

	std::string name_file;
	std::cout << "Введите имя входного текстового файла, содержащего текст для анализа: ";
	//getline(std::cin, name_file);
	std::cin >> name_file;
	std::ifstream fin(name_file, std::ios_base::in);
	if (fin.is_open())
	{
		std::string line;
		int x = 0;
		int y = 0;
		int r = 0;
		while (!fin.eof())
		{
			getline(fin, line);
			std::stringstream in(line);

			while (in >> x >> y >> r)
			{
				list.push_back(Circle(Point(x, y), r));
			}
		}
		fin.close();
		return list;
	}
}
void Clean(List& list)
{
	while (list.Head.pNext != &list.Tail)
	{
		delete list.Head.pNext;
	}
	std::cout << "Список очищен от значений" << std::endl;
}

//Разобраться как передать и получить дата и тогда доделать методы
//поиска
//Node List::GetHead(const List& list)
//{
//	return list.Head;
//}
//Node List::GetTail(const List& list)
//{
//	return list.Tail;
//}

