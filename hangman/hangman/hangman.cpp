// Hangman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
bool findGuessLetter(string a[], int size, char letter);

	/*

	  O
	 /|\
	  |
	 / \

	 1) Program randomly selects a secret word
	 2) Program draws dashes for each letter in the word -----
	 3) Program asks for a letter
	 4) If the letter is in the word, the letters are
		filled in at the correct location
		If the letter is not in the word, a piece of
		the hangman is filled in
	 5) The program displays Win or Lose

	*/

int _tmain(int argc, _TCHAR* argv[])
{
	string wordList[] = {"chocolate", "muffin", "pizza",
		"bread", "hamburger"};
	int words = sizeof(wordList) / sizeof(string);
	string name2find;
	bool EndOfGame = false;
	char response;
	string guess;
	char letter;
	int charInWord;
	int goodGuesses;
	int badGuesses;
	int startLocInString;
	string dashes = "--------------------------";
	string hangman[] = {
		"  |------|",
		"         |", 
		"         |",
		"         |",
		"         |",
		"        /_\\"
	};
	string nooseOne=    "  |------|";
	string firstLevel =	"  O      |";
	string nooseTwo=    "         |";
	string secondLevel =" /       |";
	string nooseThree = "         |";
	string secondLevel2=" /|      |";
	string secondLevel3=" /|\\     |";
	string nooseFour=   "         |";
	string thirdLevel=  "  |      |";
	string nooseFive=   "        /_\\";
	string fourthLevel= " /       |";
	string fourthLevel2=" / \\     |";
	string outerLetter;

	srand (time(0));	// seed the random number generator

	cout << "There are " << words << " words to choose from" << endl;

	do {
		name2find = wordList[ rand() % words ];
		cout << "The name to find = " << name2find << endl;

		// initialize guess count
		goodGuesses = 0;
		badGuesses = 0;
		startLocInString = 0;
		charInWord = name2find.length();
		guess = dashes.substr(0, charInWord);
		static int guessIndex = 0;
		string alreadyGuessed[50];
		for (int x=0; x<sizeof(alreadyGuessed)/sizeof(string);x++)
		{
			alreadyGuessed[x] = "";
		}

		// guess a letter until game ends
		do {
			// display the hangman
			if (badGuesses == 0)
			{
			   for (int i=0; i<sizeof(hangman)/sizeof(string); i++)
			   {
				   cout << hangman[i] << endl;
			   }
			}
				
			else if(badGuesses == 1)
			{
			  cout << nooseOne << endl << firstLevel << endl << nooseTwo << endl << nooseThree << endl << nooseFour << endl << nooseFive;
			}

			else if(badGuesses == 2)
			{
			  cout << nooseOne << endl << firstLevel << endl << secondLevel << endl << nooseThree << endl << nooseFour << endl << nooseFive;
			}

			else if(badGuesses == 3)
			{
			  cout << nooseOne << endl << firstLevel << endl << secondLevel2 << endl << nooseThree << endl << nooseFour << endl << nooseFive;
			}

			else if(badGuesses == 4)
			{
			  cout << nooseOne << endl << firstLevel << endl << secondLevel3 << endl << nooseThree << endl << nooseFour << endl << nooseFive;
			}

			else if(badGuesses == 5)
			{
			  cout << nooseOne << endl << firstLevel << endl << secondLevel3 << endl << thirdLevel << endl << nooseFour << endl << nooseFive;
			}

			else if(badGuesses == 6)
			{
			  cout << nooseOne << endl << firstLevel << endl << secondLevel3 << endl << thirdLevel << endl << fourthLevel << endl << nooseFive;
			}


			// display the guesses

			cout << endl << guess << endl;

			// ask for a letter
			cout << endl << "Guess a letter: " << endl;
			cin  >> letter;

			// put in the logic to determine if the letter is in the word
			// if it is in the word, replace each dash with the letter
			//  don't count a letter if it is already in the 'guess' string
			// if it is not in the word, draw a part of the hangman

			// for testing, just increment the badGuesses;
			stringstream sstream;
			string sletter;
			sstream << letter;
			sstream >> sletter;
			int location = name2find.find_first_of(letter, startLocInString);
			int locationTwo = name2find.rfind(letter);
			if (location == string::npos && sletter != name2find)
				badGuesses++;
			else if (findGuessLetter(alreadyGuessed,sizeof(alreadyGuessed)/sizeof(string),letter))
			{
				cout << "You have already guessed that letter!" << endl;
			}
			else
			{
				guess[location] = letter;
				guess[locationTwo] = letter;
				alreadyGuessed[guessIndex] = letter;
				guessIndex++;
			}
			outerLetter = sletter;


		} while (guess != name2find && badGuesses < 7 && outerLetter != name2find);

		if (guess == name2find || outerLetter == name2find)
		{
			cout << "Correct word: " << name2find << endl;
			cout << "You Win!" << endl;
		}
		else if (guess != name2find || outerLetter != name2find)
		{
			cout << nooseOne << endl << firstLevel << endl << secondLevel3 << endl << thirdLevel << endl << fourthLevel2 << endl << nooseFive;
			cout << "   <------------  He died because of YOU!" << endl;
			cout << "You LOSE" << endl;
			cout << "The correct word was: " << name2find << endl;
		}


		cout << endl << "Do you want to play again? ";
		cin  >> response;
		if (response == 'N' || response == 'n')
			EndOfGame = true;
	} while (! EndOfGame);

	return 0;



}

bool findGuessLetter(string a[], int size,char letter)
{
	stringstream sstream;
	string compare;
	sstream << letter;
	sstream >> compare;

	for (int x = 0; x < size; x++)
	{
		if (a[x] == compare)
		{
			return true;
		}
	}

	return false;
}