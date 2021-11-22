## **백준 10828번 - 스택 문제**

***

<br> 

### :pushpin: 성공한 코드

```c++
#include <iostream>
#include <string>

using namespace std;

#define MAXN 10001

int stackArray[MAXN];

class StackClass {
private : 
	int topIndex;
public : 
	StackClass() {
		this->topIndex = -1;
	}
	int isEmpty() {
		// 스택이 포화상태가 아니고 비어있다면 1반환
		if (this->topIndex == -1) {
			return 1;
		}
		return 0;
	}
	int isFull() {
		// 스택이 포화상태가 아니면 1반환
		if (this->topIndex != MAXN) {
			return 1;
		}
		return 0;
	}
	void push(int X) {
		if (isFull()) {
			stackArray[++(this->topIndex)] = X;
		}
		else {
			cout << "Stack is Full & Not empty" << endl;
		}
	}
	int pop() {
		int removeStack = 0;

		// 스택이 비어있지 않다면
		if (!isEmpty()) {
			removeStack = stackArray[this->topIndex];
			stackArray[this->topIndex--] = 0;
			return removeStack;
		}
		// 스택이 비어있으면
		else {
			return -1;
		}
	}
	int size() {
		return this->topIndex+1;
	}
	int top() {
		if (this->topIndex == -1) {
			return -1;
		}
		return stackArray[this->topIndex];
	}
};

int main() {
	int testCase = 0, X = 0;
	string operation;
	StackClass scObj;

	cin >> testCase;

	while (testCase--) {
		cin >> operation;

		if (operation == "push") {
			cin >> X;
			scObj.push(X);
		}
		else if (operation == "pop") {
			cout << scObj.pop() << endl;
		}
		else if (operation == "top") {
			cout << scObj.top() << endl;
		}
		else if (operation == "empty") {
			cout << scObj.isEmpty() << endl;
		}
		else if (operation == "size") {
			cout << scObj.size() << endl;
		}
		operation.clear();
	}
}
```



<br> 

### :pushpin: 해결 방법

- **push 명령어 수행 시**
  - 스택의 포화 상태만 체크하면 된다.
  - isFull() 함수를 사용한 포화 상태 체크
  - 가장 마지막 인덱스를 대표하는 topIndex 변수를 전위 증가하면서 스택에 정수 삽입
- **pop 명령어 수행 시**
  - 스택의 부재 상태만 확인하면 된다.
  - isEmpty() 함수를 사용한 부재 상태 체크
  - pop 명령어 수행 이후 LIFO 알고리즘으로 인해 가장 마지막에 저장된 정수를 반환하고<br> 스택에서 제거

