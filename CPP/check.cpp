#include<iostream>
#include<string>
using namespace std;

class ch{
public:
 inline void read(){
  cout<<"Enter a binary number"<<endl;
  cin>>s;
 }
 
 inline bool chk_bin(){
  for(int i=0;i<s.length();i++){
    if(s.at(i)=='0' || s.at(i)=='1') continue;
    else {
      cout<<"Not possible"<<endl;
      exit(0);
    }
  }
  return true;
 }
void ones() {
   if (chk_bin()) {
      for (int i = 0; i < s.length(); i++) {
        s.at(i) = (s.at(i) == '0') ? '1' : '0';
       }
    }
 }

 inline void displayone(){
  cout<<"1's Complement of "<< s <<" is :";
  ones();
  cout<<s<<endl;
 }
 
 private:
 	string s;
};
int main(){
 ch a;
 a.read();
 a.displayone();
 return 0;
}
