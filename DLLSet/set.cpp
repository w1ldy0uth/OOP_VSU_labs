#include "set.h"
#include <iostream>

Set::Set() {
    head = tail = nullptr;
    size = 0;
}
Set::Set(const Set& S) {
    head = tail = nullptr;
    size = 0;

    pSet tmp = S.head;
    while(tmp != nullptr) {
        add(tmp->data);
        tmp = tmp->next;
    }
}
Set& Set::operator=(const Set& S) {
    if(this == &S)
        return *this;
    this->~Set();

    pSet temp = S.head;

    while(temp != nullptr) {
        addToTail(temp->data);
        temp = temp->next;
    }

    return *this;
}
Set::~Set() {
    clear();
}

int Set::getSize() const{
    return size;
}
bool Set::isEmpty() const{
    return size == 0;
}
bool Set::inSet(int val) const {
    pSet ptr = head;
    while(ptr != nullptr)
        if(ptr->data == val)
            return true;
        else
            ptr = ptr->next;
    return false;
}
int Set::getPosByData(int value) {
    pSet p = head;
    int i = 1;
    while(p != nullptr) {
        if(p->data == value)
            return i;
        i++;
        p = p->next;
    }
    return -1;
}

void Set::clear() {
    while (size != 0)
        remove(1);
}

void Set::addToHead(int val) {
    pSet temp = new Node;
    temp->prev = nullptr;
    temp->data = val;
    temp->next = head;

    if(head != nullptr)
        head->prev = temp;

    if(isEmpty())
        head = tail = temp;
    else
        head = temp;
}
void Set::addToTail(int val) {
    pSet temp = new Node;
    temp->next = nullptr;
    temp->data = val;
    temp->prev = tail;

    if(tail != nullptr)
        tail->next = temp;

    if(isEmpty())
        head = tail = temp;
    else
        tail = temp;
}
void Set::addByPos(int val, int pos) {
    int i = 1;
    pSet ins = head;
    while(i<pos) {
        ins = ins->next;
        i++;
    }
    pSet prev = ins->prev;
    pSet temp = new Node;
    temp->data = val;
    if(prev != nullptr && size != 1)
        prev->next = temp;
    temp->next = ins;
    temp->prev = prev;
    ins->prev = temp;
}

void Set::add(int value) {
    pSet tmp = head;
    while(true) {
        if(tmp == nullptr) {
            addToTail(value);
            size++;
            break;
        }
        if(inSet(value))
            break;
        if(tmp->data > value) {
            int pos = getPosByData(tmp->data);
            if (pos == 1)
                addToHead(value);
            else
                addByPos(value, pos);
            size++;
            break;
        }
        if(tmp->data < value) {
            tmp = tmp->next;
        }
    }
}
void Set::remove(int pos) {
    if(pos < 1 || pos > size) {
        std::cerr << "ERROR: wrong position\n";
        return;
    }
    int cnt = 1;
    pSet del = head;
    while(cnt < pos) {
        del = del->next;
        cnt++;
    }
    pSet before = del->prev;
    pSet after = del->next;

    if(before != nullptr && size != 1)
        before->next = after;
    if(after != nullptr && size != 1)
        after->prev = before;

    if(pos == 1)
        head = after;
    if(pos == size)
        tail = before;

    delete del;
    size--;
}

std::ostream& operator<<(std::ostream &out, const Set &S) {
    out << "(";

    Set::pSet p = S.head;
    while(p->next != nullptr) {
        out << p->data << ", ";
        p = p->next;
    }

    out << p->data << ")";

    return out;
}
std::istream& operator>>(std::istream &in, Set &S) {
    int value;
    in >> value;
    S.add(value);
    return in;
}

bool operator==(const Set& C,const Set& W) {
    if(C.getSize() != W.getSize())
        return false;
    else {
        Set::pSet iterC = C.head;
        Set::pSet iterW = W.head;
        while(iterC != nullptr || iterW != nullptr) {
            if(iterC->data != iterW->data)
                return false;
            iterC = iterC->next;
            iterW = iterW->next;
        }
        return true;
    }
}
bool operator!=(const Set& C,const Set& W) {
    if(C.getSize() != W.getSize())
        return true;
    else {
        Set::pSet iterC = C.head;
        Set::pSet iterW = W.head;
        while(iterC != nullptr || iterW != nullptr) {
            if(iterC->data != iterW->data)
                return true;
            iterC = iterC->next;
            iterW = iterW->next;
        }
        return false;
    }
}

Set operator+(const Set& a, const Set& b) {
    Set result;
    Set::pSet p = a.head;
    while(p != nullptr) {
        result.add(p->data);
        p = p->next;
    }
    p = b.head;
    while(p != nullptr) {
        result.add(p->data);
        p=p->next;
    }
    return result;
}

Set operator*(const Set& a, const Set& b) {
    Set result;
    Set::pSet p = a.head;
    while(p != nullptr) {
        if(b.inSet(p->data))
            result.add(p->data);
        p = p->next;
    }
    return result;
}

Set operator-(const Set& a, const Set& b) {
    Set result;
    Set::pSet p = a.head;
    while(p != nullptr) {
        if(a.inSet(p->data) && !b.inSet(p->data))
            result.add(p->data);
        p = p->next;
    }
    return result;
}

Set operator/(const Set& a, const Set& b) {
    Set result;
    Set::pSet pA = a.head, pB = b.head;
    while(pA != nullptr) {
        result.add(pA->data);
        pA = pA->next;
    }
    while(pB != nullptr) {
        result.add(pB->data);
        pB = pB->next;
    }
    Set::pSet p = result.head;
    Set final;
    while(p != nullptr) {
        if(!(a.inSet(p->data) && b.inSet(p->data)))
            final.add(p->data);
        p = p->next;
    }
    return final;
}