//https://www.hackerrank.com/challenges/messages-order/problem
//Sample Input 0:
//Alex
//Hello Monique!
//What'up?
//Not much : (
//
//Sample Output 0:
//Alex
//Hello Monique!
//What'up?
//Not much : (
#include <iostream>
#include <string> //had to add for this to compile: cout << 'string'
#include <algorithm>
#include <vector>

using namespace std;

//Enter your code here
class Message {
private:
	string text_;
	static int order_;
	int id_;
public:
	Message() {}
	Message(const string text) : text_(text) { id_ = ++order_; }
	const string& get_text() { return text_; }
	bool operator <(Message& other) {
		return id_ < other.id_;
	}
};

int Message::order_ = 0;

class MessageFactory {
public:
	MessageFactory() {}
	Message create_message(const string& text) {
		Message m(text);
		return m;
	}
};
//End of your code

class Recipient {
public:
	Recipient() {}
	void receive(const Message& msg) {
		messages_.push_back(msg);
	}
	void print_messages() {
		fix_order();
		for (auto& msg : messages_) {
			cout << msg.get_text() << endl;
		}
		messages_.clear();
	}
private:
	void fix_order() {
		sort(messages_.begin(), messages_.end());
	}
	vector<Message> messages_;
};

class Network {
public:
	static void send_messages(vector<Message> messages, Recipient& recipient) {
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		random_shuffle(messages.begin(), messages.end());
		for (auto msg : messages) {
			recipient.receive(msg);
		}
	}
};

int main() {
	MessageFactory message_factory;
	Recipient recipient;
	vector<Message> messages;
	string text;
	while (getline(cin, text)) {
		messages.push_back(message_factory.create_message(text));
	}
	Network::send_messages(messages, recipient);
	recipient.print_messages();
}
