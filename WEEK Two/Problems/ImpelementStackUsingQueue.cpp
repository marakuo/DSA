class nextedQueue {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int count;

public:
    nextedQueue() : front(nullptr), rear(nullptr), count(0) { }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add element to the rear
    void push(int item) {
        Node* newNode = new Node(item);  // Using Node constructor

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* delptr = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete delptr;
        count--;
    }

    int peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    int peekRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;  // or throw exception
        }
        return rear->data;
    }


    int getCount() {
        return count;
    }

    ~nextedQueue() {
        while (!isEmpty()) {
            pop();
        }
    }
};
class MyStack {
    nextedQueue q;
    public:
    void push(int x) {
        q.push(x);
        for (int i =1 ; i< q.getCount(); i++) {
            q.push(q.peekFront());
            q.pop();
        }
    }
   int pop() {
        int val = q.peekFront();
        q.pop();
        return val;
    }
    bool empty() {
        return q.isEmpty();
    }
    int top() {
        return q.peekFront();
    }


};
