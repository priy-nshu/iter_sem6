#include<iostream>
using namespace std;
int main(){
  cout<<"Enter temperature in Fahrenhiet:";
  float t;
  cin>>t;
  float con;
  con=(5*(t-32))/9;
  cout<<"Temperature in celcius is :" <<con <<endl;
  return 0;
}
