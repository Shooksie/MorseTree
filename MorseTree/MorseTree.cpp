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
		else {
			cout << "Invalid Symbol.  Cannot Build Morse Tree." << endl << endl;
			successful = false;
			return;
		}
	}
	curr->data = word;
}

//goes through morse tree to find value of node.
//if not a valid path, throw error
string MorseTree::findNode(string code) {
	bool found = true;
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
		else
			found = false;

	}
	if (found)
		return curr->data;
	else
		return "Invalid Path.  Cannot Find Node";
}
void MorseTree::readFrom(string input) {

	char letter;
	string code;

	ifstream fin((input + ".txt"));
	root = new morseNode;
	while (fin >> letter) {
		fin >> code;
		curr = root;

		//build map with letter as key and the code as value
		morseMap.insert(pair<char, string>(letter, code));
		addNode(code, letter);
	}
}
void MorseTree::setUp(){
	readFrom("text");
}

string MorseTree::decode(string toDecrypt) {
	string code;
	string_tokenizer ST(toDecrypt, " ");
	while (ST.has_more_tokens()) {
		string bit = ST.next_token();
		if (findNode(bit) != "Invalid Path.  Cannot Find Node")
			code += findNode(bit);
		else {
			code = "Invalid Path.  Cannot Find Node";
			break;
		}
	}

	return code;
}

string MorseTree::encode(string toEncrypt) {

	bool found;
	string code;
	map<char, string> ::iterator mapitr;

	for (int i = 0; i < toEncrypt.size(); i++) {
		found = false;
		for (mapitr = morseMap.begin(); mapitr != morseMap.end(); mapitr++) {
			if (toEncrypt[i] == mapitr->first) {
				code += mapitr->second + space;
				found = true;

			}
		}
		if (!found)
			return 	"Invalid Node. Cannot Find Code";
	}
	return code;
}
