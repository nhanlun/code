def PrintTwo(*args):
    arg1, arg2 = args
    print("arg1: {}, arg2: {}".format(arg1, arg2))

def PrintTwoAgain(arg1, arg2):
    print("arg1: {}, arg2: {}".format(arg1, arg2))

def PrintOne(arg1):
    print("arg1: {}".format(arg1))

def PrintNone():
    print("I got nothing.")

PrintTwo("Zed", "Shaw")
PrintTwoAgain("Zed", "Shaw")
PrintOne("First!")
PrintNone()