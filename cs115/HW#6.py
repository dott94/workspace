#
# dates.py
#
# name: David Ott
#
DIM = [0,31,28,31,30,31,30,31,31,30,31,30,31]
class Date:
    """ a user-defined data structure that
        stores and manipulates dates
    """
    
    # the constructor is always named __init__ !
    def __init__(self, month, day, year):
        """ the constructor for objects of type Date """
        self.month = month
        self.day = day
        self.year = year


    # the "printing" function is always named __repr__ !
    def __repr__(self):
        """ This method returns a string representation for the object of type Date that calls it (named self).

             ** Note that this _can_ be called explicitly, but
                it more often is used implicitly via the print
                statement or simply by expressing self's value.
        """
        s =  "%02d/%02d/%04d" % (self.month, self.day, self.year)
        return s


    # here is an example of a "method" of the Date class:
    def isLeapYear(self):
        """ Returns True if the calling object is
            in a leap year; False otherwise. """
        if self.year % 400 == 0:
            return True
        elif self.year % 100 == 0:
            return False
        elif self.year % 4 == 0:
            return True
        else:
            return False

    def copy(self):
        """ Returns a new object with the same month, day, year as the calling object (self)."""

        dnew = Date(self.month, self.day, self.year)
        return dnew
    
    def equals(self, d2):
        """ Decides if self and d2 represent the same calendar date, whether or not they are the in the same place in memory."""
        return self.year == d2.year and self.month == d2.month and self.day == d2.day



#to be done:

    def tomorrow(self):
        """returns self increased by one day"""
        DIM = [0,31,28,31,30,31,30,31,31,30,31,30,31]
        if self.isLeapYear():
            DIM[2] = 29
        else:
            DIM[2] = 28
        if self.day < DIM[self.month]:    
            self.day = self.day + 1
            return
        elif self.month == 12:                 
            self.year = self.year + 1
            self.month = 1
            self.day = 1
            return
        else:                                  
            self.month = self.month + 1
            self.day = 1

            


    def yesterday(self):
        """ returns self desreased by one day"""
        DIM = [0,31,28,31,30,31,30,31,31,30,31,30,31]
        if self.isLeapYear():
            DIM[2] = 29
        else:
            DIM[2] = 28

        if self.month == 1 and self.day == 1:     
            self.year = self.year - 1
            self.month = 12
            self.day = 31
            return

        elif self.day != 1:   
            self.day = self.day - 1
            return
        else:                                 
            self.month = self.month -1
            self.day = DIM[self.month]  
        
    def addNDays(self, N):
        """Prints the next N amount of dates including the origional"""
        while N != 0:
            print self
            self.tomorrow()
            N = N-1
        print self
        
    def subNDays(self, N):
        """ Subtracts N days and prints each date including the origional"""
        while N != 0:
            print self
            self.yesterday()
            N = N-1
        print self

    def isBefore(self, d2):
        """Returns a boolean value if the one inputted date is before another"""
        if self.year < d2.year:
            return True
        elif self.year == d2.year and self.month < d2.month:
            return True
        elif self.year == d2.year and self.month == d2.month and self.day < d2.day:
            return True
        else:
            return False
        
    def isAfter(self, d2):
        """Returns a boolean value if an inputted date is after another"""
        if self.year < d2.year:
            return False
        elif self.year == d2.year and self.month < d2.month:
            return False
        elif self.year == d2.year and self.month == d2.month and self.day < d2.day:
            return False
        elif self == d2:
            return False
        else:
            return True
        
    def diff(self,d2):
        """Returns an interger value representation the difference in days between two inputted dates"""

        origDate = self.copy()
        newDate = d2.copy()
        
        if newDate.isBefore(origDate):
            diff = 0
            while not origDate.equals(newDate):
                newDate.tomorrow()
                diff = diff+1
            return diff
        elif origDate == newDate:
            diff =0
            return diff

        else:
            diff = 0
            while not origDate.equals(newDate):
                newDate.yesterday()
                diff = diff+1
            diff = 0 - diff
            return diff
        print diff
    def dow(self):
        """Prints the day of the week that the inputted date lands on"""
        refDate = Date(5,24,2014)
        spread = self.diff(refDate)
        day = spread % 7

        if day == 0:
            return 'Wednesday'
        elif day == 1:
            return 'Thursday'
        elif day == 2:
            return 'Friday'
        elif day == 3:
            return 'Saturday'
        elif day == 4:
            return 'Sunday'
        elif day == 5:
            return 'Monday'
        elif day == 6:
            return 'Tuesday'

    def dow2(self,refr):
        """Prints the day of the week that the inputted date lands on"""
        spread = self.diff(refr)
        day = spread % 7

        if day == 0:
            return 'Wednesday'
        elif day == 1:
            return 'Thursday'
        elif day == 2:
            return 'Friday'
        elif day == 3:
            return 'Saturday'
        elif day == 4:
            return 'Sunday'
        elif day == 5:
            return 'Monday'
        elif day == 6:
            return 'Tuesday'
        

