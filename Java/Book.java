import java.util.*;

class Book
{
    String name;
    String author;
    int price;

    Book(String _name, String _author, int _price)
    {
        name = _name;
        author = _author;
        price = _price;
    }

    Book()
    {
        name = "";
        author = "";
        price = 0;
    }

    public void input(Scanner sc)
    {
        String tmp = sc.nextLine();
        name = sc.nextLine();
        author = sc.nextLine();
        price = sc.nextInt();
    }

    public void printBook()
    {
        System.out.println(name + " " + author + " " + price);
    }

}