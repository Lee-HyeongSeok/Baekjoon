#include <iostream>
#include <string>
#include <regex>

using namespace std;

/*
type 1 : 010-1234-1234
type 2 : 01012341234
type 3 : +82-10-1234-1234
type 4 : asd@naver.com
type -1 : +82-010-1234-1234

전화번호가 주어지면 알맞은 타입 번호를 출력
*/

class RegexClass {
private : 
	regex dashRegex;
	regex nonDashRegex;
	regex countryCodeRegex;
	regex emailRegex;
public : 
	RegexClass() {
		this->dashRegex = "([01]{3})-([0-9]{3,4})-([0-9]{4})";
		this->nonDashRegex = "([01]{3})([0-9]{3,4})([0-9]{4})";
		this->countryCodeRegex = "(^\\+82)-(10)-([0-9]{3,4})-([0-9]{4})";
		this->emailRegex = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
	}

	void checkPhoneNumber(string phoneNumber) {
		if (regex_match(phoneNumber, this->dashRegex)) {
			cout << "type 1" << endl;
		}
		else if (regex_match(phoneNumber, this->nonDashRegex)) {
			cout << "type 2" << endl;
		}
		else if (regex_match(phoneNumber, this->countryCodeRegex)) {
			cout << "type 3" << endl;
		}
		else if (regex_match(phoneNumber, this->emailRegex)) {
			cout << "type 4" << endl;
		}
		else {
			cout << "type -1" << endl;
		}
	}
};

int main() {
	string phoneNumber;
	RegexClass rcObj;
	cin >> phoneNumber;
	rcObj.checkPhoneNumber(phoneNumber);
}