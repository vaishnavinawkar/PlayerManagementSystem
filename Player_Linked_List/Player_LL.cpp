#include "Player_LL.h"
#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList() {

ifstream in("Playerdata.bin",ios_base::binary);

	start=NULL;
     //read from the file 
	//create nodes and insert data

while (!in.eof()) {
        T data;
        in.read(((char*)(&data)), sizeof(T));

        if (!in.fail()) {
            // Create a new node with the read data
            Node<T>* temp = new Node<T>(data);

            // Insert the node into the linked list
            if (start == NULL) {
                start = temp;
            } else {
                Node<T>* p = start;
                while (p->getNext() != NULL) {
                    p = p->getNext();
                }
                p->setNext(temp);
            }
        }
    }

    in.close();

}


template <class T>
void LinkedList<T>::InsertPos(T &data,int pos) {
	Node<T>* temp=new Node<T>(data);
	if(start==NULL) {
		start=temp;
		return;

	}
	if(pos==1) {
		temp->setNext(start);
		start=temp;
		return;
	}
	int i=1;
	Node<T>* p=start;
	while(i< pos-1 && p->getNext()!= NULL) {
		p=p->getNext();
		i++;
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
}


template <class T>
void LinkedList<T>::DeletePos(int pos) {
	if(start==NULL) {
		cout<<"\nNO Element to Delete.";
		return ;
	}
	Node<T>*p=start;
	if(pos==1) {
//	Node* p=start;
		start=start->getNext();
		p->getData().Display();
		cout<<"\nDeleted...";
		delete p;
		return;
	}
	int i=1;
	while(i<pos-1 && p->getNext()!=NULL) {
		p=p->getNext();
		i++;
	}
	if(i==pos-1) {
		Node<T>* q=p->getNext();
		p->setNext(q->getNext());
		q->getData().Display();
		cout<<"\nDeleted....";
		delete q;
	}

}

template <class T>
void LinkedList<T>::Display() {
	if(start==NULL) {
		cout<<"\nNo Player to Display.";
		return;
	} else {
		Node<T>*p=start;
		while(p != NULL) {
			p->getData().Display();
			p=p->getNext();
		}
	}
}

template <class T>
void LinkedList<T>::Update(int jr_no) {
	if(start==NULL) {
		cout<<"\nNo Player to Update.";
		return;
	} else {
		Node<T>*p=start;
		bool found =false;
		while(p != NULL) {

			if(jr_no == p->getData().getJersey_no()) {
				Player& p1=p->getData();
				cout<<"Player is found!";
				cout<<"\nEnter Updated Runs: ";
				int runs;
				cin>>runs;
				cout<<"\nEnter updated Wicket: ";
				int wickets;
				cin>>wickets;
				cout<<"\nEnter updated Number of matches: ";
				int no_matches;
				cin>>no_matches;

				//set runs ,wickets ,no_matches of player.
				p1.setRun(runs);
				p1.setMatches(no_matches);
				p1.setWickets(wickets);

				found=true;
			}
//			p->getData().Display();
			p=p->getNext();
//        return;
		}
		if(found == false) {
			cout<<"\nPlayer not Found!!";
			return;
		}
	}
}

template <class T>
void LinkedList<T>::Search(int jr_no,Node<T>* &np) {

	if(start==NULL) {
		cout<<"NO Player to display";
		np=NULL;
		return;
	} 
		Node<T>*p=start;
		int found=0;
		while(p != NULL) {

			if(jr_no==p->getData().getJersey_no()) {
				np=p;
				found=1;
//				return;

			}
			p=p->getNext();
		}
		if(found==1) {
				cout<<"\n---------------------------------------------------------------------------------------------------------\n";
				cout<<"|  JERSY NO.   |  PLAYER NAME                    |  Total Matches  |  Runs           |  Wickets        |\n";
				cout<<"--------------------------------------------------------------------------------------------------------\n";

				printf("| %8d     |  %-30s |  %10d     |  %10d     |  %10d     |\n", np->getData().getJersey_no(),np->getData().getName(), np->getData().getMatches(), np->getData().getRun(), np->getData().getWickets());
				cout<<"-------------------------------------------------------------------------------------------------------\n";
			}
//return;
	
}

template <class T>
void LinkedList<T>::Display_Top_3() {
    int choice;
    Node<T> *p = start;
    cout << "\nTOP 3 player:";
    cout << "\n1.RUNS";
    cout << "\n2.WICKETS";

    cout << "\n Enter the choice: ";
    cin >> choice;

    Player Top1Player;
    Player Top2Player;
    Player Top3Player;

    if (choice == 1) {
        Top1Player.setRun(-1);
        Top2Player.setRun(-1);
        Top3Player.setRun(-1);

        while (p != NULL) {
            if (p->getData().getRun() > Top1Player.getRun()) {
                Top3Player = Top2Player;
                Top2Player = Top1Player;
                Top1Player = p->getData();
            } else if (p->getData().getRun() > Top2Player.getRun()) {
                Top3Player = Top2Player;
                Top2Player = p->getData();
            } else if (p->getData().getRun() > Top3Player.getRun()) {
                Top3Player = p->getData();
            }
            p = p->getNext(); 
        }

        cout << "Display TOP 3 player having highest RUNs";
        if (Top1Player.getRun() != -1) {
            Top1Player.Display();
        }
        if (Top2Player.getRun() != -1) {
            Top2Player.Display();
        }
        if (Top3Player.getRun() != -1) {
            Top3Player.Display();
        }

    } else if (choice == 2) {
        
        Top1Player.setWickets(-1);
        Top2Player.setWickets(-1);
        Top3Player.setWickets(-1);

        while (p != NULL) {
            if (p->getData().getWickets() > Top1Player.getWickets()) {
                Top3Player = Top2Player;
                Top2Player = Top1Player;
                Top1Player = p->getData();
            } else if (p->getData().getWickets() > Top2Player.getWickets()) {
                Top3Player = Top2Player;
                Top2Player = p->getData();
            } else if (p->getData().getWickets() > Top3Player.getWickets()) {
                Top3Player = p->getData();
            }
            p = p->getNext(); 
        }

        cout << "Display TOP 3 player having highest Wickets";
        if (Top1Player.getWickets() != -1) {
            Top1Player.Display();
        }
        if (Top2Player.getWickets() != -1) {
            Top2Player.Display();
        }
        if (Top3Player.getWickets() != -1) {
            Top3Player.Display();
        }
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
	ofstream out("Playerdata.bin",ios_base::binary);
	while(start != NULL) {
		Node<T>* p=start;
		out.write(((char *)&p->getData()),sizeof(p->getData()));
		start=start->getNext();
		delete p;
	}
	out.close();
}