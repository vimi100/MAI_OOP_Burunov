#include <string>
#include "vowel.h"

int countVowels(std::string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        // Проверяем каждый символ на гласность
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y') {
            count++;
        }
    }
    return count;
}