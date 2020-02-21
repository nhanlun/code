#ifndef Bookstore_h
#define Bookstore_h

#include <bits/stdc++.h>

class Book
{
private:
    int ID;
    char* title;
    double price;
public:
    Book();
    Book(int ID, char* title, double price);
    Book(const Book&);
    ~Book();
    bool compare(const Book&);
    void display();
};

class Bookstore
{
private:
    std::vector<Book> books;
public:
    Bookstore();
    // ~Bookstore();
    void addABook();
    void sellABook(int ID);
    void display();
};


#endif