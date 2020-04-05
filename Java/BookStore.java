import java.util.*;

class BookStore
{
    ArrayList<Book> arr = new ArrayList<Book>();

    public void input()
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; ++i)
        {
            Book newBook = new Book();
            newBook.input(sc);
            arr.add(newBook);
        }
        sc.close();
    }

    public void output()
    {
        for (Book i : arr)
            i.printBook();
    }
    public static void main(String[] args)
    {
        // BookStore bookStore = new BookStore();
        // bookStore.input();
        // bookStore.output();
    }
}