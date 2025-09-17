// circular queue
#include <iostream>
using namespace std;

int frontt = -1, rear = -1;
const int MAX_LEN = 5;
int queuee[MAX_LEN]; //max size is taken as 5 for ease of testing

bool isempty(){
    return ((frontt == rear) && (rear == -1));
}

bool isfull(){
    return (frontt == (rear+1) % MAX_LEN);
}

int size(){
    if(isempty()) return 0;
    if(rear>=frontt) return (rear - frontt + 1);
    else return MAX_LEN - (frontt - rear - 1);
}

void enqueue(int value){
    if(isfull()){
        cout << "queue overflow! \n";
    }
    else{
        rear = (rear + 1)%MAX_LEN;
        queuee[rear]=value;
        if(frontt==-1) frontt=0;
    }
}

int dequeue(){
    if(isempty()){
        cout << "queue underflow! \n";
           return -1;
    }
    else{
        int item = queuee[frontt];
        if(frontt==rear) {
            frontt = rear = -1;
        }
        else frontt = (frontt+1) % MAX_LEN;
        return item;
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
        int i = frontt;
        while(true){
            cout << queuee[i] << "   ";
            if(i == rear) break;
            i = (i + 1) % MAX_LEN;
        }
        cout << endl;
    }
}

int main(){
    int choice, value;
    while(true){
        cout << "1 enqueue \n2 dequeue \n3 isempty \n4 isfull \n5 size \n6 peek \n7 display \n8 exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                cout << "Dequeued: " << dequeue() << endl;
                break;
            case 3:
                cout << (isempty() ? "queue is empty\n" : "queue is not empty\n");
                break;
            case 4:
                cout << (isfull() ? "queue is full\n" : "queue is not full\n");
                break;
            case 5:
                cout << "queue size: " << size() << endl;
                break;
            case 6:
                cout << "Front element (peek): " << peek() << endl;
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}