#David Ott
#HW assignment 3: Assembly Language Programming
#march 25
# I pledge my honor that I have abided by the stevens honor system

import sys


Example1 = """
00 read r1          # get # from user to r1
01 read r2          # ditto, for r2
02 mul r3 r1 r2     # r3 = r1 * r2
03 write r3         # print what's in r3
04 halt             # stop.
"""

# Example1 
# 1 asks for two inputs
# 2 computes the product of the inputs
# 3 prints out the result (with write)
# 4 stops



Problem1 = """
00 read r1          # get # from user to r1
01 write r1         # print the value of r1
02 addn r1 1        # add 1 to r1
03 jumpn 01         # jump to line 01
04 halt             # never halts! [use ctrl-c]

# Problem1 is an example program that
#   1) asks the user for an input
#   2) counts up from that input
#   3) keeps going and going...


"""

# Lab task #1: Change Problem1 to "the cubic countdown"

Labtask1 = """
00 read r1          # get # from user to r1
01 mul r2 r1 r1     # multiply r1 by r1
02 mul r3 r2 r1     # multiply r2 by r1 to get the cube of r1
03 write r3         # print the value of r1
04 setn r4 1        # sets r4 equal to 1
05 sub r3 r3 r4     # subtract r4 from r3
06 write r3         # prints new value of r3
07 jgtzn r3 05      # jump to line 05          
08 halt             # never halts! [use ctrl-c
"""

# Lab task #2: Write a random-number generator, named Random, here:

Random = """
00 read r1          # input a (multiplier)
01 read r2          # input c (increment)
02 read r3          # input m (modulus)
03 read r4          # input X_0 (seed)
04 read r5          # input N (number of numbers to be printed)
05 setn r6 1        # sets  r6 equal to 1 which will be subracted later on
06 copy r7 r5       # sets r7(counter) equal to the number pf inputs
07 mul r8 r1 r4     # multiplies r1 by r4 to get r8=(a*x)
08 add r9 r8 r2     # adds r8 to r2 to get r9=(r8+c)
09 mod r10 r9 r3    # Find the remainder of r6 divided by r3 to get r10 
10 write r10        # prints out value of r8 x(n-1)
11 copy r4 r10      # sets r8 equal to the new seed value
12 sub r11 r7 r6    # subtracts 1 from r11
13 copy r7 r11      # makes r8 equal to r12
14 jgtzn r7 07      # jump to line 07 when r7 is greater than 0
15 halt
                    #Smallest Values a=21 and c=3
"""




def unique(L):
    if L == []:
        return True
    if (L[0] in L[1:]) is True :
        return False
    else:
        return unique(L[1:])
    


NUMBERS = """
24
7
50
53
16
39
22
65
68
31
54
37
80
83
46
69
52
95
98
61
84
67
10
13
76
99
82
25
28
91
14
97
40
43
6
29
12
55
58
21
44
27
70
73
36
59
42
85
88
51
74
57
0
3
66
89
72
15
18
81
4
87
30
33
96
19
2
45
48
11
34
17
60
63
26
49
32
75
78
41
64
47
90
93
56
79
62
5
8
71
94
77
20
23
86
9
92
35
38
1
"""

def test( TQS ):
    """ test takes in a triple-quoted string, TQS,
        containing one number per line. Then, test
        returns True if those numbers are all unique
        (or if TQS is empty); otherwise it returns False
    """
    ListOfStrings = TQS.strip().split()
    # print "ListOfStrings is", ListOfStrings
    ListOfIntegers = [ int(s) for s in ListOfStrings ]
    # print "ListOfIntegers is", ListOfIntegers
    return unique( ListOfIntegers )



# Task 4: Power
# Computes the number x to some power y

Power = """
# returns a number x, to some power y
00 read r1      # inputs user's base number x to r1 
01 read r2      # inputs user's power y to r2
02 jeqzn r1 15  # if base r1 is zero, jump to line 15, returns zerp, then halt (CHECK LINE
03 jeqzn r2 18  # if power r2 is zero, jump to line 18, that returns one, then halt (CHECK LINE)
04 addn r15 1   # increase stack pointer r15 by 1
05 storer r1 r15# store r1 (base) in the stack is a push
06 addn r15 1   # increase stack pointer 15 by 1
07 storer r2 r15# store r2 (exponent) in the stack is a push
08 calln r14 21 # call power 21 function
09 loadr r2 r15 # pop r2 off the stack (exponent)
10 addn r15 -1  # decrease the stack pointer by 1
11 loadr r1 r15 # pop r1 off the stack (base)
12 addn r15 -1  # decrease the stack pointer r15 by 1
13 write r3     # print register that has final Power number 
14 halt         # halt program
15 setn r1 0    # if base is equal to 0, set r1 equal to 0
16 write r1     # print 0
17 halt         # halt program
18 setn r1 1    # if power is 0, set r1 equal to 1
19 write r1     # print 1
20 halt         # halt program
21 copy r3 r1   # set the value of r1 (base) equal to r3
22 addn r2 -1   # reduce exponent r2 by 1
23 mul r3 r3 r1 # multiply the base time the base and store it in r3
24 addn r2 -1   # reduce exponent by 1
25 jnezn r2 22  # if r2 (exponent) is not 0, jump to line 13
26 jumpr r14    # return to the first function call
"""


# These statements are to set up Hmmm...
# You'll need the files that are in this folder.

if __name__ == "__main__" : 
    import hmmmAssembler ; reload(hmmmAssembler)
    import hmmmSimulator ; reload(hmmmSimulator)
    hmmmAssembler.main() # assemble input into machine code
    hmmmSimulator.main(['-n'])   # run that machine code

# to change the function being run by the assembler and simulator, change to
#   hmmmAssembler.main(Function_name)
#
# to avoid debugging mode without asking, replace the last line with
#     hmmmSimulator.main(['-n'])
#
# to enter debugging mode without asking, replace the last line with
#     hmmmSimulator.main(['-d'])
#
# to have the program ask you whether or not you want to debug, use
#     hmmmSimulator.main()



#!/usr/bin/python
# hmmmSimulator.py
#
# $Id: hmmmSimulator.py,v 1.4 2007/10/08 08:10:12 geoff Exp $
#
# Ran Libeskind-Hadas, 2006
# modified by Peter Mawhorter, June 2006
# extensively modified by Geoff Kuenning, October 2007
