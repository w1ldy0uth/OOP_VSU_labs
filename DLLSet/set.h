#include <iostream>

class Set {
    struct Node {
        int data;
        Node *prev;
        Node *next;
    };

    typedef Node* pSet;

    pSet head, tail;
    int size;

    void addToHead(int);
    void addToTail(int);
    void addByPos(int, int);

public:
    Set();
    Set(const Set&);
    ~Set();

    int getSize() const;
    bool isEmpty() const;
    bool inSet(int) const;
    int getPosByData(int);

    void clear();

    void add(int);
    void remove(int);
    
    Set& operator=(const Set&);

    friend Set operator+(const Set&, const Set&);
    friend Set operator*(const Set&, const Set&);
    friend Set operator-(const Set&, const Set&);
    friend Set operator/(const Set&, const Set&);

    friend bool operator==(const Set&, const Set&);
    friend bool operator!=(const Set&, const Set&);

    friend std::ostream& operator<<(std::ostream&, const Set&);
    friend std::istream& operator>>(std::istream&, Set&);
};