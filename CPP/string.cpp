#include <iostream>
#include <cstring>

using namespace std;

class String {
    char *s1;
    int len;

public:
    String() {
        len = 0;
        s1 = new char[1];
        s1[0] = '\0';
    }

    String(const char* str) {
        len = strlen(str);
        s1 = new char[len + 1];
        strcpy(s1, str);
    }

    String(const String& s) {
        len = s.len;
        s1 = new char[len + 1];
        strcpy(s1, s.s1);
    }

    ~String() {
        delete[] s1;
    }

    void display() const {
        cout << s1 << endl;
    }

  void join(String &s1, String &s2){
    //just use concat functionn here and no comments
  }
};



int main() {
    String s1;
    String s2("Well done!");
    String s3 = s2;

    s1.display();
    s2.display();
    s3.display();

    String s4 = s2 + s3;
    s4.display();

    String s5 = s4 + "!!!";
    s5.display();

    String s6;
    s6 = s5;
    s6.display();

    std::cout << s6.getLength() << std::endl;

    const char* c_string = s6.c_str();
    std::cout << c_string << std::endl;

    return 0;
}
