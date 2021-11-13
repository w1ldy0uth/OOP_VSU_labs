#include "time.h"
#include <sstream>
#include <iostream>
#include <string>

class Bill {
    std::string surname;
    std::string number;
    int rate;
    int discount;
    Time callBegin;
    Time callEnd;

public:
    Bill();
    Bill(std::string, std::string, int, int, Time, Time);

    std::string getSurname();
    std::string getNumber();
    int getRate() const;
    int getDiscount() const;
    Time getCallBegin();
    Time getCallEnd();
    void setSurname(std::string);
    void setNumber(std::string);
    void setRate(int);
    void setDiscount(int);
    void setCallBegin(Time);
    void setCallEnd(Time);

    double getTotalAmount() const;

    friend std::ostream& operator<<(std::ostream&, Bill&);
};
