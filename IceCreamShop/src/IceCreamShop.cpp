//============================================================================
// Name        : IceCreamShop.cpp
// Author      : Alex Dinkelacker
// Instructor  : Jackie Kuehn
// Description :
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

//Global variable charge.
double charge = 0;

//Function to print out total charge.
void totalCharge(){
	cout << "Total charge:\t" << "$" << charge << endl;
}

//Function to print out the cone (yummy!).
void conePrinter(int scoops, string firstScoop, string secondScoop, string thirdScoop){

cout << endl << "Here's your cone! Enjoy!!!" << endl;

//These three if statements will catch the three characters in the cone,
// 	and print them in the desired way(per the assignment).
if(scoops >= 1) {
	cout << "\t ( " << firstScoop << " )" << endl;
}

if(scoops >= 2) {
	cout << "\t ( " << secondScoop << " )" << endl;
}

if(scoops >= 3) {
	cout << "\t ( " << thirdScoop << " )" << endl;
}

//These two statements will print out the bottom of the cone.
//Got to be able to hold your cone.
cout << "\t  \\ /" << endl;
cout << "\t   |" << endl;
}

//This function creates each cone.
//This function also takes use of the global variable charge to keep a running total on the charge.
void makeMeACone(){

//Count for the amount of scoops.
int scoops;

//Using strings because the user could accidentally type in more than one char for each scoop.
string one, two, three;

cout << endl << "How many scoops for cone? (limit 3 scoops per cone) ";
cin >> scoops;

//This if statement just alerts the user if they have typed more than 3 scoops.
if(scoops > 3){
	cout << endl << "****Only three scoops per cone!****" << endl;
}

/*--These next three if statements will take user input in for each scoop of ice cream.
  --Note, the user is able to type something greater than 1 character, however this program will
  	  make them retype that scoop, because you can't have more than one char per scoop. */
if(scoops >= 1){
	cout << endl << "Specify the flavor for scoop 1: ";
	cin >> one;

	while(one.length() > 1){
		cout << endl << "*****I told you only one character per scoop, try again*****" << endl << endl << "Specify the flavor for scoop 1(again): ";
		cin >> one;
}
	charge += 2.00;}

if(scoops >= 2){
	cout << "Specify the flavor for scoop 2: ";
	cin >> two;

	while(two.length() > 1){
		cout << endl <<"I told you only one character per scoop, try again" << endl << endl <<"Specify the flavor for scoop 2(again): ";
		cin >> two;
}
	charge += 2.00;}

if(scoops >= 3){
	cout << "Specify the flavor for scoop 3: ";
	cin >> three;

	while(three.length() > 1){
		cout << endl <<"I told you only one character per scoop, try again" << endl << endl <<"Specify the flavor for scoop 3(again): ";
		cin >> three;
}
	charge += 1.25;}

//Just some **flavor** for the user.
//see what a did there? ;) #flavor -> like ice cream flavor
if (scoops > 3){
	cout << endl << "Sorry, no more than three scoops! You can thank me later!" << endl;
}
conePrinter(scoops, one, two, three);
}

/*
 * This function starts our program off and initializes the user to type how many cones they will want.
 * This function runs a loop for ever cone and will utilize the makeMeACone function to make each one of the cones.
 */
void yummyProject(){
int n;

cout << endl << "Ice Cream Flavors: Only one input character for each flavor." << endl << endl;
cout << "Please input the number of cones that you wish to purchase (10 max): ";
cin >> n;

//A check to make sure the user is only inputting up to 10 cones. 10 being the max for one person.
while(n > 10){
	//Some more flavor in here.
	cout << endl << "****Only 10 cones per order please****" << endl << endl << "Please input the number of cones that you wish to purchase (10 max): ";
	cin >> n;
}
//For each cone, make a cone.
for(int i=0; i<n; i++){
	makeMeACone();
}
//Prints total charge last.
totalCharge();
}

int main() {

//This is the starting lines of the program.
//Gives the title of the shop and the price for the ice cream.
//Given from the assignment.
cout << "\t\t Alex and Olivia's Ice Cream Shop" << endl;
cout << "\t\t 1 scoop \t ->\t $2.00" << endl;
cout << "\t\t 2 scoops \t ->\t $4.00" << endl;
cout << "\t\t each scoop after 2->\t $1.25" << endl;

//Starts the process
yummyProject();

}
