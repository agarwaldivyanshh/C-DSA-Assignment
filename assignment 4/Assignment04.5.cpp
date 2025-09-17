#include <iostream>
using namespace std;

class queuee {
    int frontt = -1, rear = -1;
    int arr[200]; // max size
public:
    bool isempty() {
        return ((frontt == -1 && rear == -1) || frontt > rear);
    }

    bool isfull() {
        return (rear == 50 - 1);
    }

    int size() {
        if (isempty()) return 0;
        return (rear - frontt + 1);
    }

    void enqueue(int value) {
        if (isfull()) {
            cout << "Queue overflow!\n";
        } else if (isempty()) {
            frontt = rear = 0;
            arr[rear] = value;
        } else {
            arr[++rear] = value;
        }
    }

    int dequeue() {
        if (isempty()) {
            cout << "Queue underflow!\n";
            return -1;
        } else {
            return arr[frontt++];
        }
    }

    int peek() {
        if (isempty()) {
            cout << "Queue empty!\n";
            return -1;
        }
        return arr[frontt];
    }
};

// ------------------ STACK USING TWO QUEUES ------------------
class StackTwoQ {
    queuee q1, q2;
public:
    void push(int x) {
        // enqueue to empty q2
        q2.enqueue(x);

        // move all q1 to q2
        while (!q1.isempty()) {
            q2.enqueue(q1.dequeue());
        }

        // swap q1 and q2
        queuee temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop() {
        if (q1.isempty()) {
            cout << "Stack underflow!\n";
            return -1;
        }
        return q1.dequeue();
    }

    bool isempty() {
        return q1.isempty();
    }
};

// ------------------ STACK USING ONE QUEUE ------------------
class StackOneQ {
    queuee q;
public:
    void push(int x) {
        int sz = q.size();
        q.enqueue(x);

        // rotate the queue
        for (int i = 0; i < sz; i++) {
            q.enqueue(q.dequeue());
        }
    }

    int pop() {
        if (q.isempty()) {
            cout << "Stack underflow!\n";
            return -1;
        }
        return q.dequeue();
    }

    bool isempty() {
        return q.isempty();
    }
};

// ------------------ main() ------------------
int main() {
    cout << "Stack using Two Queues:\n";
    StackTwoQ s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl; 

    cout << "\nStack using One Queue:\n";
    StackOneQ s2;
    s2.push(5);
    s2.push(15);
    s2.push(25);
    cout << s2.pop() << endl;
    cout << s2.pop() << endl; 
    cout << s2.pop() << endl; 

    return 0;
}