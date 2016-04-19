#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

class MorseTree {
private:
	typedef struct morseNode {
		string data = "0";
		morseNode* right=NULL;
		morseNode* left=NULL;
		morseNode* parent;
	}*link;
	link root;
	link curr;
	map<string, string> morseMap;
	vector<string> alpha;
public:
	void addNode(string code, string data);
	void setUp();
	void readFrom(string fileinput);
	string findNode(string code);
	
};