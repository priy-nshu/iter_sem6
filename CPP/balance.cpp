#include<iostream>
using namespace std;

class bank{
  float Balance=0;
  
  void update(int up,float dep,float with){
   if(up==1){
     Balance+=dep;
   }
   else{
     Balance-=with;
   }
  }
	
 public:
   void deposit();
   void withdraw();
   void showBalance();
   int up;
};

int main(){
  bank myBank;
  int choice;
 
  do{
    cout << "\nBank Menu:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Show Balance\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
  switch(choice) {
      case 1:
         myBank.deposit();
          break;
      case 2:
           myBank.withdraw();
           break;
      case 3:
           myBank.showBalance();
           break;
      case 4:
           cout << "Exiting program.\n";
           break;
      default:
           cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);

    return 0;
}

inline void bank::deposit(){
      float amount;
      cout << "Enter deposit amount: ";
      cin >> amount;
      update(1, amount, 0);  
    
}

inline void bank::withdraw() {
     float amount;
     cout << "Enter withdrawal amount: ";
     cin >> amount;
     if(amount > Balance) {
        cout << "Error: Insufficient funds! Withdrawal denied.\n";
    } else {
        update(0, 0, amount); 
    }
 }
 
 inline void bank::showBalance() {
     cout << "Current balance: " << Balance << endl;
  }
