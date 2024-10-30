//���� ������� �����, ���� ������ ����������� ������� s0, �, sn, � .
//1. ��������, �� � � ��� ����������� ��� �������� si, si + 1 �� si � �� ����(�, �), � si + 1 �
//����(���), �� ��������� �� �������.
//2. ������� ����� ����� ������� �, �� ������� �* �.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������� ��� ������ ����������� ",-" � �����
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

// ������� ��� ����� ����� ����� ������� ",-" �� "*"
static char* Replace(char* s) {
    char* result = new char[strlen(s) + 1];
    int i = 0, j = 0;

    while (s[i] != '\0') {
        if (s[i] == ',' && s[i + 1] == '-') {
            result[j] = '*';
            i += 2;  // ���������� ������ �������
            j++;
        }
        else {
            result[j] = s[i];
            i++;
            j++;
        }
    }
    result[j] = '\0';
    strcpy_s(s, strlen(result) + 1, result); // ������������ strcpy_s
    delete[] result; // ��������� ����������� ������
    return s;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // �������� �������� ����������� ",-"
    if (Search(str)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    // ����� ����������� ",-" �� "*"
    char* dest = Replace(str);
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
