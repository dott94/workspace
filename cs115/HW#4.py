#David Ott
#4/1/14
#Nim HW
#I pledge my honor that I have abided by the Stevens Honor System




print"""Lets Play Nim!!!"""
num_piles = int(raw_input("How many piles would you like to play with? "))
pile = [0] * num_piles
pile_sum = [0] * num_piles
gamechecker = False
while num_piles <= 0:
    print "Enter a valid number"
    num_piles = int(raw_input("How many piles would you like to play with?"))



def startNimgame():
    '''starts the game, ending when the gameover flag is set by the winner'''
    prnt_piles()
    while gamechecker == False: 
        user_turn()
        if gamechecker == True:
            break
        comp_turn(num_piles)
        checkforwin()
    return

for i in range(num_piles):
    print "How many coins do you want in pile",str(i),"?"
    pile[i] = int(raw_input())    

 

def prnt_piles():
    '''prints number of coins in each pile'''
    for i in range(len(pile)):
        print "pile ",str(i)," = ",str(pile[i])
    return

 

def nimsum():
    '''Finds the xor of the piles and returns puts in nim_sum'''
    global pile
    i = 0
    nim_sum = 0
    while i <= (len(pile)-1):
        nim_sum = nim_sum ^ pile[i] 
        i = i + 1
    return nim_sum

 

def pilesums(num_piles,nim_sum):
    '''accepts the number of piles, nim_sum and calculates the xor of each individual pile''' 
    global pile,pile_sum
    i = 0
    while i <= (len(pile)-1):
        pile_sum[i] = pile[i] ^ nim_sum
        i=i+1
    return 

 

def user_turn():
    '''  user player picks from a pile, checks for illegal pile or objects number and modifies the pile list ''' 
    global pile
    needthepilenum = True
    print "Your turn ..."
    while needthepilenum == True:
        pilenum=int(raw_input("Which pile do you want to take from ? "))
        if pilenum < 0 or pilenum > (len(pile)-1) or pile[pilenum] == 0:
            print "Put in a valid number."
        else:
            needthepilenum = False
    needtheobjectnum = True        
    while needtheobjectnum == True:        
        howmany = int(raw_input("How many will you take ? "))
        if howmany <=0 or howmany > pile[pilenum]:
            print "Put in a valid number."
        else:
            needtheobjectnum = False
    pile[pilenum] = pile[pilenum]-howmany
    prnt_piles()
    checkforwin()
    if gamechecker == True:
        print "AHA! YOU WIN!!!"
    return

 

def comp_turn(num_piles):
    '''allows the computer to pick from a pile optimally, checks for nim_sum of zero error, skips turn if necessary and returns the pile list accordingly'''
    global pile
    print "You know nothing user....."
    nim_sum = nimsum()
    pilesums(num_piles,nim_sum)
    i = 0
    while i <= (len(pile)-1):
        if pile_sum[i] < pile[i]:
            pilenum = i
            howmany = pile[i]-pile_sum[i]
        i = i + 1
    if nim_sum == 0:
        print "There is no optimal move I forfeit my turn!!"
    else:    
        pile[pilenum] = pile[pilenum] - howmany    
        print "I take ",howmany," from pile ",i - 1
    prnt_piles()
    checkforwin()
    if gamechecker == True:
        print "When you play the game of Nim you either win or die... You die!!"
    return

 
def checkforwin():
    '''checks for a winning state and if so makes gameover flag to be true'''
    global pile,gamechecker
    if sum(pile) == 0:
        gamechecker = True
    return 

 
 

 

 

if __name__ == "__main__" : startNimgame()
