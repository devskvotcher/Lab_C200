#include "Node.h"
Node::Node()
{
	this->pPrev = this->pNext = nullptr;
}
Node::Node(Node *prev, const Circle* pc):m_data(*pc)
{
	pPrev = prev;
	pNext = pPrev->pNext;
	pPrev->pNext = this;
	pNext->pPrev = this;	
}
Point Node::GetDataPoint(Circle& data)
{
	return data.point;
	//return Circle::pc.GetX();
}
Node::~Node()
{
	if (pNext != 0)
	{
		pNext->pPrev = pPrev;
	}
	if (pPrev != 0)
	{
		pPrev->pNext = pNext;
	}
}