#include <iostream>
#include <string>
using namespace std;
/*
 * Pointer based implementation
 * =======================
 * =  value + pointer    =  => node
 * =======================
 */
template <class t>

// Linked Stack
class Stack {
public:
    struct Node {
        t Data;
        Node* Next; // initially pointing to the node
    };
    Node*top; // initially pointing to the node
    Stack():top(nullptr) {  } // initializing top
    // isEmpty
    bool isEmpty() {
        return (top == nullptr);
    }
    //push
    void push(t element) {
        Node*newNode = new Node;
        newNode->Data = element;
        newNode->Next = top;
        top = newNode;
    
    }
// display 
    void display() {
        Node*temp = top;
        while (temp != nullptr) {
            cout << temp->Data << " ";
            temp = temp->Next;

        }
        cout<<endl;
    }
    // pop
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            Node*delptr =top;
            top = top->Next;
            delete delptr;

        }
    }
    //peek
    t peek() {
        return top->Data;
    }
    // counter
    t counter() {
        int counter =0;
        Node*temp = top;
        while (temp !=nullptr) {
            counter++;
            temp = temp->Next;
        }
        return counter;
    }
    // search
    bool isFound(t item) {
        bool found = false;
        Node*temp = top;
        while (temp !=nullptr) {
            if (item == temp->Data) {
                found = true;
            }
            temp = temp->Next;

        }
        return found;
    }

};






int main() {
    Stack<int> s;
    int n;
    for (int i =0; i<=3 ; i++) {
        cout << "enter an element: ";
        cin >>n;
        s.push(n);
        s.display();

    }

    cout << s.pop()<<" this item was deleted"<<endl;
    s.display();
    cout << s.pop()<<" this item was deleted"<<endl;
    s.display();
    cout <<"counter is " <<s.counter()<<endl;
    if (s.isFound(5)) {
        cout<< "is found "<<endl;

    }
    else cout <<"not found";




    return 0;
}
