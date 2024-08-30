#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// REIVEN O. JASA
// 1. Add books (with title, author, and year)
// 2. Display all books
// 3. Search for a book by title/author/year
// 4. Implement a menu for user interaction
// 5. Push your code to GitHub.

// will store information about each book.
// setting the books details (constructor / setter methods)
// getting the books details
// displaying the books details
class Book
{
    private:
        std::string title;
        std::string author;
        int year;

    public:
        // Constructor / setter methods
        Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {}

        // Getters
        std::string getTitle() const { return title; }
        std::string getAuthor() const { return author; }
        int getYear() const { return year; }

        // Display function
        void displayBook() const
        {
            cout << title;
            cout << "\t" << author;
            cout << "\t" << year << endl;
        }
};

// to manage the collection of books
// vector (or another container) to store the 'Book' objects.
// functions to add books, display all books, and search for books by title.
// to display the books in alphabetical order by title
class Library
{
    private:
        vector<Book> books;

    public:
        void addBook(const Book& book)
        {
            books.push_back(book);
            cout << "Book added successfully!" << endl;
        }

        void displayBooks() const
        {
            if (books.empty())
            {
                cout << "No books available!" << endl;
                return;
            }

            // Create a copy of the books vector to sort it without affecting the original order
            vector<Book> sortedBooks = books;
        
            // Sort the books by year
            sort(sortedBooks.begin(), sortedBooks.end(), [](const Book& a, const Book& b)
            {
                return a.getYear() < b.getYear();
            });

            cout << "\nList of Books:" << endl;
            cout << "Title\t\tAuthor\tYear" << endl;
            cout << "----------------------------------------------" << endl;
            for (const auto& book : sortedBooks)
            {
                book.displayBook();
            }
            cout << endl;
        }

        void searchBook(const std::string& title) const
        {
            if (title.empty())
            {
                cout << "Search query cannot be empty." << endl;
                return;
            }
            bool found = false;
            cout << "\nSearch Results:" << endl;
            cout << "Title\t\tAuthor\tYear" << endl;
            cout << "----------------------------------------------" << endl;
            for (const auto& book : books)
            {
                if (book.getTitle() == title)
                {
                    book.displayBook();
                    found = true;
                }
            }
            if (!found)
            {
                cout << "No books found with the title \"" << title << "\"." << endl;
            }
            cout << endl;
        }
};

int main()
{
    Library library;
    int choice;
    std::string input;
    int year;

    do
    {
        cout << "\nMenu\n";
        cout << "1 - Add Book\n";
        cout << "2 - Display Books\n";
        cout << "3 - Search Books\n";
        cout << "4 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Validate user choice
        if (choice < 1 || choice > 4)
        {
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                cout << "\nEnter title: ";
                getline(cin, input);
                if (input.empty())
                {
                    cout << "Title cannot be empty." << endl;
                    break;
                }
                string title = input;

                cout << "Enter author: ";
                getline(cin, input);
                if (input.empty())
                {
                    cout << "Author cannot be empty." << endl;
                    break;
                }
                string author = input;

                cout << "Enter year: ";
                while (!(cin >> year) || year < 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter a valid year: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                library.addBook(Book(title, author, year));
                break;
            }
            case 2:
                library.displayBooks();
                break;

            case 3:
            {
                cout << "\nEnter the title to search: ";
                getline(cin, input);
                library.searchBook(input);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
    while (choice != 4);

    return 0;
}