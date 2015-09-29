#David Ott
#HW #7
#I pledge my honor that I have abided by the stevens honor system
#5/1/14

def a7_test():
    NBA = League("National Basketball Association")
    NHL = HockeyLeague("National Hockey League")
    EPL = SoccerLeague("English Premier League")
    file = open('assgn7.txt', 'r')
    for line in file:
        fields = line.strip().split(' ')
        if len(fields) < 2:
            continue
        league = fields[0]
        action = fields[1]
        if league == "NBA":
            if action == "Team":
                NBA.addTeam(fields[2], fields[3])
            elif action == "Game":
                NBA.addResult(fields[2], fields[4])    # fields[2] is winner, fields[4] is loser
            elif action == "Standings":
                NBA.printStandings()
            else:
                print "ERROR: incorrect action on line " + line
        elif league == "NHL":
            if action == "Team":
                NHL.addTeam(fields[2], fields[3])
            elif action == "Game":
                if len(fields) == 7 and fields[6] == "OT":
                    NHL.addResult(fields[2], fields[4], True)    # fields[2] winner, fields[4] loser, fields[6] OT
                else:
                    NHL.addResult(fields[2], fields[4])
            elif action == "Standings":
                NHL.printStandings()
            else:
                print "ERROR: incorrect action on line " + line
        elif league == "EPL":
            if action == "Team":
                EPL.addTeam(fields[2], fields[3])
            elif action == "Game":
                EPL.addResult(fields[2], fields[4], int(fields[3]), int(fields[5]))    # winner, loser, winner score, loser score
            elif action == "Standings":
                EPL.printStandings()
            else:
                print "ERROR: incorrect action on line " + line
        else:
            print "ERROR: incorrect league on line " + line
    file.close()


class Team:

    def __init__(self, city, name):
        """ create new team with initial 0-0 record """
        self.city = city
        self.nickname = name
        self.wins = 0
        self.losses = 0

    def __repr__(self):
        """ return string with team's city, nickname, wins, and losses """
        return "%-25s%d%2d" % (self.city + " " + self.nickname, self.wins, self.losses)

    def win(self):
        """ record that team won a game """
        self.wins = self.wins + 1

    def lose(self):
        """ record that team lost a game """
        self.losses = self.losses + 1

    def standing(self):
        """ return fraction of games won; return 0.0 if no games played """
        if self.wins + self.losses == 0:
            return 0.0
        else:
            return float(self.wins) / (self.wins + self.losses)


class League:

    def __init__(self, name):
        """ create new league with no teams in the league """
        self.leagueName = name
        self.teams = list()

    def addTeam(self, city, nickname):
        """ adds team to league; don't worry about duplicates """
        t = Team(city, nickname)
        self.teams.append(t)

    def addResult(self, winner, loser):
        """ add result of a game; first arg is winner, second arg is loser """

        def findTeam(name):
            for t in self.teams:
                if (t.city == name) or (t.nickname == name):
                    return t
            return None
        
        w = findTeam(winner)
        l = findTeam(loser)
        if (w == None) or (l == None):    # do nothing & return if either team not found
            return
        w.win()
        l.lose()

    def printStandings(self):
        """ print league standings based on what each team's 'standing' method returns """

        #  nums is list of numbers that represent each team's standing
        nums = [ x.standing() for x in self.teams ]      # this is a 'list comprehension'
        
        #  order is list of INDICES of standings once they are sorted high-to-low
        #  Example: if nums = [ 0.500, 0.333, 0.666 ] then order = [ 2, 0, 1 ]
        order = sorted(range(len(nums)), key=lambda x: nums[x], reverse=True)

        #  print teams in standings order
        print "Standings for " + self.leagueName + ":"
        for i in order:
            print str(self.teams[i])
        print " "      # blank line


