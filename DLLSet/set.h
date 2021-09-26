struct Node {
    int data;
    Node *prev;
    Node *next;
};

typedef Node* pSet;

class Set {
    pSet head, tail;
    int size;

    void addToHead(int);
    void addToTail(int);
    void addByPos(int, int);

public:
    Set();
    Set(const Set&);
    ~Set();

    [[nodiscard]] int getSize() const;
    [[nodiscard]] bool isEmpty() const;
    bool inSet(int);
    int getPosByData(int);

    void print();
    void clear();

    void add(int);
    void remove(int);
    
    Set& operator=(const Set&);

    Set operator+();
    Set operator*();
    Set operator-();

    bool operator==(const Set&);
    bool operator!=(const Set&);
    bool operator<=(const Set&);
    bool operator>=(const Set&);
    bool operator>(const Set&);
    bool operator<(const Set&);
};