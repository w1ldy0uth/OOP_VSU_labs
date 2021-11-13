#include "bill.h"

Bill::Bill() {
    surname = "default_surname";
    number = "default_number";
    rate = 0;
    discount = 0;
    callBegin = Time();
    callEnd = Time();
}

Bill::Bill(std::string _surname, std::string _number, int _rate, int _discount, Time _callBegin, Time _callEnd) {
    surname = std::move(_surname);
    number = std::move(_number);
    rate = _rate;
    discount = _discount;
    callBegin = _callBegin;
    callEnd = _callEnd;
    if (callEnd.toSeconds() < callBegin.toSeconds())
        std::swap(callBegin, callEnd);
}

std::string Bill::getSurname() {
    return surname;
}

void Bill::setSurname(std::string _surname) {
    surname = std::move(_surname);
}

std::string Bill::getNumber() {
    return number;
}

void Bill::setNumber(std::string _number) {
    number = std::move(_number);
}

int Bill::getRate() const {
    return rate;
}

void Bill::setRate(int _rate) {
    rate = _rate;
};

int Bill::getDiscount() const {
    return discount;
}

void Bill::setDiscount(int _discount) {
    discount = _discount;
    if (discount < 0) {
        discount = std::abs(discount);
        std::clog << "WARNING: discount cannot be negative; automatically been set to absolute value\n";
    }
    if (discount > 100) {
        discount %= 100;
        std::clog << "WARNING: discount cannot be bigger than 100; automatically been set to modulo 100 division value\n";
    }
}

Time Bill::getCallBegin() {
    return callBegin;
}

void Bill::setCallBegin(Time _callBegin) {
    callBegin = _callBegin;
    if (callBegin > callEnd)
        std::swap(callBegin, callEnd);
}

Time Bill::getCallEnd() {
    return callEnd;
}

void Bill::setCallEnd(Time _callEnd) {
    callBegin = _callEnd;
    if (callBegin > callEnd)
        std::swap(callBegin, callEnd);
}

double Bill::getTotalAmount() const {
    int callDuration = (int)(callEnd.toMinutes() - callBegin.toMinutes());
    if (discount != 0)
        return callDuration * ((double)rate * discount / 100);
    else
        return callDuration * rate;
}

std::ostream& operator<<(std::ostream& out, Bill& call) {
    out << "Bill for a phone call" << "\n========================\n";
    out << "Caller: " << call.surname << "\n";
    out << "Number: " << call.number << "\n\n";
    out << "Time of conversation: " << (int)(call.callEnd.toMinutes() - call.callBegin.toMinutes()) << " minutes";
    out << " (" << call.callBegin << " - " << call.callEnd << ")\n\n";
    out << "Rate: " << call.rate << " rub\\min\n";
    out << "Discount: " << call.discount << "%\n------------------------\n";
    out << "Total cost of phone call - " << call.getTotalAmount() << " rub\n";
    return out;
}