class HockeyTeam(Team):

    def __init__(self, city, name):
        """ create new team with 0 initial points """
        self.city = city
        self.nickname = name
        self.points = 0

    def __repr__(self):
        """ return string with team's city, nickname, and points """
        return "%-25s%2d" % (self.city + " " + self.nickname, self.points)

    def win(self):
        """ record that team won a game """
        self.points = self.points + 2

    def lose(self, OT):
        """ record that team lost a game """
        if OT:
            self.points = self.points + 1

    def standing(self):
        """ return number of points """
        return self.points


class HockeyLeague(League):

    def addTeam(self, city, nickname):
        """ add team to league; don't worry about duplicates """
        t = HockeyTeam(city, nickname)
        self.teams.append(t)

    def addResult(self, winner, loser, isOT=False):
        """ add result of a game; first arg is winner, second arg is loser, third arg indicates OT """

        def findTeam(name):
            for t in self.teams:
                if (t.city == name) or (t.nickname == name):
                    return t
            return None
        
        w = findTeam(winner)
        l = findTeam(loser)
        if (w == None) or (l == None):    # do nothing & return if either team not found
            return
        w.win()
        l.lose(isOT)
class SoccerTeam(Team):

    def __init__(self, city, name):
        """ create new team with initial 0-0-0 record """
        self.city = city
        self.nickname = name
        self.points = 0
        self.wins = 0
        self.loses = 0
        self.ties = 0
        self.goalsFor = 0
        self.goalsAgainst = 0
        self.dif = 0

    def __repr__(self):
        """ return string with team's city, nickname, wins, and losses """
        return "%-25s%2d%2d%2d%3d%3d" % (self.city + " " + self.nickname, self.wins, self.ties, self.loses, self.goalsFor, self.goalsAgainst)

    def win(self):
        """ record that team won a game """
        self.points = self.points + 3
        self.wins = self.wins + 1

    def tie(self):
        """ record that team tied a game """
        self.points = self.points + 1
        self.ties = self.ties + 1

    def lose(self):
        """Record that team lost"""
        self.loses = self.loses + 1

    def goalDif(self,goalsFor,goalsAgainst):
        """Keeps track of the teams goal differential"""
        self.goalsFor = self.goalsFor + goalsFor
        self.goalsAgainst = self.goalsAgainst + goalsAgainst
        self.dif = self.dif  + (goalsFor - goalsAgainst)
        
    def standing(self):
        """ return number of points plus accounting for goal differential"""
        return float(self.points) + (self.dif*0.001) + (self.wins*0.00001)
    
class SoccerLeague(League):    

    def addTeam(self, city, nickname):
        """ add team to league; don't worry about duplicates """
        t = SoccerTeam(city, nickname)
        self.teams.append(t)

    def addResult(self, winner, loser, winScore, loseScore):
        """ add result of a game; first arg is winner, second arg is loser, third arg is winner score, fourth arg is loser score """

        def findTeam(name):
            for t in self.teams:
                if (t.city == name) or (t.nickname == name):
                    return t
            return None
        
        w = findTeam(winner)
        l = findTeam(loser)
        if winScore == loseScore:
            w.tie()
            l.tie()
        else:
            w.win()
            l.lose()
        if (w == None) or (l == None):    # do nothing & return if either team not found
            return
        w.goalDif(winScore,loseScore)
        l.goalDif(loseScore,winScore)
    def printStandings(self):
        """ prints league standings based on what each individual team's standing returns """

        #  nums is list of numbers that represent each team's standing
        nums = [ x.standing() for x in self.teams ]      # this is a 'list comprehension'
        
        #  order is list of INDICES of standings once they are sorted high-to-low
        #  Example: if nums = [ 0.500, 0.333, 0.666 ] then order = [ 2, 0, 1 ]
        order = sorted(range(len(nums)), key=lambda x: nums[x], reverse=True)

        #  print teams in standings order
        print "Standings for " + self.leagueName + ":"
        for i in order:
            print str(self.teams[i])
        print " "      # blank line
