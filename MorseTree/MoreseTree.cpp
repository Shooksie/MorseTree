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

	while (fin >> letter) {
		fin >> code;
		morseMap.insert(pair<char, string>(letter, code));
		alpha.push_back(letter);
	}
}
void MorseTree::setUp(){
	readFrom("text");
	
	root = new morseNode;
	root->right = NULL;
	for (int i = 0; i < alpha.size(); i++) {
		curr = root;
		addNode(morseMap[alpha[i]], alpha[i]);
	}
}

void MorseTree::decode(string toDecrypt) {
	string_tokenizer ST(toDecrypt, " ");
	while (ST.has_more_tokens()) {
		string bit = ST.next_token();
		cout << findNode(bit);
	}

	cout << endl << endl;
}

void MorseTree::encode(string toEncrypt) {


	map<char, string> ::iterator mapitr;

	for (int i = 0; i < toEncrypt.size(); i++) {
		for (mapitr = morseMap.begin(); mapitr != morseMap.end(); mapitr++) {
			if (toEncrypt[i] == mapitr->first) {
				cout << mapitr->second << " ";

			}
		}
	}
	cout << endl << endl;
}
