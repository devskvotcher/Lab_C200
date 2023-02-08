#pragma once
#include "Node.h"
class List
{
public:
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
	bool RemoveAll(const Circle& pc);
	void sort();
	~List();
	//std::ostream& operator<< (std::ostream& out);
//	Node GetHead(const List& list);
//	Node GetTail(const List& list);
	friend std::ostream& operator<< (std::ostream& out, const List& list);
	friend std::istream& operator>> (std::istream& in, List& list);
	friend void WriteFile(const List& list);
	friend List& ReadFromFile(List& list);
	friend class Node;
};

