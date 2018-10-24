//Input (stdin):
//3
//Peter
//Me
//Arxwwz
//Output:
//Valid
//Too short: 2
//Invalid

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* submitted code */
class BadLengthException : public exception {
private:
	string msg;
public:
	BadLengthException(int n) : msg(to_string(n)) {
/*alternative: compile the message from parameters using a stringstream
		stringstream ss;
		ss << n;
		msg = ss.str();
*/
	}
	const char* what() const throw() { return msg.c_str(); }
};
/* end of submitted code */

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
