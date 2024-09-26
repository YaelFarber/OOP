#pragma once

//--------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//--------------------------------------
class List
{
protected:
	//---------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//---------------------------------------
	class Link
	{
	public:
		// data areas
		int value;
		Link* next;
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
	};	//end of class Link

public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);
	int firstElement() const;
	bool isEmpty() const;
	void removeFirst();
	void clear();

protected:
	// data field
	Link* head;
};

