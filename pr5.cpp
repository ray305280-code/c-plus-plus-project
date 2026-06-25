#include <iostream>
using namespace std;

class LibraryItem {
private:
    string title, author, dueDate;

public:
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
public:
    Book(string t, string a, string d)
        : LibraryItem(t, a, d) {}

    void checkOut() override {
        cout << "Book Checked Out\n";
    }

    void returnItem() override {
        cout << "Book Returned\n";
    }

    void displayDetails() override {
        cout << "Book: " << getTitle()
             << " | Author: " << getAuthor()
             << " | Due: " << getDueDate() << endl;
    }
};

int main() {
    LibraryItem* items[5];
    int count = 0, choice;

    do {
        cout << "\n1.Add Book\n2.Display\n3.Check Out\n4.Return\n5.Exit\nChoice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                string title, author, due;
                cout << "Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "Due Date: ";
                getline(cin, due);

                if (title.empty())
                    throw "Invalid Title!";

                items[count++] = new Book(title, author, due);
                cout << "Book Added\n";
                break;
            }

            case 2:
                for (int i = 0; i < count; i++)
                    items[i]->displayDetails();
                break;

            case 3:
                if (count > 0) items[0]->checkOut();
                break;

            case 4:
                if (count > 0) items[0]->returnItem();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                throw "Invalid Choice!";
            }
        }
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
        catch (...) {
            cout << "Unknown Error!\n";
        }

    } while (choice != 5);

    for (int i = 0; i < count; i++)
        delete items[i];
}

/*ouput

1.Add Book
2.Display
3.Check Out
4.Return
5.Exit
Choice: 1
Title: the Guide
Author: RK Narayan
Due Date: 9 july 2026
Book Added

1.Add Book
2.Display
3.Check Out
4.Return
5.Exit
Choice: 2
Book: the Guide | Author: RK Narayan | Due: 9 july 2026

1.Add Book
2.Display
3.Check Out
4.Return
5.Exit
Choice: 3
Book Checked Out

1.Add Book
2.Display
3.Check Out
4.Return
5.Exit
Choice: 4
Book Returned

1.Add Book
2.Display
3.Check Out
4.Return
5.Exit
Choice: 5
Exiting...
*/
