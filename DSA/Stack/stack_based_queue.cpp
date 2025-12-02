#include <iostream>
#include <cassert>
using namespace std;

class queue
{
    int size{};
    int front{0};
    int rear{0};
    int added_elements{};
    int *array{};

public:
    queue(int size) : size(size)
    {
        array = new int[size];
    }

    ~queue()
    {
        delete[] array;
    }

    int next(int pos)
    {
        return (pos + 1 == size ? 0 : pos + 1);
    }

    void enqueue(int value)
    {
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        added_elements++;
    }

    int dequeue()
    {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        added_elements--;
        return value;
    }

    bool isEmpty()
    {
        return added_elements == 0;
    }

    bool isFull()
    {
        return added_elements == size;
    }

    int count() { return added_elements; }
};

class Stack
{
private:
    queue qe;
    int add_element{};

public:
    Stack(int n) : qe(n) {}

    void push(int val)
    {
        // Step 1: enqueue new value
        qe.enqueue(val);

        // Step 2: rotate old elements
        for (int i = 0; i < add_element; i++)
            qe.enqueue(qe.dequeue());

        // Now size increases
        add_element++;
    }

    int pop()
    {
        assert(add_element > 0);
        add_element--;
        return qe.dequeue();
    }
};

int main()
{
    Stack st(10);

    st.push(5);
    st.push(7);
    st.push(9);

    cout << st.pop() << "\n"; // 9
    cout << st.pop() << "\n"; // 7
    cout << st.pop() << "\n"; // 5

    return 0;
}
