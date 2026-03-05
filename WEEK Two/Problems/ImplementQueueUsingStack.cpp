class Stack {
public:
    struct Node {
        int Data;
        Node* Next;
    };
    Node*top;
    Stack():top(nullptr) {  }
    // isEmpty
    bool isEmpty() {
        return (top == nullptr);
    }
    //push
    void push(int element) {
        Node*newNode = new Node;
        newNode->Data = element;
        newNode->Next = top;
        top = newNode;

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

    int peek() {
        return top->Data;
    }
    // counter
    int counter() {
        int counter =0;
        Node*temp = top;
        while (temp !=nullptr) {
            counter++;
            temp = temp->Next;
        }
        return counter;
    }
};
    class MyQueue {
        Stack input;
        Stack output;


    public:
        MyQueue() {

        }

        void push(int x) {
            input.push(x);

        }

        int pop() {
            int val;

            if (!output.isEmpty()) {
                val = output.peek();
                output.pop();
            }else{
                while (!input.isEmpty()) {
                    output.push(input.peek());
                    input.pop();
                }
                val = output.peek();
                output.pop();

            }
           return val;


        }

        int peek() {


            if (!output.isEmpty()) {

                return output.peek();
            }else{
                while (!input.isEmpty()) {
                    output.push(input.peek());
                    input.pop();
                }

                return output.peek();

            }

        }

        bool empty() {
            return output.isEmpty() && input.isEmpty();



        }
    };
