//============================================================================
// Name        : SoundEx.cpp
// Author      : Alex Dinkelacker
// Project     : Soundex allows you to sort through many historic records quickly,
//				 such as old census records. The Soundex system is a useful tool in
//		         searching for ancestors because the misspelling of family names was
//				 a common occurrence in official records. As well, the spelling of
//				 family names can change over time.
//============================================================================

#include <iostream>
using namespace std;
int main() {
	string name;
	string coded = "";
	cout << "Enter name: ";
	cin >> name;
	coded += name[0]; //1st letter
	for (size_t i = 1; i < name.length(); i++) {
		char ch = name[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			coded += "_";
		else if (ch == 'h' || ch == 'w')
			coded += ch;
		else if (ch == 'b' || ch == 'f' || ch == 'p' || ch == 'v')
			coded += '1';
		else if (ch == 'c' || ch == 'g' || ch == 'j' || ch == 'k' || ch == 'q'
				|| ch == 's' || ch == 'x' || ch == 'z')
			coded += '2';
		else if (ch == 'd' || ch == 't')
			coded += '3';
		else if (ch == 'l')
			coded += '4';
		else if (ch == 'm' || ch == 'n')
			coded += '5';
		else if (ch == 'r')
			coded += '6';
	}
	string s = "";
	s += coded[0];
	char prev = coded[0];
	for (size_t i = 1; i < coded.length(); i++) {
		if (coded[i] == '_') //one of the vowels , so need to retain next digit
				{
			prev = '_';
			//go to the next conditional
			continue;
		}
		if (coded[i] == 'h' || coded[i] == 'w' || coded[i] == prev) //need to retain only single occurence
			continue;
		s += coded[i];
		if (s.length() == 4) //stop if length is 4
			break;
		prev = coded[i];
	}
	while (s.length() < 4) //length less than 4 , append extra 0
		s += '0';
	cout << coded << " => " << s << endl;
	return 0;
}
