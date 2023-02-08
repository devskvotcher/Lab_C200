#include "Node.h"
#include "List.h"
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
Circle Node::Getm_data(Circle& data)
{
	return this->m_data;
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

//Node& Node::GetpPrev(const List& list)
//{
//	
//	return *list.Head.pNext;
//}
//Node& Node::GetpNext(const List& list)
//{
//	return *list.Head.pNext;
//}
//
//Node& Node::GetNextElement(Node *prev)
//{
//	return *prev->pNext;
//}