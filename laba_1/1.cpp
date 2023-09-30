#include <iostream>
#include "vowel.h"
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int vowels = countVowels(input);
    cout << "Count vowels: " << vowels << endl;

    return 0;
}