#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
};

int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {

        // Ignore spaces
        if (exp[i] == ' ')
            continue;

        // If operand, push it into stack
        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        // If operator, pop two operands
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (exp[i]) {
                case '+':
                    s.push(val1 + val2);
                    break;
                case '-':
                    s.push(val1 - val2);
                    break;
                case '*':
                    s.push(val1 * val2);
                    break;
                case '/':
                    s.push(val1 / val2);
                    break;
                case '%':
                    s.push(val1 % val2);
                    break;
            }
        }
    }

    return s.pop();
}

int main() {
    string postfix;

    cout << "Enter Postfix Expression: ";
    getline(cin, postfix);

    cout << "Result = " << evaluatePostfix(postfix);

    return 0;
}