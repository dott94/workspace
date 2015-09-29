#include "cracker.h"

using namespace std;
int main(int argc, char** argv) {
	string salt;
	int timeout;
	time_t endwait;
	int passGenCount = 0;
	int passTried;
	int crackAttempt;
	string password;
	int passIndex = 0;
	int dictIndex = 0;
	string line;
	bool hasSalt = false;
	bool found = false;
	int userPasswordsCount = 0;

	if (argc > 5 || argc < 4) {
		printf("usage: ./cracker password_file results_file timeout salt");
		exit(1);
	}
	if (atoi(argv[3]) == '0') {
		exit(1);
	}
	if (argc == 5) {
		hasSalt = true;
		salt = string(argv[4]);
	}
	timeout = atoi(argv[3]); //setting time from input
	time_t startTime = time(NULL);
	endwait = startTime + timeout;

	ifstream input(argv[1]); //input file
	ofstream result(argv[2]); //out file
	bool cont = true;
	while (std::getline(input, line) && cont) {
		int position = line.find(":");
		password = line.substr(position + 1, line.size()); // making sure we read the hash string 
		userPasswordsCount += 1;
		found = false;
		ifstream dictionary("dictionary.txt");
		string newLine;
		passTried = 0;
		while (std::getline(dictionary, newLine) && cont && !found) {

			/*Dictionary attack*/
			for (char i = 47; i < 58; i++) //loops used for Heuristics feature
					{
				for (int j = 0; j < 2; j++) {
					string line2 = newLine;
					if (j == 1) {
						transform(line2.begin(), line2.end(), line2.begin(),
								::toupper); //setting first letter of passwords toupper (Heuristics)
					}
					if (i > 47) {
						line2 += i; //appending extra character to password (Heuristics)
					}
					passTried++;
					if (hasSalt) {
						line2 = line2 + salt; // appending salt
					}
					/* converting dictionary passwords to md5 hash and comparing with the hash of input file passwords*/
					unsigned char md5Dict[16];
					const unsigned char* dictLine =
							(const unsigned char*) line2.c_str();
					MD5(dictLine, line2.size(), (unsigned char*) &md5Dict);
					char mdString[33];
					for (int i = 0; i < 16; i++) {
						sprintf(&mdString[i * 2], "%02x",
								(unsigned int) md5Dict[i]);
					}
					if (string((const char*) mdString) == password) { // comparing to see if we match

						result << password << " : "
								<< line2.substr(0, line2.size() - salt.size())
								<< endl; // writing to out file
						found = true;
					}
					if (time(NULL) > endwait) {
						cont = false;
					}
				}
			}

		}
		/*brute force attack*/
		string passGen = "";
		for (char i = 31; i < 127 && !found && cont; i++) //looping through ascii characters that are useful
				{
			for (char j = 33; j < 127 && !found && cont; j++) {
				for (char k = 33; k < 127 && !found && cont; k++) {
					for (char l = 33; l < 127 && !found && cont; l++) {
						for (char m = 33; m < 127 && !found && cont; m++) {
							passGen = "";
							if (i > 32) { //used to triger the append of the 5th character 
								passGen += i;
							}
							if (i > 31) { //used to trigger the append of 4th character 
								passGen += j;
							}
							passGen += k; //3 char string creation
							passGen += l;
							passGen += m;
							passGenCount += 1;
							passTried++;
							if (hasSalt) {
								passGen = passGen + salt; //append salt
							}
							unsigned char md5Dict[16];
							const unsigned char* dictLine =
									(const unsigned char*) passGen.c_str(); //same md5 logic as dictionary
							MD5(dictLine, passGen.size(),
									(unsigned char*) &md5Dict);
							char mdString[33];
							for (int i = 0; i < 16; i++) {
								sprintf(&mdString[i * 2], "%02x",
										(unsigned int) md5Dict[i]);
							}
							if (string((const char*) mdString) == password) {
								result << password << " : "
										<< passGen.substr(0,
												passGen.size() - salt.size())
										<< endl;
								found = true;
							}
							if (time(NULL) > endwait) {
								cont = false;
							}
						}
					}
				}
				if (i == 31) {
					break;
				}
			}
		}
	}
	time_t runTime = time(NULL) - startTime; //runtime calculation 
	cout << "The program ran for: " << runTime - 1 << " seconds." << endl;
	cout << "We tried this many total passwords: " << passTried << "." << endl;
	cout << "The number of passwords generated is: " << passGenCount << "."
			<< endl;
	cout << "The number of user passwords that we attempted to crack: "
			<< userPasswordsCount << "." << endl;

	return 0;

}
