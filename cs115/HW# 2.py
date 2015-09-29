#David Ott
#Homework 2
#3/1/14
    
def isOdd(N):
    '''tests if a number is even or odd'''
    if N%2==0:
        return True
    else:
        return False
def numToBinary(N):
    '''Take a number N and returns its binary representation'''
    if N == 0:
        return ''
    elif N%2==0:
        return numToBinary(N/2) + '0'
    else:
        return numToBinary(N/2) + '1'

    
def binaryToNum(S):
    '''takes the binary representation of a number and returns its decimal value'''
    if S=='':
        return 0
    else:
        return int(S[-1]) + 2*binaryToNum(S[:-1])

def increment(I):
    '''Takes a binary string and returns an incrimental value of that string'''
    if I=='':
        return ''
    elif I== "11111111":
        return "00000000"    
    else:
        change= binaryToNum(I)
        new= change+1
        string= numToBinary(new)
        zero= 8-len(string)
        return '0'*zero + string

def count(S, n):
    '''Take a binary string and an incremental value and returns that given string with the given increment'''
    if S=='':
        return ''
    elif n==0:
        print S
    else:
        print S
        print count(increment(S),n-1)
      
    
def numToBaseB(N,B):
    '''Takes a number and converts it to a given base'''
    if N==0:
        return ''
    elif N%B==0:
        return numToBaseB((N/B),B) + '0'
    else:
        return numToBaseB((N/B),B) + '1'

def baseBToNum(S,B):
    '''takes a representation string and a given base, and returns the decimal value of the representation'''
    if S=='':
        return 0
    else:
        return int(S[-1]) + B*binaryToNum(S[:-1])

def add(S1, S2):
    '''takes two binary strings and returns the sum of the two, also in binary representation'''
    if S1=='' and S2=='':
        return ''
    else:
        s1= binaryToNum(S1)
        s2= binaryToNum(S2)
        Num= s1+s2
        return numToBinary(Num)     

def addBHelp(s1, s2, carry):
    
    if s1 == "" and s2 == "" :
        if carry== 1:
            return str(carry)
        else:
            return ""
    elif s1 == "" :
        return addBHelp(str(carry), string2, 0)
    elif s2 == "" :
        return addBHelp(s1, str(carry), 0)
    else :
        sum = int(carry + int(s1[-1]) + int(s2[-1])) % 2
        carryout = int(carry + int(s1[-1]) + int(s2[-1])) / 2
        return addBHelp(s1[:-1], s2[:-1], carryout) + str(sum)
    
def addB(S1,S2):
    '''adds two binary string and returns their result only showing significant digits'''
    return addBHelp(S1, S2, 0)

def complement(string) :
    '''Returns 0's for 1 representation, and 1's for zero represenation'''
    if string == "" :
        return ""
    else :
        if string[0] == "1" :
            return "0" + complement(string[1:])
        else :
            return "1" + complement(string[1:])

def TwosComplement(string) :
    '''returns the two's compliment representation of a string'''
    return addB(complement(string), "1")

def TcToNum(S):
    '''Takes a string representing 2s compliment of an integer and returns the corresponding integer'''
    if len(S)>8:
        return "Error"
    elif S== '':
        return ''
    elif S[0]=='0':
        return binaryToNum(S)
    else:
        return -1 * binaryToNum(TwosComplement(S))

def NumToTc(N):
    '''takes a string representing an integer and returns its twos compliment value'''
    if N>127 or N<-128:
        return "Error"
    elif N>0:
        length= 8-len(numToBinary(N))
        zeroes= '0'*length
        return zeroes + numToBinary(N)
    else:
        length=8-len(numToBinary(-N))
        zeroes= '0'*length
        string1= zeroes+numToBinary(-N)
        return TwosComplement(string1)


def BinarysTest():
    if isOdd(5)== False:
        print "isOdd test pass!"
    else:
        print "isOdd test fail :("
    if numToBinary(binaryToNum('100')) == '100':
        print "numToBinary and binaryToNum test pass!"
    else:
        print "numToBinary and binaryToNum test Fail :("
    if increment ('11111111') == '00000000':
        print 'Increment test pass!'
    else:
        print 'Increment test fail :('
    #count test
    if numToBaseB(4,2)=='100':
        print 'numToBaseB test pass!'
    else:
        print 'numToBaseB test fail :('
    if baseBToNum("11", 2)== 3:
        print 'baseBToNum test pass!'
    else:
        print 'baseBToNum test fail :('
    if add("11", "01")== '100':
        print 'add test pass!'
    else:
        print 'add test fail :('
    if addB("11", "1")== '100':
        print 'addB test pass!'
    else:
        print 'addB test fail :('
    if TcToNum(NumToTc(1))== 1:
        print 'TcToNum and NumToTc test pass!'
    else:
        print 'TcToNum and NumToTc test fail :('
    
    
    





