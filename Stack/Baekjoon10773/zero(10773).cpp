#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
class StackType {
private : 
	int top; // ���� ������ ������, -1�ϰ�� �ƹ��͵� �������� ����
	int size; // ���� ���ÿ� ���Ե� �ڷ��� ����
	int stackMaxSize;
	T *stack;
public : 
	// ������
	// ������ �ִ� ����� ������ ���ÿ� �μ��� ���޹޾Ƽ� �޸� Ȯ��
	StackType(int stackMaxSize) {
		this->stackMaxSize = stackMaxSize;
		this->stack = new T[stackMaxSize];
		this->top = -1;

		for (int i = 0; i < stackMaxSize; ++i) {
			this->stack[i] = 0;
		}
	}
	// �Ҹ���
	// ȣ��ʰ� ���ÿ� Ȯ���� �޸� ����
	~StackType() {
		delete[] stack;
	}
	// ������ ��ȭ ���¸� Ȯ���ϴ� �޼���
	bool isFull() {
		// ���� ������ ���¸� Ȯ��
		if (this->top + 1 == this->stackMaxSize)
			return true; // ��ȭ������ ��� true ��ȯ
		return false;
	}
	// ������ ���� ���¸� Ȯ���ϴ� �޼���
	bool isEmpty() {
		if (this->top < 0) // ������ ����Ű�� top �Ű������� -1�̶�� ������ ���� ����
			return true;
		return false;
	}

	// ���ÿ� �ڷḦ �����ϴ� �޼���
	void push(T value) {
		if (!isFull()) {
			stack[++(this->top)] = value;
		}
		else
			cout << "stack overflow" << endl;
	}
	// ���ÿ� ���� ���� ������ �ڷḦ ��ȯ�ϰ� �����ϴ� �޼���
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

		// �Էµ� ���� 0�� �ƴ϶��
		if (inputValue) {
			stackType.push(inputValue);
		}
		// �Էµ� ���� 0�� ���
		else {
			stackType.pop();
		}
	}

	stackType.printStack();
}