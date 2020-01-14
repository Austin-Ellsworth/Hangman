#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <locale>
using namespace std;

int main() {
	string words[20];
	string currentWord, guessStatus;
	char letter;
	char input = 'y';
	bool guessed = false, noLetter = true, letterAlready = false;
	int count, misses = 0;

	srand(time(0));
	ifstream inFile;
	inFile.open("words.txt");
	
	// 20 random words loaded into words arr 
	for (int i = 0; i < 20; i++) {
		inFile >> words[i];
	}

	while (input == 'y' or input == 'Y') { //big while
		//set word randomly selected
		currentWord = words[rand() % 20];
		count = 0;
		misses = 0;
		guessStatus = "";
		for (int i = 0; i < currentWord.length(); i++) {
			guessStatus += "*";
		}
		while (!guessed) {//guess while
			cout << "(Guess) Enter a letter in word " << guessStatus << " > ";
			cin >> letter;
			for (int i = 0; i < currentWord.length(); i++) {
				if (tolower(letter) == currentWord[i]) {
					if (guessStatus[i] == currentWord[i]) {
						letterAlready = true;
					}
					else {
						guessStatus[i] = currentWord[i];
					}
					count++;
				}
			}
			if (count < 1) {
				cout << "\n--" << letter << " is not in the word\n";
				misses++;
			}
			if (letterAlready == true) {
				cout << "\n--" << letter << " is already in the word\n";
			}

			letterAlready = false;
			count = 0;
			for (int i = 0; i < currentWord.length(); i++) {
				if (guessStatus[i] == currentWord[i]) {
					count++;
				}
			}
			if (count == currentWord.length()) {
				guessed = true;
			}
			else {
				count = 0;
			}
		}
		guessed = false;
		
		cout << "\n***The word is " << guessStatus << ". You missed " << misses << " time(s)***";
		cout << "\nDo you want to guess another word? Enter <y> or <n> \n";
		cin >> input;
	}

	cout << "\nThanks for using my program!";


	return 0;
}