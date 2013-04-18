#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* str) {
    if(*str == '\0') {
        return;
    }
    char* end = str;
    while(*end != '\0') {
        end++;
    }
    end--;
    char* start = str;
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char s1[] = "hello world";
    char s2[] = "reverse the string";
    char s3[] = "";
    reverse(s1);
    reverse(s2);
    reverse(s3);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
}
