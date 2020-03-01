//============================================================================
// Name        : NumberOfWordsInText.cpp
// Author      : Alex Dinkelacker
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>

#include<bits/stdc++.h>

using namespace std;

int main()

{

	fstream file;

	string word;

	map<string, int> count;

	//Input your file here to open it
	//Surround text file with quotes
	//Example - file.open("yourFile.txt");
	file.open("map.txt");

	//Reading file word by word
	while (file >> word)

	{
		//Converting each word to lowercase
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		//Removing ',' and '.' from the end of words
		//Can be converted to remove other characters as well
		if (word[word.size() - 1] == ',' || word[word.size() - 1] == '.' || word[word.size() - 1] == ';')

			word = word.substr(0, word.size() - 1);

		if (count.find(word) == count.end())

			count[word] = 1;

		else

			count[word]++;

	}



	for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it)

		cout << it->first << " => " << it->second << '\n';

	return 0;

}
