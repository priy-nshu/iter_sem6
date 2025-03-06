#include <iostream>
#include <string>
using namespace std;

class ch {
	    string s; 
	    
	   
public:
    void read();
    bool chk_bin();
    void ones(); 
    void displayone(); 
    string getBinary();
    
};

int main() {
    ch bin;
    bin.read(); 
    if (bin.chk_bin()) {
        bin.displayone(); 
    }
    return 0;
}

inline void ch::read() {
    cout << "Enter a binary number: ";
    cin >> s;
}

inline bool ch::chk_bin() {
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) != '0' && s.at(i) != '1') {
            cout << "Wrong input! Not a binary number." << endl;
            return false;
        }
    }
    return true;
}

inline void ch::ones() {
    for (int i = 0; i < s.length(); i++) {
        s.at(i) = (s.at(i) == '0') ? '1' : '0';
    }
}

inline void ch::displayone() {
    cout << "1's Complement of " << s << " is: ";
    ones();
    cout << s << endl;
}
inline string ch::getBinary() {
    return s;
}

