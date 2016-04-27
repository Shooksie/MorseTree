#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

class MorseTree {
private:
	const char space = ' ';
	typedef struct morseNode {
		string data = "0";
		morseNode* right=NULL;
		morseNode* left=NULL;
		morseNode* parent;
	}*link;
	link root;
	link curr;
	map<char, string> morseMap;
	bool successful = true;
public:
	bool getSuccess() { return successful; }
	void addNode(string code, char data);
	void setUp();
	void readFrom(string fileinput);
	string decode(string toDecrypt);
	string encode(string toEncrypt);
	string findNode(string code);
	
};
