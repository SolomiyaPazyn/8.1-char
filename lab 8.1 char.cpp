//ƒано л≥терний р€док, €кий м≥стить посл≥довн≥сть символ≥в s0, Е, sn, Е .
//1. ¬и€снити, чи Ї в ц≥й посл≥довност≥ так≥ елементи si, si + 1 що si Ц це кома(У, Ф), а si + 1 Ц
//тире(УЦФ), та обчислити њх к≥льк≥сть.
//2. «ам≥нити кожну групу символ≥в У, ЦФ з≥рочкою У* Ф.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ‘ункц≥€ дл€ пошуку посл≥довност≥ ",-" в р€дку
static bool Search(char* s) {
    int pos = 0;
    while (s[pos] != '\0') {
        if (s[pos] == ',' && s[pos + 1] == '-') {
            return true;
        }
        pos++;
    }
    return false;
}

// ‘ункц≥€ дл€ зам≥ни кожноњ групи символ≥в ",-" на "*"
static char* Replace(char* s) {
    char* result = new char[strlen(s) + 1];
    int i = 0, j = 0;

    while (s[i] != '\0') {
        if (s[i] == ',' && s[i + 1] == '-') {
            result[j] = '*';
            i += 2;  // ѕропускаЇмо обидва символи
            j++;
        }
        else {
            result[j] = s[i];
            i++;
            j++;
        }
    }
    result[j] = '\0';
    strcpy_s(s, strlen(result) + 1, result); // ¬икористанн€ strcpy_s
    delete[] result; // «в≥льненн€ тимчасового буфера
    return s;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // ѕерев≥рка на€вност≥ посл≥довност≥ ",-"
    if (Search(str)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    // «ам≥на посл≥довност≥ ",-" на "*"
    char* dest = Replace(str);
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
