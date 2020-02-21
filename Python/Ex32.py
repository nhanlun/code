theCount = [*range(1,6)]
fruits = ["apples", "oranges", "pears", "apricots"]
change = [1, "pennies", 2, "dimes", 3, "quarters"]

for number in theCount:
    print("This is count {}".format(number))

for fruit in fruits:
    print(f"A fruit of type: {fruit}")

for i in change:
    print(f"I got {i}")

elements = []
for i in range(6):
    print(f"Adding {i} to the list.")
    elements.append(i)

for i in elements:
    print(f"Element was: {i}")
