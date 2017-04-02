#include <iostream>
#include <vector>
#include <string>
#include<map>
#include<fstream>
#define SIZE 10000000
using std::string;
using std::vector;
using std::cin;

struct Query {
	string type, name;
	int number;
};

vector<std::pair<int, string>>myContacts(SIZE);
vector<Query> read_queriesMine() {
	std::ifstream in;
	in.open("in.txt");

	int n;
	in >> n;
	vector<Query> queries(n);
	for (int i = 0; i < n; ++i) {
		in >> queries[i].type;
		if (queries[i].type == "add")
			in >> queries[i].number >> queries[i].name;
		else
			in >> queries[i].number;
	}
	in.close();
	return queries;
}

vector<Query> read_queries() {
	int n;
	cin >> n;
	vector<Query> queries(n);
	for (int i = 0; i < n; ++i) {
		cin >> queries[i].type;
		if (queries[i].type == "add")
			cin >> queries[i].number >> queries[i].name;
		else
			cin >> queries[i].number;
	}
	return queries;
}
void write_responsesTrial(const vector<std::pair<int, string>>& result) {
	for (size_t i = 0; i < result.size(); ++i)
		std::cout << result[i].first << " ::" << result[i].second << "\n";
}
void write_responses(const vector<string>& result) {
	for (size_t i = 0; i < result.size(); ++i)
		std::cout << result[i] << "\n";
}
vector<string> process_queriesMine(const vector<Query>& queries) {
	vector<string> result;
	// Keep list of all existing (i.e. not deleted yet) contacts.
	vector<Query> contacts;
	contacts.resize(SIZE);
	for (size_t i = 0; i < queries.size(); ++i)
		if (queries[i].type == "add") {
			bool was_founded = false;
			// if we already have contact with such number,
			// we should rewrite contact's name
			//for (size_t j = 0; j < contacts.size(); ++j)

			if (myContacts[queries[i].number].first == queries[i].number) {
				myContacts[queries[i].number].second = queries[i].name;
				was_founded = true;
				//break;
			}
			// otherwise, just add it
			if (!was_founded){
				myContacts[queries[i].number].first == queries[i].number;
				myContacts[queries[i].number].second = queries[i].name;
			}


		}
		else if (queries[i].type == "del") {

			if (myContacts[queries[i].number].first == queries[i].number) {
				contacts.erase(contacts.begin() + queries[i].number);

			}
		}
		else {
			string response = "not found";

			if (contacts[queries[i].number].number == queries[i].number) {
				response = contacts[queries[i].number].name;

			}
			result.push_back(response);
		}
		return result;
}
vector<string> process_queriesTrial(const vector<Query>& queries) {
	vector< string> result;
	// Keep list of all existing (i.e. not deleted yet) contacts.
	std::map<int, string> contacts;

	for (size_t i = 0; i < queries.size(); ++i){

		//	std::cout << contacts[76213].number << " " << contacts[76213].name << std::endl;
		if (queries[i].type == "add") {
			bool was_founded = false;
			// if we already have contact with such number,
			// we should rewrite contact's name
			//for (size_t j = 0; j < contacts.size(); ++j)
			contacts[queries[i].number] = queries[i].name;

		}
		else if (queries[i].type == "del") {

			if (contacts[queries[i].number].length()) {
				contacts.erase(queries[i].number);

			}
		}
		else {
			string response = "not found";

			if (contacts[queries[i].number].length()) {
				response = contacts[queries[i].number];

			}
			result.push_back(response);
		}
	}
	return result;
}

vector<string> process_queries(const vector<Query>& queries) {
	vector<string> result;
	// Keep list of all existing (i.e. not deleted yet) contacts.
	vector<Query> contacts;
	contacts.resize(SIZE);
	for (size_t i = 0; i < queries.size(); ++i)
		if (queries[i].type == "add") {
			bool was_founded = false;
			// if we already have contact with such number,
			// we should rewrite contact's name
			//for (size_t j = 0; j < contacts.size(); ++j)

			if (contacts[queries[i].number].number == queries[i].number) {
				contacts[queries[i].number].name = queries[i].name;
				was_founded = true;
				//break;
			}
			// otherwise, just add it
			if (!was_founded)
				contacts[queries[i].number] = (queries[i]);

		}
		else if (queries[i].type == "del") {

			if (contacts[queries[i].number].number == queries[i].number) {
				contacts.erase(contacts.begin() + queries[i].number);

			}
		}
		else {
			string response = "not found";

			if (contacts[queries[i].number].number == queries[i].number) {
				response = contacts[queries[i].number].name;

			}
			result.push_back(response);
		}
		return result;
}

int main() {
	write_responses(process_queriesTrial(read_queries()));
	//system("pause");
	return 0;
}