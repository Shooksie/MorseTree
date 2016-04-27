#include "MorseTree.h"
#include "String_Tokenizer.h"
#include "Syntax_Error.h"
#include <iostream>
using namespace std;

void MorseTree::addNode(string code, char word) {
	string::iterator itr;
	string codes = "._";
	for (itr = code.begin(); itr != code.end(); itr++) {
		if (*itr == codes[1]) {
			if (curr->right == NULL) {
				curr->right = new morseNode;
				curr->right->parent = curr;
			}
			curr = curr->right;
		}
		else if (*itr == codes[0]) {
			if (curr->left == NULL) {
				curr->left = new morseNode;
				curr->left->parent = curr;
			}
			curr = curr->left;
		}
	}
	curr->data = word;
}
string MorseTree::findNode(string code) {
	curr = root;
	string::iterator itr;
	string codes = "._";
	for (itr = code.begin(); itr != code.end(); itr++) {
		if (*itr == codes[1]) {
			curr = curr->right;
		}
		else if (*itr == codes[0]) {
			curr = curr->left;
		}

	}
	return curr->data;
}
void MorseTree::readFrom(string input) {

	char letter;
	string code;

	ifstream fin((input + ".txt"));
	root = new morseNode;
	while (fin >> letter) {
		fin >> code;
		curr = root;
		morseMap.insert(pair<char, string>(letter, code));
		// add node to make quicker..
		addNode(code, letter);
	}
}
void MorseTree::setUp(){
	readFrom("text");
}

string MorseTree::decode(string toDecrypt) {
	string code;
	code += findNode(toDecrypt);
	return code;
}

string MorseTree::tokenize(string toToken) {
	string code;
	string_tokenizer ST(toToken, space);
	while (ST.has_more_tokens()) {
		string bit = ST.next_token();
		code +=decode(bit);
	}
	return code;
}
string MorseTree::encode(string toEncrypt) {


	string code;
	map<char, string> ::iterator mapitr;

	for (int i = 0; i < toEncrypt.size(); i++) {
		for (mapitr = morseMap.begin(); mapitr != morseMap.end(); mapitr++) {
			if (toEncrypt[i] == mapitr->first) {
				code += mapitr->second + space;
				// have a const variable instead of a " " for space

			}
		}
	}
	return code;
}
