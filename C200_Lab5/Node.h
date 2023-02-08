#pragma once
#include "Circle.h"
class Node
{
public:
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
	friend class List;
};

