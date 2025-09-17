#include <iostream>
using namespace std;

int frontt = -1, rear = -1;
int queuee[5]; //max size is taken as 5 for ease of testing

bool isempty(){
    return ((frontt == -1 && rear == -1) || frontt > rear);
}

bool isfull(){
    return (rear == 5-1);
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
