//#include "Player.h"

//#include <iostream>
//using namespace std;
template <class T>
class Node {
//	Player data;
		T data;
		Node* next;

	public:
//		Node(Player &);
//		void setData(Player &);
//		void setNext(Node*);
//		Player& getData();
//		Node* getNext();

		Node( T &);
		void setData(T &);
		void setNext(Node*);
		T& getData();
		Node* getNext();

};