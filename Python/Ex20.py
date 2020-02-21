from sys import argv

script, inputFile = argv

def printAll(f):
    print(f.read())

def rewind(f):
    f.seek(0)

def printALine(lineCount, f):
    print(lineCount, f.readline())

currentFile = open(inputFile)

print("First let's print the whole file:\n")

printAll(currentFile)

print("Now let's rewind\n")

rewind(currentFile)

currentLine = 1
printALine(currentLine, currentFile)

currentLine = currentLine + 1
printALine(currentLine, currentFile)

currentLine = currentLine + 1
printALine(currentLine, currentFile)