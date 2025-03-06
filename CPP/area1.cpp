#include<iostream>
using namespace std;
#define PI 3.14
void square(float &a){
  a=(a*a);
}
void circle(float &r){
  r=(PI*r*r);
}
int main(){
 float a,r;
 cout<<"Enter side of square\n";
 cin>>a;
 square(a);
 cout<<"area of square"<<a;
 cout<<"Enter Radius\n";
 cin>>r;
 circle(r);
 cout<<"area of square"<<r;
 return 0;
}
