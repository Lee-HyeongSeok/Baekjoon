#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	multimap<int, string> m;

	int test = 0;
	scanf("%d", &test);

	int Key;
	string Value;

	
	for (int i = 0; i < test; i++) {
		cin >> Key >> Value;
		m.insert(pair<int, string>(Key, Value));
	}

	multimap<int, string>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
	
	return 0;
}