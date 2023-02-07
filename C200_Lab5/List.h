#pragma once
#include "Node.h"
class List
{
protected:
	Node Head;
	Node Tail;
	size_t m_size;
public:
	List();
	List(List&& other);
	List(const List&& other);
	void push_front(const Circle* pc);
	void push_back(const Circle& pc);
	bool RemoveOne(const Circle& pc);
	~List();
	//std::ostream& operator<< (std::ostream& out);
	friend std::ofstream& operator<< (std::ofstream& out, const List& list);
	friend std::ifstream& operator>> (std::ifstream& in, List& list);
	friend class Node;
};

