import random
from urllib.request import urlopen 
import sys

WORD_URL = "http://learncodethehardway.org/words.txt"
WORDS = []

PHRASES = {
    "Class %%%(%%%):": "Make a class named %%% that is-a %%%.",
    "Class %%%(object):\n\tdef__init__(self, ***)": "class %%% has-a __init__ that takes self and *** params.",
    "class %%%(object):\n\tdef ***(self, @@@)": "Class %%% has-a function *** that takes self and @@@ params.",
    "*** = %%%()": "Set *** to an intance of class %%%.",
    "***.***(@@@)": "From *** get the *** function, call it with params self, @@@.",
    "***.*** = '***'": "From *** get the *** attribute and set it to '***'."
}


if len(sys.argv) == 2 and sys.argv[1] == "english":
    PHRASE_FIRST = True
else:
    PHRASE_FIRST = False


for word in urlopen(WORD_URL).readlines():
    WORDS.append(str(word.strip(), encoding = "utf-8"))


def convert(snippet, phrase):
    classNames = [w.capitalize() for w in random.sample(WORDS, snippet.count("%%%"))]
    otherNames = random.sample(WORDS, snippet.count("***"))
    results = []
    paramNames = []

    for i in range(0, snippet.count("@@@")):
        paramCount = random.randint(1,3)
        paramNames.append(", ".join(random.sample(WORDS, paramCount)))

    for sentence in snippet, phrase:
        result = sentence[:]

        for word in classNames:
            result = result.replace("%%%", word, 1)

        for word in otherNames:
            result = result.replace("***", word, 1)
        
        for word in paramNames:
            result = result.replace("@@@", word, 1)

        results.append(result)
    
    return results


try:
    while True:
        snippets = list(PHRASES.keys())
        random.shuffle(snippets)

        for snippet in snippets:
            phrase = PHRASES[snippet]
            question, answer = convert(snippet, phrase)
            if PHRASE_FIRST:
                question, answer = answer, question

            print(question)

            input("> ")
            print(f"ANSWER: {answer}\n\n")
except EOFError:
    print("\nBye")