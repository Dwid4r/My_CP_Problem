#include <iostream>
using namespace std;
class Stack
{
private:
    struct Node
    {
        int data{};
        Node *next{};

        Node(int data) : data(data) {}
    };
    Node *head = {};

public:
    void push(int val)
    {
        Node *item = new Node(val);
        item->next = head;
        head = item;
    }
    int pop()
    {
        int element = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return element;
    }
};

int main()
{
    Stack st;
    st.push(5);
    cout<<st.pop()<<endl;
}