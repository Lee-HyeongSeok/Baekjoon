#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
class StackType {
private : 
	int top; // 현재 스택의 포인터, -1일경우 아무것도 존재하지 않음
	int size; // 현재 스택에 삽입된 자료의 개수
	int stackMaxSize;
	T *stack;
public : 
	// 생성자
	// 스택의 최대 사이즈를 생성과 동시에 인수로 전달받아서 메모리 확보
	StackType(int stackMaxSize) {
		this->stackMaxSize = stackMaxSize;
		this->stack = new T[stackMaxSize];
		this->top = -1;

		for (int i = 0; i < stackMaxSize; ++i) {
			this->stack[i] = 0;
		}
	}
	// 소멸자
	// 호출됨과 동시에 확보된 메모리 해제
	~StackType() {
		delete[] stack;
	}
	// 스택의 포화 상태를 확인하는 메서드
	bool isFull() {
		// 다음 스택의 상태를 확인
		if (this->top + 1 == this->stackMaxSize)
			return true; // 포화상태인 경우 true 반환
		return false;
	}
	// 스택의 부재 상태를 확인하는 메서드
	bool isEmpty() {
		if (this->top < 0) // 스택을 가르키는 top 매개변수가 -1이라면 스택은 부재 상태
			return true;
		return false;
	}

	// 스택에 자료를 삽입하는 메서드
	void push(T value) {
		if (!isFull()) {
			stack[++(this->top)] = value;
		}
		else
			cout << "stack overflow" << endl;
	}
	// 스택에 들어온 가장 마지막 자료를 반환하고 삭제하는 메서드
	void pop() {
		if (!isEmpty())
			stack[this->top--] = 0;
		else
			cout << "stack is empty" << endl;
	}

	void printStack() {
		int sum = 0;
		for (int i = 0; i < this->top + 1; ++i) {
			sum += this->stack[i];
		}
		cout << sum << endl;
	}
};

int main() {
	int K = 0, inputValue = 0;
	cin >> K;

	StackType<int> stackType(K);

	while (K--) {
		cin >> inputValue;

		// 입력된 값이 0이 아니라면
		if (inputValue) {
			stackType.push(inputValue);
		}
		// 입력된 값이 0일 경우
		else {
			stackType.pop();
		}
	}

	stackType.printStack();
}