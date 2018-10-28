//https://www.hackerrank.com/challenges/magic-spells/problem
//LCS problem: https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
//Sample Input:
//3
//fire 5
//AquaVitae 999 AruTaVae
//frost 7
//
//Sample Output:
//Fireball : 5
//6
//Frostbite : 7

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
	string scrollName;
public:
	Spell() : scrollName("") { }
	Spell(string name) : scrollName(name) { }
	virtual ~Spell() { }
	string revealScrollName() {
		return scrollName;
	}
};

class Fireball : public Spell {
private: int power;
public:
	Fireball(int power) : power(power) { }
	void revealFirepower() {
		cout << "Fireball: " << power << endl;
	}
};

class Frostbite : public Spell {
private: int power;
public:
	Frostbite(int power) : power(power) { }
	void revealFrostpower() {
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private: int power;
public:
	Thunderstorm(int power) : power(power) { }
	void revealThunderpower() {
		cout << "Thunderstorm: " << power << endl;
	}
};

class Waterbolt : public Spell {
private: int power;
public:
	Waterbolt(int power) : power(power) { }
	void revealWaterpower() {
		cout << "Waterbolt: " << power << endl;
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;
	}
};
string SpellJournal::journal = "";
/* recursive solution for LCS problem - too expensive: O(2^n)
int similar(string str1, string str2)
{
	if (str1.size() == 0 || str2.size() == 0) return 0;
	if (str1[0] == str2[0]) return 1 + similar(str1.substr(1), str2.substr(1));
	int nleft = similar(str1, str2.substr(1));
	int nright = similar(str1.substr(1), str2);
	return nright > nleft ? nright : nleft;
}
*/
void counterspell(Spell *spell) {
/* Enter your code here */
	if (Fireball* new_spell = dynamic_cast<Fireball*>(spell))
		new_spell->revealFirepower();
	else if (Frostbite* new_spell = dynamic_cast<Frostbite*>(spell))
		new_spell->revealFrostpower();
	else if (Waterbolt* new_spell = dynamic_cast<Waterbolt*>(spell))
		new_spell->revealWaterpower();
	else if (Thunderstorm* new_spell = dynamic_cast<Thunderstorm*>(spell))
		new_spell->revealThunderpower();
	else if (Spell* new_spell = dynamic_cast<Spell*>(spell))
	{
		string name1 = new_spell->revealScrollName(); 
		int l1 = name1.size();
		string name2 = SpellJournal::read();
		int l2 = name2.size();
		vector<vector <int>> V(l1 + 1, vector<int>(l2 + 1, 0)); // (l1+1)x(l2+1), initialized with 0s
		for (int i = 1; i < l1 + 1; i++)
			for (int j = 1; j < l2 + 1; j++)
				if (name1[i - 1] == name2[j - 1])
					V[i][j] = V[i - 1][j - 1] + 1;
				else
					V[i][j] = V[i][j - 1] > V[i - 1][j] ? V[i][j - 1] : V[i - 1][j]; //max function is in <algorythm> and is not available for this problem
		cout << V[l1][l2] << endl;
	}
}

class Wizard {
public:
	Spell *cast() {
		Spell *spell;
		string s; cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell *spell = Arawn.cast();
		counterspell(spell);
	}

	getchar();
	getchar();

	return 0;
}