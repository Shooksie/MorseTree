#pragma once
#include <string>
#include "Binary_Search_Tree.h"
#include <map>

using namespace std;

class MorseTree {
private:
	vector<string>* morse;
	vector<string> binaryMorse;
	map<string, string> alphabet;
	Binary_Search_Tree<int> binaryData;
public:
	void addMorse(vector<string>* morse1) { morse = morse1; };
	void convertToBinary();
	void encrypt(string word);
	void decrypt(string morse);
	
};