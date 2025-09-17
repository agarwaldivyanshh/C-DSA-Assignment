#include <iostream>
using namespace std;
class queuee{
int frontt = -1, rear = -1;
int queuee[20]; //max size is taken as 5 for ease of testing
public:
bool isempty(){
    return ((frontt == -1 && rear == -1) || frontt > rear);
}

bool isfull(){
    return (rear == 20-1);
}

int size(){
    if(isempty()) return 0;
    return (rear - frontt + 1);
}

void enqueue(int value){
    if(isfull()){
        cout << "queue overflow! \n";
    }
    else if(isempty()){
        frontt = rear = 0;
        queuee[rear] = value;
    }
    else{
        queuee[++rear] = value;
    }
}

int dequeue(){
    if(isempty()){
        cout << "queue underflow! \n";
        return -1;
    }
    else if(frontt == rear){
        int x = queuee[frontt++];
        return x;
    }
    else{
        return queuee[frontt++];
    }
}

int peek(){
    if(isempty()){
        cout << "queue underflow! \n";
        return -1;
    }
    else{
        return queuee[frontt];
    }
}

void display(){
    if(isempty()){
        cout << "queue underflow! \n";
    }
    else{
        cout << "queue elements: \n";
        for(int i = frontt; i <= rear; i++){
            cout << queuee[i] << "   ";
        }
        cout << endl;
    }
}
};

int main(){
    queuee q1, q2, result;

    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q1.enqueue(x);
    }

    int half = n / 2;

    for (int i = 0; i < half; i++) {
        q2.enqueue(q1.dequeue());
    }

    // Interleave
    while (!q2.isempty() && !q1.isempty()) {
        result.enqueue(q2.dequeue());
        result.enqueue(q1.dequeue());
    }

    cout << "Interleaved queue: \n";
    result.display();

    return 0;
    
}