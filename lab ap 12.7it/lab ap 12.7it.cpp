#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> stringList;
    list<int> indexList;

    // Зчитування рядків з текстового файлу та заповнення першого списку
    ifstream inputFile("textfile.txt");
    string line;
    while (getline(inputFile, line)) {
        stringList.push_back(line);
    }
    inputFile.close();

    // Зчитування натуральних чисел з клавіатури та заповнення другого списку
    int numElements;
    cout << "Enter the number of items to delete: ";
    cin >> numElements;
    for (int i = 0; i < numElements; i++) {
        int index;
        cout << "Enter the serial number of the item to delete: ";
        cin >> index;
        indexList.push_back(index);
    }

    // Видалення елементів з першого списку за заданими порядковими номерами
    int currentIndex = 1;
    for (auto it = stringList.begin(); it != stringList.end();) {
        if (find(indexList.begin(), indexList.end(), currentIndex) != indexList.end()) {
            it = stringList.erase(it);
        }
        else {
            ++it;
        }
        currentIndex++;
    }

    // Виведення початкового та зміненого списків
    cout << "Initial list of strings:\n";
    for (const auto& str : stringList) {
        cout << str << "\n";
    }

    cout << "Output list of strings:\n";
    for (const auto& str : stringList) {
        cout << str << "\n";
    }

    return 0;
}