#include <iostream>
#include <string>
using namespace std;

string form;

class LostParenthesisClass {
public : 
	void findMinOfValue(string virtualForm) {
		bool isMinus = false;
		int result = 0;
		string temp;

		// ���̳ʽ� �ڿ� �÷��� ��ȣ�� ���̳ʽ��� �ٲپ� ����ϸ� �ȴ�.
		// 55-50+40 -> 55-(50+40) -> 55-50-40
		for (int i = 0; i <= virtualForm.size(); ++i) {
			if (virtualForm[i] == '+' || virtualForm[i] == '-' || virtualForm[i] == '\0') {
				if (isMinus) { // ���̳ʽ����
					result -= stoi(temp);
				}
				else {
					result += stoi(temp);
				}

				temp = "";
				if (virtualForm[i] == '-')
					isMinus = true;
			}
			else {
				temp += virtualForm[i];
			}
		}

		cout << result << endl;
	}
};

int main() {
	cin >> form;
	LostParenthesisClass lpcObj;
	lpcObj.findMinOfValue(form);
}