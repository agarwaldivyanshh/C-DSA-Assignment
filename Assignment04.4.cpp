#include <iostream>
using namespace std;

class queuee {
    int frontt = -1, rear = -1;
    char arr[50]; // max size 50
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

    void enqueue(char value) {
        if (isfull()) {
            cout << "queue overflow! \n";
        } else if (isempty()) {
            frontt = rear = 0;
            arr[rear] = value;
        } else {
            arr[++rear] = value;
        }
    }

    char dequeue() {
        if (isempty()) {
            return '\0';
        } else {
            return arr[frontt++];
        }
    }

    char peek() {
        if (isempty()) {
            return '\0';
        } else {
            return arr[frontt];
        }
    }
};

int main() {
    queuee q1;
    string inp;
    cout << "Enter string: ";
    getline(cin, inp);

    int freq[256] = {0}; // frequency array

    cout << "Output: ";
    for (char ch : inp) {
        if (ch == ' ') continue; // ignore spaces

        freq[ch]++;        // update frequency
        q1.enqueue(ch);    // add to queue

        // pop until front is non-repeating
        while (!q1.isempty() && freq[q1.peek()] > 1) {
            q1.dequeue();
        }

        if (q1.isempty())
            cout << -1 << " ";
        else
            cout << q1.peek() << " ";
    }
    cout << endl;

    return 0;
}