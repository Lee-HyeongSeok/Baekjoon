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
		// ������ ��ȭ���°� �ƴϰ� ����ִٸ� 1��ȯ
		if (this->topIndex == -1) {
			return 1;
		}
		return 0;
	}
	int isFull() {
		// ������ ��ȭ���°� �ƴϸ� 1��ȯ
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
		cout << "���� top : " << this->topIndex << endl;
	}
	int pop() {
		int removeStack = 0;

		// ������ ������� �ʴٸ�
		if (!isEmpty()) {
			removeStack = stackArray[this->topIndex];
			stackArray[this->topIndex--] = 0;
			return removeStack;
		}
		// ������ ���������
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