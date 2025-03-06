#include <iostream>
using namespace std;
int main(){
int vote[5],count[5];
int sp,i;
cout<<"Enter Candidate numbers for voting"<<endl;
for(i=0;i<5;i++){
 cout<<"Enter Ballot for:";
 cin>>count[i];
   if(count[i]<1 || count[i]>5)
    sp++;
   else if(count[i]==1)
    vote[0]=vote[0]+1;
    else if(count[i]==2)
    vote[1]=vote[1]+1;
    else if(count[i]==3)
    vote[2]=vote[1]+1;
    else if(count[i]==4)
    vote[3]=vote[3]+1;
    else if(count[i]==5)
    vote[4]=vote[4]+1;
}
 for(i=0;i<5;i++){
  cout<<"Candidate numbers "<<i+1<<": "<<vote[i]<<endl;
 }
 cout<<"Spoiled :"<<sp<<endl;
}
