#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include "password_generation.h"
using namespace std;

password_generation pass_gen;

void saveFile(const string& fileName, unordered_map<string, string> passwords) {
	fstream file(fileName);

	for (auto& pair : passwords)
		file << pair.first << " " << pair.second << endl;

	file.close();
}
unordered_map<string, string> loadFile(const string& fileName){
	fstream file(fileName);
	unordered_map<string, string> passwords;

	while (!file.eof()) {
		string name, pass;
		file >> name >> pass;
		passwords[name] = pass;
	}
	file.close();

	return passwords;
}

void create_pass(const string& fileName) {
	unordered_map<string, string> passwords;

	string passName; cout << "Generate password for... "; cin >> passName;
	cout << endl;

	cout << endl << "Your password is:" << pass_gen.generatePass();
	cout << endl;

	passwords[passName] = pass_gen.pass;

	saveFile(fileName, passwords);
}
void add_pass(const string& fileName) {
	unordered_map<string, string> addPass;

	string passName; cout << "Enter name of the app/acc... "; cin >> passName;
	cout << endl;

	string pass; cout << "Enter password for " << passName << " ... "; cin >> pass;
	cout << endl;

	addPass[passName] = pass;

	saveFile(fileName, addPass);
}
string find_pass(const string& fileName, unordered_map<string, string> passwords) {
	string passName; cout << "Name of app/account "; cin >> passName;
	cout << endl;

	auto it = passwords.find(passName);
	if (it != passwords.end()) {
		string returnPass = passwords[passName];
		return returnPass;
	}
	else cerr << "App wasn't finded" << endl;
}

int main() {
	string pass_file = "passwords.txt";
	unordered_map<string, string> passwords = loadFile(pass_file);

	int ui = 0;
	while (true) {
		cout << "|| Enter {1} to create password..." << endl;
		cout << "|| Enter {2} to add password..." << endl;
		cout << "|| Enter {3} to find password..." << endl;
		cout << "|| Enter {0} to exit..." << endl;
		cin >> ui; cout << endl;

		switch (ui) {
		case 1:
			create_pass(pass_file);
			cout << endl;
			break;

		case 2:
			add_pass(pass_file);
			cout << endl;
			break;
		case 3:
			cout << find_pass(pass_file, passwords);
			cout << endl;
			break;
		}
		if (ui == 0) break;
	}

	cout << endl;
	system("pause");
}