def nycounter():
    """counts how many times the new year will land on each individual day of the week for the next 100 years!"""

    dowd = {}              # dowd == 'day of week dictionary'
    dowd["Sunday"] = 0     # a 0 entry for Sunday
    dowd["Monday"] = 0     # and so on...
    dowd["Tuesday"] = 0
    dowd["Wednesday"] = 0
    dowd["Thursday"] = 0
    dowd["Friday"] = 0
    dowd["Saturday"] = 0

    # live for another 100 years...
    for year in range(2011, 2112):
        d = Date(1, 1, year)   # get ny
        print 'Current date is', d
        s = d.dow()        # get day of week
        dowd[s] += 1       # count it

    print 'totals are', dowd

    # we could return dowd here
    # but we don't need to right now
    # return dowd






def bdayCounter():
    """Counts how many times my birthday will land on each invidual day of the week for the next 100 years!"""

    dowd = {}              # dowd == 'day of week dictionary'
    dowd["Sunday"] = 0     # a 0 entry for Sunday
    dowd["Monday"] = 0     # and so on...
    dowd["Tuesday"] = 0
    dowd["Wednesday"] = 0
    dowd["Thursday"] = 0
    dowd["Friday"] = 0
    dowd["Saturday"] = 0

    for year in range(2014, 2114):
        d = Date(2,23,year)   # get next birthday
        print 'Current date is', d
        s = d.dow()        # get day of week
        dowd[s] += 1       # count it

    print 'The totals are', dowd

#The totals are {'Monday': 15, 'Tuesday': 13, 'Friday': 15,
#'Wednesday': 14, 'Thursday': 14, 'Sunday': 14, 'Saturday': 15}    





def thirteenthCounter():
    """Counts how many times the 13th will land on each day of the week for the next 400 years!"""
    refDate = Date(2,14,2014)
    dowd = {}              # dowd == 'day of week dictionary'
    dowd["Sunday"] = 0     # a 0 entry for Sunday
    dowd["Monday"] = 0     # and so on...
    dowd["Tuesday"] = 0
    dowd["Wednesday"] = 0
    dowd["Thursday"] = 0
    dowd["Friday"] = 0
    dowd["Saturday"] = 0

    for year in range(2014, 2414):
        for month in range(1,12):
            d = Date(month,13,year)   
            print 'The current date is', d
            if d.dow() == 'Friday':
                refDate = d.copy()      
                s = d.dow2(refDate)        
                dowd[s] += 1      
            else: 
                s = d.dow()       # get day of week
                dowd[s] += 1      # count it
    print 'The totals are', dowd    

#The totals are {'Monday': 626, 'Tuesday': 631, 'Friday': 0,
#'Wednesday': 1256, 'Thursday': 629, 'Sunday': 631, 'Saturday': 627}        
        





