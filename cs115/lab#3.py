# David Ott
# cs 115 lab#3
# 2/6/2014





scrabbleScores = [ ["a", 1], ["b", 3], ["c", 3], ["d", 2], ["e", 1], ["f", 4], ["g", 2], ["h", 4], ["i", 1], ["j", 8], ["k", 5], ["l", 1], ["m", 3], ["n", 1], ["o", 1], ["p", 3], ["q", 10], ["r", 1], ["s", 1], ["t", 1], ["u", 1], ["v", 4], ["w", 4], ["x", 8], ["y", 4], ["z", 10] ]




def removeALL (e, l):
    ''' takes a element and removes every instance of that element from a list '''
    if l == [ ]:
        return []
    elif e == l[0]:
        return removeALL(e, l[1:])
    else: 
        return [l[0]]+ removeALL(e, l[1:])
    
def myfilter(f, L):
    '''takes a function and a list, takes each element in that list and runs it through the function, giving it a boolean value'''
    '''It then returns a new list with all elements that returned true'''
    if L == []:
        return []
    elif f(L[0]) == True:
        return [L[0]] + myfilter(f, L[1:])
    else:
        return myfilter(f, L[1:])
def even(X):
    '''this function tests whether or not the elements are even or odd'''
    if X % 2 == 0 :
        return True
    else:
        return False
    

def deepReverse(L):
    '''takes a list and returns its elements in reverse order'''
    '''if the list contains additional lists, the elements within the additional list will also return in reverse order'''
    if L == []:
        return []
    elif isinstance(L[0], list):
        return deepReverse(L[1:]) + [deepReverse(L[0])]
    else:
        return deepReverse(L[1:]) + [L[0]]

def letterScore (x, y):
    '''takes a letter from a scrabble game and returns the letter's numerical value'''
    if y == []:
        return []
    elif x == y[0][0]:
        return y[0][1]
    else:
        return letterScore(x, y[1:]) 

def wordScore (e, f):
    '''takes a string of letters and returns its total numerical scrabble value'''
    if e == '':
        return 0
    else:
        return letterScore(e[0], f) + wordScore(e[1:], f)
    
