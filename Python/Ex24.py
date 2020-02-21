print("Let's practice everything.")
print('You\'d need to know \'bout escapes with \\ that do:')
print('\n newlines and \t tabs.')

poem = """
\tThe lovely world
with logic so firmly planted
cannot discern \n the needs of love
nor comprehend passion from intuition
and requires an explanation
\n\twhere there is none.
"""
print("-" * 20)
print(poem)
print("-" * 20)

five = 10 - 2 + 3 -6
print(f"This should be five: {five}")

def secret_formula(started):
    jellyBeans = started * 500
    jars = jellyBeans / 1000
    crates = jars / 100
    return jellyBeans, jars, crates


startPoint = 10000
beans, jars, crates = secret_formula(startPoint)


print("With a starting point of: {}".format(startPoint))
print(f"We'd have {beans} beans, {jars} jars, and {crates} crates.")

startPoint /= 10

print("We can also do that this way:")
formula = secret_formula(startPoint)

print("We'd have {} beans, {} jars, and {} crates.".format(*formula))