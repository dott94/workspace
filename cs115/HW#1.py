#David Ott
#CS 115
#HW number 1

scrabbleScores = [ ["a", 1], ["b", 3], ["c", 3], ["d", 2], ["e", 1], ["f", 4], ["g", 2], ["h", 4], ["i", 1], ["j", 8], ["k", 5], ["l", 1], ["m", 3], ["n", 1], ["o", 1], ["p", 3], ["q", 10], ["r", 1], ["s", 1], ["t", 1], ["u", 1], ["v", 4], ["w", 4], ["x", 8], ["y", 4], ["z", 10] ]
from dict import *
rack = ['a', 'b', 'b', 't', 'c', 'd', 'm', 'n', 'f', 'b']

#The following functions are used as helper functions for scoreList
def letterScore (x, y):
    '''takes a letter from a scrabble game and returns the letter's numerical value'''
    if y == []:
        return 0
    elif x == y[0][0]:
        return y[0][1]
    else:
        return letterScore(x, y[1:]) 

def wordScore (S, scrabbeScores):
    '''takes a string of letters and returns its total numerical scrabble value'''
    if S == '':
        return 0
    else:
        return letterScore(S[0], scrabbleScores) + wordScore(S[1:], scrabbleScores)
    
def contains(x, S):
    '''returns true if x is contained in string S'''
    if S == []:
        return False
    elif x == S[0]:
        return True
    else:
        return contains(x, S[1:])

def remove(x, L):
    '''remove a single iteration of x from L'''
    if L[0] == []:
        return []
    elif L[0] == x:
        return L[1:]
    else:
        return [L[0]] + remove(x, L[1:])

def isWord(S, rack):
    '''returns True is a word can be made from the string'''
    if S == "" or rack == []:
        return True
    elif contains(S[0], rack):
        x = S[0]
        return isWord(S[1:], remove(x, rack))
    else:
        return False

def posswords(rack):
    '''returns a list of possible words from the rack of letters'''
    def helper(r):
        return isWord(r, rack)
    return filter(helper, Dictionary)

def scorewords(S):
    '''catenate a string with a scrabbleScore'''
    return [S] + [wordScore(S, scrabbleScores)]
    
def scoreList(rack):
    '''returns a list of possible words with their respected score'''
    return map(scorewords, posswords(rack)) 
 
#the following functions are used for the bestWord function
def betterWord(g, k):
    '''Given G is a list comprised of words and their scores, this returns the word and score with the larger score'''
    if g[1] > k[1]:
        return g
    else:
        return k

def bestWord(rack):
    '''shows the best word available from the given rack'''
    r = scoreList(rack)
    return reduce(betterWord, r)


#The Best Word Function
def bestWordtest():
    '''This shows the best word given the entire alphabet(with and without vowels)'''
    Alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "p", "w", "x", "y", "z"]
    NoVowels = ["b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "p", "w", "x", "y", "z"]
    if bestWord != []:
        print "empty rack"
    elif bestword(Alphabet) != ['quiz', 22]:
        print "failed rack" + str(Alphabet)
    elif bestWord(NoVowels) != ['www', 12]:
        print "failed rack" + str(NoVowels)
    else:
        print "bestWord Passed all tests"




#Test Cases:

#letterscore test cases:
#In putted the letters 'a', 'b' 'f' and 'd' and they all passes. I tested with letters
#because they all have different numerical value,

#wordScore tese cases:
#I inputted 'apple', 'mamma', 'antidisestablishmentarianism'. These were picked
#because some contain double letters, others vary in all letters and string lengths.

#contains:
#I inputted single character strings such as 'a' and 'b' to test, along with multiple
#character strings such as 'add' and 'cat'. All returned True and false accordingly in 
#their respected tests. 

#Remove:
#Tested with single chatacter strings and multiple character strings like the "contains" 
#test.

#isWord:
#I tested a series of words including words that contained all the letters in my rack 
#and additional letters, words that had dubble letters such as 'apple' and 'mom'. all
#tests passed and failed accordingly. 

#posswords:
#tested with varies rack inputs so i could recognize whether or the program was running 
#properly. I also made racks with inputs like ['a', 'd', 'd'], knowing that there are only a
#few words with those letters. 

#scorewords and scorelist:
#scorewords also worked with all cases by testing side by side with the wordscore, varifing
#its accuracy. Scorelist always mattched these inputs correctly as well. 

#Betterword and Bestword:
#I also approached this test by minipulating the rack so that i can logically verify the 
#accuracy of the program. given a score list with few functions(such as the posswords
#example) it was clear to indetify the correctness, along with larger rack sizes. 
