#pragma once
#include "Circle.h"

class List;
class Node
{
//public:
	Node* pPrev;
	Node* pNext;
	Circle m_data;
public:
	Node();
	Node(Node *prev, const Circle *pc);
	Circle Getm_data(Circle &data);
//	Node& GetpPrev(const List& list);
//	Node& GetpNext(const List& list);
//	Node& GetNextElement(Node* prev);
	//Circle GetDataPoint(Node* prev, const Circle* pc);
	~Node();
	friend std::ostream& operator<< (std::ostream& out, const List& list);
	friend class List;
};

