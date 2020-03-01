//============================================================================
// Name        : RYGGame.cpp
// Author      : Alex Dinkelacker
// Version     : 001
// Instructor  : Jackie Kuehn
// Description : RYG (Red Yellow Green) Game. In this game you will be prompted
//             : for a guess. This guess will be 3 numbers (0-9), corresponding
//             : to 3 positions. The program will then tell you the amount of
//             : green, yellow and red guesses you have (hence RYG Game).
//             : Green means you have the correct number in the correct position.
//             : Yellow mean you have the correct number but out of position.
//             : Red means incorrect number.
//             : Goal is to get all green in the least amount of guesses. GO!
//============================================================================
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//instantiating my class
class RYGGame {

//all public info below
public:

	//constructor
	RYGGame() {
		//seeding the random number automatically with clock
		srand(time(NULL));
		//creating secret number(private variable) between 100 and 999
		secret = rand() % 900 + 100;
	}

	//function to see if guess is the correct number
	int guess(int n) {
		//all colors should start at 0 - in case user inputs no number
		int green = 0;
		int red = 0;
		int yellow = 0;

		//hundreds place secret digit
		//leftmost
		int d = secret / 100;
		//if secrets leftmost equals the guesses leftmost then green!
		if (d == n / 100)
			green++;
		//if the left most secret number equals the middle or rightmost guess number then yellow!
		else if (d == (n / 10) % 10 || d == n % 10)
			yellow++;
		else
			red++;

		//tens place secret digit
		//middle
		d = (secret / 10) % 10;
		//if secrets middle digit equals the guesses middle then green!
		if (d == (n / 10) % 10)
			green++;
		//if the middle secret number equals the leftmost or rightmost than yellow!
		else if (d == n / 100 || d == n % 10)
			yellow++;
		else
			red++;

		//ones place of secret digit
		d = secret % 10;
		//if secrets rightmost digit equals the guesses rightmost digit than green!
		if (d == n % 10)
			green++;
		//if secrets rightmost digit equals the guesses leftmost or middle digit than yellow!
		else if (d == n / 100 || d == (n / 10) % 10)
			yellow++;
		else
			red++;

		//if we have the correct guess then return 1 which will be seen as "status" in main
		if (yellow + red == 0)
			return 1;

		//this only prints if you have not yet guessed the correct number
		cout << endl <<  "You have: " << endl << " " << red << " red" << endl;
		cout << " " << green << " green" << endl;
		cout << " " << yellow << " yellow" << endl;

		//if you have not guessed the correct number than your "status" will be 0
		return 0;
	}
	~RYGGame(){
		cout << "Great job!" << endl;
	}

private:
	int secret;
};


int main() {

	//new instance of RYG Game calling constructor
	RYGGame game;

	int n;
	int status;

	cout << "Please enter a guess?" << endl;
	cin >> n;
	status = game.guess(n);
	int guesses = 2;
	while (status != 1) {
		cout << "Wrong! Next guess? Guess number: " << guesses << endl;
		cin >> n;
		guesses++;
		status = game.guess(n);
	}
	cout << "CONGRATULATIONS, YOU ARE CORRECT!!!!!!" << endl;
	cout << "Only took you " << guesses-1 << " guesses!" << endl;
	if (guesses == 1){
		cout << "Congratulations, you are the grand prize winner." << endl;
		cout << "FIRST TRY!!";
		cout << "Please call 1-800-805-5365 to collect your grand prize of $1B" << endl;
		cout << "________$$$$_______________"
				<< endl <<"_______$$__$_______________"
				<< endl <<"_______$___$$______________"
				<< endl <<"_______$___$$______________"
				<< endl <<"_______$$___$$_____________"
				<< endl <<"________$____$$____________"
				<< endl <<"________$$____$$$__________"
				<< endl <<"_________$$_____$$_________"
				<< endl <<"_________$$______$$________"
				<< endl <<"__________$_______$$_______"
				<< endl <<"____$$$$$$$________$$______"
				<< endl <<"__$$$_______________$$$$$$"
				<< endl <<"_$$____$$$$____________$$$"
				<< endl <<"_$___$$$__$$$____________$$"
				<< endl <<"_$$________$$$___1B_______$"
				<< endl <<"__$$____$$$$$$____________$"
				<< endl <<"__$$$$$$$____$$___________$"
				<< endl <<"__$$_______$$$$___________$"
				<< endl <<"___$$$$$$$$$__$$_________$$"
				<< endl <<"____$________$$$$_____$$$$"
				<< endl <<"____$$____$$$$$$____$$$$$$"
				<< endl <<"_____$$$$$$____$$__$$"
				<< endl <<"_______$_____$$$_$$$"
				<< endl <<"________$$$$$$$$$$";
	}
	return 0;
}

