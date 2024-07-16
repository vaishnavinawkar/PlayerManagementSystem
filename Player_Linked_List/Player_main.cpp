#include "Player_LL.cpp"
#include "Player.h"
#include <iostream>
#include <fstream>

int main() {
	int choice=0;
	LinkedList<Player> l1;

	while(choice != 7) {

	cout << "+---------------------------------------+" << endl;
    cout << "|               MENU                    |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| Option |          Description         |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "|   1    | Insert Player at Position    |" << endl;
    cout << "|   2    | Delete Player from Position  |" << endl;
    cout << "|   3    | Update Players               |" << endl;
    cout << "|   4    | Search Players               |" << endl;
    cout << "|   5    | Display Top 3 Players        |" << endl;
    cout << "|   6    | Display Players              |" << endl;
    cout << "|   7    | Exit                         |" << endl;
    cout << "+---------------------------------------+" << endl;

		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice) {


			case 1: {
				int jersey_no;
				char name[30];
				int runs;
				int wickets;
				int no_matches;
				cout<<"\nEnter jersery_no: ";
				cin>>jersey_no;
				cout<<"\nEnter Name : ";
				cin>>name;
				cout<<"\nEnter Runs: ";
				cin>>runs;
				cout<<"\nEnter Wickets : ";
				cin>>wickets;
				cout<<"\nEnter Number of matches: ";
				cin>>no_matches;

				Player p(jersey_no,name,runs,wickets,no_matches);
				int pos;
				cout<<"\nEnter position: ";
				cin>>pos;
				l1.InsertPos(p,pos);
				break;
			}
			case 2: {
				int pos;
				cout<<"\nEnter position: ";
				cin>>pos;
				l1.DeletePos(pos);
				break;
			}
			case 3: {
				int jr_no;
				cout<<"Enter the palyer jersey number you want to update: ";
				cin>>jr_no;
				l1.Update(jr_no);
				break;
			}
			case 4: {
				int jr_no;
				cout<<"\nEnter Jersery number you want to search: ";
				cin>>jr_no;
				Node<Player>* p=NULL;
				l1.Search(jr_no,p);
				break;
			}
			case 5:{
				l1.Display_Top_3();
				break;
			}
			case 6: {
				l1.Display();
				break;
			}
			case 7: {
				cout<<"\nEnd of Program";
				break;
			}
			default: {
				cout<<"\nInvalid choice!!";
				cout<<"\nEnter valid Choice";
				break;
			}

		}
	}
	return 0;
}