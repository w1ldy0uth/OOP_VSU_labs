#include "bill.h"
#include <iostream>

int main() {
    //    Time mt0;
    //    Time mt1(12, 16, 52);
    //    Time mt2("12:16:52");
    //    Time mt3(44213);
    //    std::cout << mt0 << "\n" << mt1 << "\n" << mt2 << "\n" << mt3 << "\n\n";
    //    std::cout << mt1.toMinutes() << " " << mt1.toSeconds() << "\n\n";
    //    std::cout << (mt1 == mt2) << " " << (mt1 != mt3) << " " << (mt1 >= mt2) << " " << (mt2 <= mt3) << " " << (mt1 > mt3) << " " << (mt1 < mt2) << "\n\n";
    //    std::cout << (mt1 - mt3) << " " << (mt1 + mt3) << " " << (mt1 - 44213) << " " << (mt1 + 44213) << "\n";
    //    std::cout << (Time("12:30:56") > Time(12, 40, 21)) << "\n\n";
    Bill phoneCall("Ivanov", "+79202215263", 9, 13, Time("12:30:56"), Time(12, 40, 21));
    std::cout << phoneCall;
    return 0;
}