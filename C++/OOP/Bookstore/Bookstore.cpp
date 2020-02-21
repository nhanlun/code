#include "Bookstore.h"

Book::Book()
{
    using std::cout;
    using std::cin;
    char buffer[1000];

    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter title: ";
    cin.ignore(1000, '\n');
    cin.get(buffer, 1000, '\n');
    int size = strlen(buffer) + 1;
    title = new char[size];
    strcpy(title, buffer);

    cout << "Enter price: ";
    cin >> price;

}

Book::Book(int ID, char *title, double price)
{
    this->ID = ID;
    int size = strlen(title) + 1;
    this->title = new char[size];
    for (int i = 0; i < size; ++i)
        this->title[i] = title[i];
    this->price = price;
}

Book::~Book()
{
    delete[] title;
}

Book::Book(const Book &x)
{
    ID = x.ID;
    price = x.price;
    int size = strlen(x.title) + 1;
    title = new char[size];
    for (int i = 0; i < size; ++i)
        title[i] = x.title[i];
}

void Book::display()
{
    using std::cout;
    cout << "ID: " << ID << '\n';
    cout << "title: " << title << '\n';
    cout << "price: " << price << '\n';
}

Bookstore::Bookstore()
{
}

void Bookstore::addABook()
{
    Book tmp;
    bool found = false;
    for (auto &i : books)
    {
        if (i.compare(tmp))
        {
            found = true;
            break;
        }
    }
    if (!found)
        books.push_back(tmp);
}

bool Book::compare(const Book& x)
{
    return ID == x.ID;
}

void Bookstore::display()
{
    for (auto &i : books)
        i.display();
}

void Bookstore::sellABook(int ID)
{
}