#include "MorseTree.h"
#include <iostream>
#include <iomanip>
using namespace std;

void main() {
	MorseTree tree;
	tree.setUp();



	string decode = "_..  __.";
	string decode1 = "_.. &  __.";
	string decode2 = "_.. . _._. ___ _.. . ._.";

	string encode = "ac";
	string encode1 = "Ac";
	string encode2 = "encoder";

	if (tree.getSuccess()) {
		cout << setw(15) << "MORSE CODE" << endl <<
			"====================" << endl << endl;

		cout << "Decoding: " << decode << " ==> " << tree.decode(decode) << endl;
		cout << "Decoding: " << decode1 << " ==> " << tree.decode(decode1) << endl;
		cout << "Decoding: " << decode2 << " ==> " << tree.decode(decode2) << endl << endl;

		cout << "Encoding: " << encode << " ==> " << tree.encode(encode) << endl;
		cout << "Encoding: " << encode1 << " ==> " << tree.encode(encode1) << endl;
		cout << "Encoding: " << encode2 << " ==> " << tree.encode(encode2) << endl << endl;

	}

	system("pause");
	return;
}	
