#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char *auth;
    char *titl;
    float prc;
    char *pub;
    int stk;

public:
    Book(const char* a, const char* t, float p, const char* u, int s) {
        auth = new char[strlen(a) + 1];
        strcpy(auth, a);

        titl = new char[strlen(t) + 1];
        strcpy(titl, t);

        prc = p;

        pub = new char[strlen(u) + 1];
        strcpy(pub, u);

        stk = s;
    }

    ~Book() {
        delete[] auth;
        delete[] titl;
        delete[] pub;
    }

    void displayBookDetails() const {
        cout << "Title: " << titl << endl;
        cout << "Author: " << auth << endl;
        cout << "Publisher: " << pub << endl;
        cout << "Price: " << prc << endl;
        cout << "Stock: " << stk << endl;
    }

    bool isMatch(const char* t, const char* a) const {
        return (strcmp(titl, t) == 0) && (strcmp(auth, a) == 0);
    }

    bool checkStockAndCalculateCost(int reqCopies, float& totalCost) const {
        if (stk >= reqCopies) {
            totalCost = reqCopies * prc;
            return true;
        } else {
            return false;
        }
    }

    void updateStock(int soldCopies) {
        stk -= soldCopies;
    }
};

class BookShop {
private:
    Book **inv;
    int totalBooks;

public:
    BookShop(int numBooks) {
        totalBooks = numBooks;
        inv = new Book*[totalBooks];
    }

    ~BookShop() {
        for (int i = 0; i < totalBooks; ++i) {
            delete inv[i];
        }
        delete[] inv;
    }

    void addBook(int idx, const char* a, const char* t, float p, const char* u, int s) {
        inv[idx] = new Book(a, t, p, u, s);
    }

    void searchBook(const char* t, const char* a) {
        bool found = false;
        for (int i = 0; i < totalBooks; ++i) {
            if (inv[i]->isMatch(t, a)) {
                found = true;
                inv[i]->displayBookDetails();
                int reqCopies;
                cout << "Enter the number of copies required: ";
                cin >> reqCopies;
                float totalCost;
                if (inv[i]->checkStockAndCalculateCost(reqCopies, totalCost)) {
                    cout << "Total cost for " << reqCopies << " copies: " << totalCost << endl;
                    inv[i]->updateStock(reqCopies);
                } else {
                    cout << "Required copies not in stock." << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "Book not found in the inventory." << endl;
        }
    }
};
int main() {
    BookShop shop(3);

    shop.addBook(0, "J.K. Rowling", "Harry Potter", 15.99, "Bloomsbury", 10);
    shop.addBook(1, "George Orwell", "1984", 12.99, "Secker & Warburg", 5);
    shop.addBook(2, "J.R.R. Tolkien", "The Hobbit", 10.99, "HarperCollins", 7);

    char titl[100], auth[100];
    cout << "Enter the title of the book: ";
    cin.ignore();
    cin.getline(titl, 100);
    cout << "Enter the author of the book: ";
    cin.getline(auth, 100);

    shop.searchBook(titl, auth);

    return 0;
}

