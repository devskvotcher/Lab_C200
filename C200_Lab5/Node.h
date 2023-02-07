#pragma once
#include "Circle.h"
class Node
{
protected:
	Node* pPrev;
	Node* pNext;
	Circle m_data;
public:
	Node();
	Node(Node *prev, const Circle *pc);
	Point GetDataPoint(Circle &data);
	//Circle GetDataPoint(Node* prev, const Circle* pc);
	~Node();
	friend class List;
};

