#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
    }

    int getId() const {
        return id;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    void display() const {
        cout << "ID: " << id << " | Title: " << title << " | Author: " << author << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        Book newBook(id, title, author);
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "Library is empty.\n";
            return;
        }
        cout << "\n--- Book List ---\n";
        int counter = 1;  // عداد الكتب
        for (const Book& b : books) {
            cout << counter << ". ";  // رقم الكتاب
            b.display();
            counter++;  // زيادة العداد بعد كل كتاب
        }
    }

    void searchBook() {
        cout << "Search by (1) Title or (2) ID: ";
        int option;
        cin >> option;
        cin.ignore();

        if (option == 1) {
            // البحث بالاسم
            string keyword;
            cout << "Enter book title to search: ";
            getline(cin, keyword);

            bool found = false;
            for (const Book& b : books) {
                if (b.getTitle() == keyword) {
                    b.display();
                    found = true;
                }
            }

            if (!found) {
                cout << "Book not found.\n";
            }
        } else if (option == 2) {
            // البحث بالـ ID
            int id;
            cout << "Enter book ID to search: ";
            cin >> id;

            bool found = false;
            for (const Book& b : books) {
                if (b.getId() == id) {
                    b.display();
                    found = true;
                }
            }

            if (!found) {
                cout << "Book not found.\n";
            }
        } else {
            cout << "Invalid option! Please select 1 or 2.\n";
        }
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Book deleted successfully.\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.deleteBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option!\n";
        }

    } while (choice != 5);

    return 0;
}
