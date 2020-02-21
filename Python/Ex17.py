from sys import argv 
from os.path import exists

script, fromFile, toFile = argv

print("Copying from {} to {}".format(fromFile, toFile))

inp = open(fromFile)
inpData = inp.read()

print("The input file is {} bytes long".format(len(inpData)))

print("Does the output file exist? {}".format(exists(toFile)))
print("Ready, hit RETURN to continue, CTRL-C to abort.")
input()

out = open(toFile, 'w')
out.write(inpData)

print("Alright, all done.")

out.close()
inp.close()