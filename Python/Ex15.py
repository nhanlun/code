from sys import argv

script, fileName = argv

txt = open(fileName)

print("Here's your file {}:".format(fileName))
print(txt.read())

print("Type the filename again:")
fileAgain = input("> ")

txtAgain = open(fileAgain)

print(txtAgain.read())