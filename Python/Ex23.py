import sys 
script, inputEncoding, error = sys.argv


def main(languageFile, encoding, error):
    line = languageFile.readline()
    
    if line:
        print_line(line, encoding, error)
        return main(languageFile, encoding, error)


def print_line(line, encoding, error):
    nextLang = line.strip()
    rawBytes = nextLang.encode(encoding, errors = error)
    cookedString = rawBytes.decode(encoding, errors = error)

    print(rawBytes, "<===>", cookedString)


languages = open("languages.txt", encoding = "utf-8")

main(languages, inputEncoding, error)