#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class stacks
{
private:
    string books[MAX];
    int top;

public:
    // Constructor
    stacks()
    {
        top = -1;
    }

    // Push operation - Add a book
    void push(string book)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow! No space for more books." << endl;
            return;
        }

        top++;
        books[top] = book;

        cout << book << " Book Added Successfully!" << endl;
    }

    // Pop operation - Arrange a book
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! No book to arrange." << endl;
            return;
        }

        cout << books[top] << " Arranged on the shelf." << endl;
        top--;
    }

    // Peek operation - View top book
    void Peek()
    {
        if (top == -1)
        {
            cout << "There are no books on the shelf." << endl;
            return;
        }

        cout << "Top Book: " << books[top] << endl;
    }

    // Display all books
    void display()
    {
        if (top == -1)
        {
            cout << "No books available in the stack." << endl;
            return;
        }

        cout << "\nBooks in the stack are:\n";

        for (int i = top; i >= 0; i--)
        {
            cout << books[i] << endl;
        }
    }
};

// Main function
int main()
{
    string book;
    stacks s;
    int choice;

    do
    {
        cout << "\n======== Library Stack Menu ========" << endl;
        cout << "1. Return Book" << endl;
        cout << "2. Arrange Book" << endl;
        cout << "3. See Top Book" << endl;
        cout << "4. Display All Books" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your Choice: ";
        cin >> choice;

        cin.ignore(10000, '\n');

        switch (choice)
        {
            case 1:
                cout << "Enter Book Name: ";
                getline(cin, book);
                s.push(book);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.Peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Input! Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
