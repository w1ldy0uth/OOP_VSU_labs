#include "rational.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<Rational> storage;
    int choice;
    cout << "1. Create a fraction;\n2. List of fractions;\n3. Delete a fraction;\n4. Sum of fractions;\n5. Subtraction of fractions;\n";
    cout << "6. Multiplication of fraction;\n7. Division of fractions;\n8. Comparing of fractions\n0. Exit;\n";
    while (true) {
        cout << "\nEnter a number: ";
        cin >> choice;
        switch (choice) {
            case 0: {
                cout << "Exiting...\n";
                return 0;
            }
            case 1: {
                cout << "\nEnter numerator and denominator through a space: ";
                int num, den;
                cin >> num >> den;
                Rational def(num, den);
                storage.push_back(def);
                cout << "Successfully created\n";
                break;
            }
            case 2: {
                if (storage.empty()) {
                    cout << "You haven't created any fractions yet. Pick 1 at the menu to create new one.\n";
                    break;
                }
                int counter = 1;
                for (auto i: storage) {
                    cout << counter << ". " << i.toString() << "\n";
                    counter++;
                }
                break;
            }
            case 3: {
                if (storage.empty()) {
                    cerr << "Error: no fractions found to delete\n";
                    break;
                }
                cout << "Enter a number of a fraction that you want to delete: ";
                int num;
                cin >> num;
                if (storage.size() < num) {
                    cerr << "Error: no such fraction in list\n";
                    break;
                }
                storage.erase(storage.begin() + (num-1));
                cout << "Successfully deleted\n";
                break;
            }
            case 4: {
                cout << "Pick two fractions from a list and enter their numbers trough a space: ";
                int fst, scd;
                cin >> fst >> scd;
                if (fst > storage.size() || scd > storage.size()) {
                    cerr << "Error: no such fraction in list\n";
                    break;
                }
                Rational first = storage[fst-1], second = storage[scd-1];
                Rational res = first.sum(second);
                cout << first.toString() << " + " << second.toString() << " = " << res.toString() << "\n";
                break;
            }
            case 5: {
                cout << "Pick a minuend first and a subtrahend second from a list and enter their numbers trough a space: ";
                int fst, scd;
                cin >> fst >> scd;
                if (fst > storage.size() || scd > storage.size()) {
                    cerr << "Error: no such fraction in list\n";
                    break;
                }
                Rational first = storage[fst-1], second = storage[scd-1];
                Rational res = first.sub(second);
                cout << first.toString() << " - " << second.toString() << " = " << res.toString() << "\n";
                break;
            }
            case 6: {
                cout << "Pick two fractions from a list and enter their numbers through a space: ";
                int fst, scd;
                cin >> fst >> scd;
                if (fst > storage.size() || scd > storage.size()) {
                    cerr << "Error: no such fraction in list\n";
                    break;
                }
                Rational first = storage[fst-1], second = storage[scd-1];
                Rational res = first.mul(second);
                cout << first.toString() << " * " << second.toString() << " = " << res.toString() << "\n";
                break;
            }
            case 7: {
                cout << "Pick a dividend first and a divider second from a list and enter their numbers trough a space: ";
                int fst, scd;
                cin >> fst >> scd;
                if (fst > storage.size() || scd > storage.size()) {
                    cerr << "Error: no such fraction in list\n";
                    break;
                }
                Rational first = storage[fst-1], second = storage[scd-1];
                Rational res = first.div(second);
                cout << first.toString() << " : " << second.toString() << " = " << res.toString() << "\n";
                break;
            }
            case 8: {
                cout << "Pick two fractions from a list and enter their numbers trough a space: ";
                int fst, scd;
                cin >> fst >> scd;
                if (fst > storage.size() || scd > storage.size()) {
                    cerr << "Error: no such fraction in list";
                    break;
                }
                Rational first = storage[fst-1], second = storage[scd-1];
                if (first.equal(second))
                    cout << first.toString() << " == " << second.toString() << "\n";
                else if (first.greater(second))
                    cout << first.toString() << " > " << second.toString() << "\n";
                else if (first.less(second))
                    cout << first.toString() << " < " << second.toString() << "\n";
                break;
            }
            default:
                cout << "Wrong menu number, try again.\n";
                break;
        }
    }
}