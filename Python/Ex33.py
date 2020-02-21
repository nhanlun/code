numbers = []

def add_numbers(numbers, n):
    # i = 0
    # while i < n:
    for i in range(n):
        print(f"At the top i is {i}")
        numbers.append(i)

        i = 10
        print("Numbers now: ", numbers)
        print(f"At the bottom i is {i}")

add_numbers(numbers, 10)

print("The numbers: ")

for num in numbers:
    print(num)