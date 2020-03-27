public class HelloWorld
{
    public static void main(String[] args)
    {
        Cat neko = new Cat();
        System.out.println(neko.numberOfMeows);
    }
}

class Cat
{
    int numberOfMeows = 10;
    public Cat(int x)
    {
        // numberOfMeows = 0;
    }
}