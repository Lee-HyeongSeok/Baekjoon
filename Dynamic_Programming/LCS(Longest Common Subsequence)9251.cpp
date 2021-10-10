#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 1001

int stringDP[MAXN][MAXN];

class LcsClass {
private : 
	string str1;
	string str2;
public : 
	void init() {
		cin >> str1 >> str2;
	}

	void findCommonLCS() {
		int i, j;

		for (i = 1; i <= str2.size(); ++i) {
			for (j = 1; j <= str1.size(); ++j) {
				if (str2[i-1] == str1[j-1]) {
					stringDP[i][j] = stringDP[i - 1][j - 1] + 1;
				}
				else {
					stringDP[i][j] = max(stringDP[i][j - 1], stringDP[i - 1][j]);
				}
			}
		}
		cout << stringDP[str2.size()][str1.size()] << endl;
	}
};

//int main() {
//	LcsClass lcObj;
//	lcObj.init();
//	lcObj.findCommonLCS();
//}