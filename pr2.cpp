#include<iostream>
using namespace std;

class Train
{
    int no;
    string name, source, destination, time;

public:
    void input()
    {
        cout << "Enter Train Number: ";
        cin >> no;
        cin.ignore();

        cout << "Enter Train Name: ";
        getline(cin, name);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Train Time: ";
        getline(cin, time);
    }

    void display()
    {
        cout << "\nTrain Number : " << no << endl;
        cout << "Train Name   : " << name << endl;
        cout << "Source       : " << source << endl;
        cout << "Destination  : " << destination << endl;
        cout << "Train Time   : " << time << endl;
    }

    int getNo()
    {
    	
	}    
};

int main()
{
    Train t[100];
    int total = 0, choice, num;
    bool found;
    
    cout << "Enter Details of 3 Trains:\n";
    for(int i = 0; i < 3; i++)
    {
        cout << "\nTrain " << i + 1 << endl;
        t[total].input();
        total++;
    }

    do
    {
        cout << "\n===== Railway Reservation System =====\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                t[total].input();
                total++;
                break;

            case 2:
                if(total == 0)
                {
                    cout << "No Train Records Available!\n";
                }
                else
                {
                    for(int i = 0; i < total; i++)
                    {
                        cout << "\nTrain " << i + 1 << " Details:";
                        t[i].display();
                    }
                }
                break;

            case 3:
                cout << "Enter Train Number to Search: ";
                cin >> num;
                found = false;

                for(int i = 0; i < total; i++)
                {
                    if(t[i].getNo() == num)
                    {
                        t[i].display();
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "Train Not Found!\n";
                }

            case 4:
                cout << "Exiting the System. Goodbye!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }
        
    } while(choice != 4);
}

/*output

===== Railway Reservation System =====
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter Your Choice: 1
Enter Train Number: 101
Enter Train Name: Okha Express
Enter Source: Surat
Enter Destination: Mumbai
Enter Train Time: 10 AM

===== Railway Reservation System =====
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter Your Choice: 2

Train 1 Details:
Train Number : 101
Train Name   : Okha Express
Source       : Surat
Destination  : Mumbai
Train Time   : 10 AM

Train 2 Details:
Train Number : 102
Train Name   : Okha Express
Source       : Surat
Destination  : Surat
Train Time   : 10 AM

Train 3 Details:
Train Number : 103
Train Name   : Okha Express
Source       : Surat
Destination  : Mumbai
Train Time   : 10 AM

Train 4 Details:
Train Number : 101
Train Name   : Okha Express
Source       : Surat
Destination  : Mumbai
Train Time   : 10 AM

===== Railway Reservation System =====
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter Your Choice: 3
Enter Train Number to Search: 103
Train Not Found!
Exiting the System. Goodbye!

===== Railway Reservation System =====
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter Your Choice: 3
Enter Train Number to Search: 104
Train Not Found!
Exiting the System. Goodbye!

===== Railway Reservation System =====
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter Your Choice: 4
Exiting the System. Goodbye!
*/