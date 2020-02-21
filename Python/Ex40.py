class Song(object):

    def __init__(self, lyrics):
        self.lyrics = lyrics

    def sing_me_a_song(self):
        for line in self.lyrics:
            print(line)

happyBirthday = Song(["Happy birthday to you", "I don't want to get sued", "So I'll stop right there"])

bullsOnParade = Song(["They rally around tha family", "With pockets full of shells"])

happyBirthday.sing_me_a_song()

bullsOnParade.sing_me_a_song()