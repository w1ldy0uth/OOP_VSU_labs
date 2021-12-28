#include <iostream>

template <typename T>
struct QNode {
    T data;
    QNode<T>* prev;
    QNode<T>* next;
};

template <class T>
class Queue {
    QNode<T> *head, *tail;
    int size;

public:
    Queue(): head(nullptr), tail(nullptr), size(0) {};
    ~Queue();
    Queue(const Queue&);
    Queue<T>& operator=(const Queue&);

    void push(T);
    void pop();

    bool empty() {return size == 0;};

    T front() {return head->data;};
    T back() {return tail->data;};
};

template <typename T>
Queue<T>::~Queue() {
    while(!empty())
        pop();
}

template <typename T>
Queue<T>::Queue(const Queue<T> &other) {
    head = tail = nullptr;
    size = 0;

    QNode<T>* tmp = other.head;
    while(tmp != nullptr) {
        push(tmp->data);
        tmp = tmp->next;
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other) {
    if(this == &other)
        return *this;

    this->~Queue();

    QNode<T>* tmp = other.head;
    while(tmp != nullptr) {
        push(tmp->data);
        tmp = tmp->next;
    }

    return *this;
}

template <typename T>
void Queue<T>::push(T item) {
    QNode<T>* tmp = new QNode<T>;
    tmp->data = item;
    size++;

    if (!head) {
        head = tmp;
        tail = head;
    }
    else {
        tmp ->next = head;
        head->prev = tmp;
        head = tmp;
    }
}

template <typename T>
void Queue<T>::pop() {
    if (head->next) {
        QNode<T>* tmp = head;
        head = head->next;
        head->prev = nullptr;
        delete tmp;
        size--;
    }
    else if (head == tail) {
        head->next = nullptr;
        head = nullptr;
        delete head;
        size--;
    }
}