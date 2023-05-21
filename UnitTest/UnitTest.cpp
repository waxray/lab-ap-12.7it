#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\tmaks\code\c++ labs\lab ap 12.7it\lab ap 12.7it\lab ap 12.7it.cpp"
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// Function to remove elements from the string list based on indices
void removeElements(list<string>& stringList, const list<int>& indexList) {
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
}

// Test class
TEST_CLASS(UnitTest) {
public:
    // Test method
    TEST_METHOD(TestRemoveElements) {
        list<string> stringList = { "a", "b", "c", "d", "e" };
        list<int> indexList = { 2, 4 };

        removeElements(stringList, indexList);

        list<string> expectedList = { "a", "c", "e" };
        Assert::IsTrue(stringList == expectedList);
    }
};