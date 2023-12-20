#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;


class password_generation
{
private:	vector<string> loadCards(const string& fileName) {
		vector<string> cards;
		ifstream file(fileName);

		if (file.is_open()) {
			string card;

			while (getline(file, card))
				cards.push_back(card);
			file.close();
		}
		else cerr << "File wans't open" << endl;

		return cards;
	}

private:	string randomCombo(const string& fileName, int passSize) {
		string file = fileName;
		string pass;
		vector<string> cards = loadCards(file);

		srand(time(NULL));

		for (int i = 0; i < passSize; i++) {
			int randIdx = rand() % cards.size();
			pass += cards[randIdx];
		}

		return pass;
	}

public: string pass;
public: string generatePass() {
		string fileName = "cards.txt";

		cout << "Input size of the password(min size == 3 / max size != 20): " << endl;
		int passSize = 0;
		while (passSize < 3 || passSize > 20) {
			cin >> passSize;

			if (passSize >= 3 && passSize <= 20)
				break;
		}
		pass = randomCombo(fileName, passSize);
		return pass;
	}
};

