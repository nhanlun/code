public class Cat 
{
    int age;
    String name;
    enum Color{Yellow, Black, White}
    Color color;

    public Cat(int _age, String _name, Color _color)
    {
        age = _age;
        name = _name;
        color = _color;
    }

    public void meow()
    {
        System.out.println("Meow");
    }

    public void info()
    {
        System.out.println(age + " " + name + " " + color);
    }
} 