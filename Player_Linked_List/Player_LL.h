//declaration of linkedlist

#include "Player_node.cpp"
#include <string.h>

template<class T>
class LinkedList {
		Node<T>* start;

	public:
		LinkedList();
		void InsertPos(T &,int);
		void DeletePos(int);
		void Display();
	    void Update(int);
	    void Search(int,Node<T>* &);
	    void Display_Top_3();
		~LinkedList();
};
