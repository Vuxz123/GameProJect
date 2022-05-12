#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
class GameManager
{
public:
	int health;
	int mana;

protected:

	std::string word;
	std::string displace_word;
	std::string word_meaning;

	std::vector<std::string> wordlist;
	std::vector<std::string> wordmeaninglist;
	
	std::vector<char> guessedchar;

public:
	void addHealth(int add) {
		if (health == 100 && add > 0) return;
		health = health + add;
		if (health < 0) {
			health = 0;
			return;
		}
	}

	GameManager() {
		health = 50;
		mana = 100;

		loadWord();
		setRandom();
	}

	void reset() {
		health = 100;
		mana = 100;

		setRandom();
	}

	void loadWord() {
		std::ifstream wordinput; 
		std::string temp;

		wordinput.open("Word.txt", std::ifstream::in);
		
		while (wordinput >> temp) {
			wordlist.push_back(temp);
		}

		wordinput.close();

		wordinput.open("WordMeaning.txt", std::ifstream::in);

		while (wordinput >> temp) {
			wordmeaninglist.push_back(temp);
		}

		wordinput.close();

	}

	void setRandom() {
		guessedchar = std::vector<char>();
		srand(time(0));

		int i = rand() % wordlist.size();
		word = wordlist[i];
		word_meaning = wordmeaninglist[i];
		displace_word = std::string(word.length(), '-');
	}

	std::string getWord() {
		return word;
	}

	std::string getDisplay_Word() {
		return displace_word;
	}

	std::string getWord_Meaning() {
		return word_meaning;
	}

	bool guessChar(char c) {
		if (std::find(guessedchar.begin(), guessedchar.end(), c) != guessedchar.end()) {
			std::cout << "find" << std::endl;
			return false;
		}
		bool a = false;
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == c) {
				displace_word[i] = c;
				a = true;
			}
		}
		guessedchar.push_back(c);
		return a;
	}

};

