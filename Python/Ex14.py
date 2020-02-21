from sys import argv

script, userName = argv
prompt = "> "

print("Hi {}, I'm the {} script.".format(userName, script))
print("I'd like to ask you a few question.")
print("Do you like me {}?".format(userName))
like = input(prompt)

print("Where do you live {}?".format(userName))
lives = input(prompt)

print("What kind of computer do you have?")
computer = input(prompt)

print("""
Alright, so you said {} about liking me.
You live in {}. Not sure where that is.
And you have a {} computer. Nice.
""".format(like, lives, computer))