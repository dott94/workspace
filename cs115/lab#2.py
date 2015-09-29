#David Ott
#CS 115
import math 
def inverse(n):
    return 1.0 / n

def add (x, y):
    return x + y
def e(n):
   a = map(math.factorial, range(0, n+1, 1))
   d = map(inverse, a)
   f = reduce(add, d)
   return f    
 
