## Phone Number 문제

***

<br> 

### :pushpin: 문제

- 전화번호 또는 이메일이 주어지면 각 타입을 출력
- **타입**
  - type 1 : 010-1234-1234
  - type 2 : 01012341234 또는 0101231234
  - type 3 : +82-10-1234-1234
  - type 4 : abcd@naver.com
  - type -1 : +82-010-1234-1234
- **입력**
  - 010-1234-1234
- **출력**
  - type 1

<br>

### :pushpin: 코드

```c++
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
```

<br> 

### :pushpin: 정규식 풀이

- **([01]{3})-([0-9]{3,4})-([0-9]{4})**

  - [01]{3} : 0 또는 1이 3번 이상 반복
    - [01] : 0 또는 1
  - \- : 대시(dash), 기호 그대로 처리
  - ([0-9]{3,4}) : 0에서 9사이 숫자가 3번 이상, 4번 이하로 반복
  - \- : 대시(dash), 기호 그대로 처리
  - ([0-9]{4}) : 0에서 9사이 숫자가 4번 이상 반복

- **(^\\+82)-(10)-([0-9]{3,4})-([0-9]{4})**

  - (^\\+82) : 시작하는 기호가 +82일 때
  - (10) : \- 기호 다음에 10이 올 때
  - ([0-9]{3,4}) : 0에서 9사이 숫자가 3번 이상, 4번 이하 반복될 때

- **(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+**

  - (\w+) : \\w 는 알파벳, 숫자, _ 중에 한 문자임을 의미

  - (\\.|_)? : .(dot) 또는 _(under bar) 문자가 존재할 수도, 않을 수도 있음

  - (\\w*) : 알파벳, 숫자, _ 중에 한 문자가 0번 또는 그 이상 반복됨을 의미

  - @ : 기호 그대로 사용

  - (\w+) : 알파벳, 숫자, _ 중에 한 문자가 한번 이상 반복됨을 의미

  - (\\.(\w+))+ : .(dot) 뒤에 알파벳, 숫자, _ 중에 한 문자가 한번 이상 반복됨을 의미, 이가 한번 이상 반복됨을 의미

    > **ex) .org.kr.co 이런식으로**

