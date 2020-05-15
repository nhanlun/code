long doSomething()
{
    long sum = 0;
    for (long i = 0; i < 10; ++i)
    {
        if (i & 1) continue;
        sum +=i;
    }
    return sum;
}