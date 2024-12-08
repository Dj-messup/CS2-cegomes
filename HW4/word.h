#pragma once
#include <string>
#include <iostream>

using namespace std;

class Word {
private:
    string _word;
    int _counter;

public:
    Word();
    Word(string tmpWord, int tmpCounter);

    bool operator==(const Word &otherWord);
    bool operator<(const Word &otherWord);
    bool operator>(const Word &otherWord);
    Word operator++(int);
    friend ostream &operator<<(ostream &os, const Word &tmpWord)
    {
        os << tmpWord._word << ":" << tmpWord._counter;
        return os;
    }
};

// Default constructor, set word to "" and counter to 1
Word::Word() {
    _word = "";
    _counter = 1;
}

// Parameterized constructor
Word::Word(string tmpWord, int tmpCounter) {
    _word = tmpWord;
    _counter = tmpCounter;
}

// return a constructed word with the counter incremented
Word Word::operator++(int counter) {
    Word temp = *this;
    _counter++;
    return temp;
}

// Check if two Words are equal (compare _word)
bool Word::operator==(const Word &otherWord) {
    return _word == otherWord._word;
}

// Check if this is less than otherWord
bool Word::operator<(const Word &otherWord) {
    return _word < otherWord._word;
}

// Check if this is greater than otherWord
bool Word::operator>(const Word &otherWord) {
    return _word > otherWord._word;
}