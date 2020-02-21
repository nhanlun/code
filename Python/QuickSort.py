n = int(input())
a = [i for i in map(int, input().split())]

def QuickSort(a):
    if len(a) == 1:
        return a
    pivot = a[0]
    Left = [i for i in a if i < pivot]
    Right = [i for i in a if i > pivot]
    return QuickSort(Left) + QuickSort(Right)

print(QuickSort(a))