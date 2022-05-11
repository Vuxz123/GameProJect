#pragma once
#include <string>
#include <vector>
#include <fstream>
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

};

