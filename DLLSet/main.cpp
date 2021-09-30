#include "set.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::string info = "\n1. Create a set\n2. Show existing sets\n3. Delete a set\n4. Add to a set\n5. Remove from a set\n6. Union of sets\n7. Intersection of sets\n8. Difference of sets\n9. Symmetric set difference\n10. Comparison of sets\n\n0. Exit\n";
    int choice;
    std::vector <Set> storage;
    while(true) {
        std::cout << info << "\nChoose a menu item: ";
        std::cin >> choice;
        switch (choice) {
            case (0): {
                std::cout << "Exiting...\n";
                return 0;
            }
            case (1): {
                Set set;

                std::cout << "Enter a desired size of a set: ";
                int desiredSize;
                std::cin >> desiredSize;

                std::cout << "Choose a method of input - manual or random(M/R): ";
                char inputMethod;
                std::cin >> inputMethod;

                if (inputMethod == 'm' || inputMethod == 'M') {
                    std::cout << "Enter set's members through a space: ";
                    for (int i = 0; i < desiredSize; ++i)
                        std::cin >> set;
                } else if (inputMethod == 'r' || inputMethod == 'R') {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dist(0, 256);
                    for (int i = 0; i < desiredSize; ++i)
                        set.add(dist(gen));
                } else {
                    std::cout << "Impossible to recognize the choice. Try again from menu\n";
                    break;
                }
                storage.push_back(set);
                std::cout << "Successfully created\n";

                break;
            }
            case (2): {
                if (storage.empty()) {
                    std::cout << "You haven't created any sets yet. Pick 1 at the menu to create new one.\n";
                    break;
                }
                int counter = 1;
                for (const auto& i: storage) {
                    std::cout << counter << ". " << i << "\n";
                    counter++;
                }

                break;
            }
            case (3): {
                if (storage.empty()) {
                    std::cout << "Error: no sets found to delete\n";
                    break;
                }

                std::cout << "Enter a number of set to delete: ";
                int toDelete;
                std::cin >> toDelete;

                if (toDelete < 1 || toDelete > storage.size()) {
                    std::cout << "Wrong number of set in list. Try again\n";
                    break;
                }

                storage[toDelete - 1].~Set();
                storage.erase(storage.begin() + (toDelete - 1));

                break;
            }
            case (4): {
                std::cout << "Pick a set from a storage that you want to extend: ";
                int toExtend;
                std::cin >> toExtend;
                if (toExtend < 1 || toExtend > storage.size()) {
                    std::cout << "No such number in storage. Try again\n";
                    break;
                }

                std::cout << "How much elements you want to add? ";
                int amount;
                std::cin >> amount;

                std::cout << "Enter elements through a space: ";
                for (int i = 0; i < amount; ++i) {
                    std::cin >> storage[toExtend - 1];
                }

                break;
            }
            case (5): {
                std::cout << "Pick a set from a storage that you want to erase: ";
                int toErase;
                std::cin >> toErase;
                if (toErase < 1 || toErase > storage.size()) {
                    std::cout << "No such number in storage. Try again\n";
                    break;
                }

                std::cout << "How do you want to erase set: by index or by data? (I/D): ";
                char eraseMethod;
                std::cin >> eraseMethod;
                if (eraseMethod == 'i' || eraseMethod == 'I') {
                    std::cout << "Enter an index of set's member to delete: ";
                    int idx;
                    std::cin >> idx;
                    if (idx < 1 || idx > storage[toErase - 1].getSize()) {
                        std::cout << "No such member in set. Try again from menu\n";
                        break;
                    }
                    storage[toErase - 1].remove(idx);
                } else if (eraseMethod == 'd' || eraseMethod == 'D') {
                    std::cout << "Enter a data to delete from set: ";
                    int data;
                    std::cin >> data;
                    if (storage[toErase - 1].getPosByData(data) == -1) {
                        std::cout << "No such member with entered data in set. Try again from menu\n";
                        break;
                    }
                    storage[toErase - 1].remove(storage[toErase - 1].getPosByData(data));
                } else
                    std::cout << "Impossible to recognize the choice. Try again from menu\n";

                break;
            }
            case (6): {
                int FCh, SCh;
                std::cout << "Enter numbers of 2 sets from a storage through a space: ";
                std::cin >> FCh >> SCh;

                std::cout << storage[FCh-1] + storage[SCh-1] << "\n";

                break;
            }
            case (7): {
                int FCh, SCh;
                std::cout << "Enter numbers of 2 sets from a storage through a space: ";
                std::cin >> FCh >> SCh;

                std::cout << storage[FCh-1] * storage[SCh-1] << "\n";

                break;
            }
            case (8): {
                int FCh, SCh;
                std::cout << "Enter numbers of 2 sets from a storage through a space: ";
                std::cin >> FCh >> SCh;

                std::cout << storage[FCh-1] - storage[SCh-1] << "\n";

                break;
            }
            case (9): {
                int FCh, SCh;
                std::cout << "Enter numbers of 2 sets from a storage through a space: ";
                std::cin >> FCh >> SCh;

                std::cout << storage[FCh-1] / storage[SCh-1] << "\n";

                break;
            }
            case (10): {
                std::cout << "Enter a numbers of sets in storage to compare through a space: ";
                int Fch, Sch;
                std::cin >> Fch >> Sch;

                if (storage[Fch - 1] == storage[Sch - 1])
                    std::cout << storage[Fch - 1] << " == " << storage[Sch - 1] << "\n";
                else if (storage[Fch - 1] != storage[Sch - 1])
                    std::cout << storage[Fch - 1] << " != " << storage[Sch - 1] << "\n";

                break;
            }
            default:
                std::cout << "Wrong menu item, try again\n";
                break;
        }
    }
}
