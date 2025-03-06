#include<iostream>
using namespace std;
#define PI 3.14
void square(float a){
  cout<<"Area of square:"<<(a*a)<<endl;
}
void circle(float r){
  cout<<"Area of Circle:"<<(PI*r*r)<<endl;
}
int main(){
 float a,r;
 cout<<"Enter side of square\n";
 cin>>a;
 square(a);
 cout<<"Enter Radius\n";
 cin>>r;
 circle(r);
 return 0;
}
