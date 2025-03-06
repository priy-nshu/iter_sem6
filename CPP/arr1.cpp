#include<iostream>
using namespace std;

class store{
private:
    string storeItems[10];
    double storePrices[10];
    int storeItemCount;
    
    string bagItems[10];
    double bagPrices[10];
    int bagItemCount;
    
public :

   store() : storeItemCount(0), bagItemCount(0) {}
   
   void items(){
    if(storeItemCount < 10) {
            cout << "Enter item name: ";
            cin >> storeItems[storeItemCount];
            cout << "Enter item price: ";
            cin >> storePrices[storeItemCount];
            storeItemCount++;
        } else {
            cout << "Store is full. Cannot add more items.\n";
        }
    }
   
void add_item(){
   if (storeItemCount > 0) {
      cout << "Enter item name to add to your bag: ";
      string name;
       cin >> name;
            bool found = false;
            for (int i = 0; i < storeItemCount; i++) {
                if (storeItems[i] == name) {
                    if (bagItemCount < 10) {
                        bagItems[bagItemCount] = storeItems[i];
                        bagPrices[bagItemCount] = storePrices[i];
                        bagItemCount++;
                        found = true;
                        break;
                    } else {
                        cout << "Bag is full. Cannot add more items.\n";
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << "Item not found in the store.\n";
            }
        } else {
            cout << "Store is empty. No items to add to the bag.\n";
        }
    }
  
  void remove_item(){
   if(bagItemCount > 0) {
       cout << "Enter item name to remove from your bag: ";
       string name;
       cin >> name;
       bool found = false;
        for(int i = 0; i < bagItemCount; i++) {
          if(bagItems[i] == name) {
           for(int j = i; j < bagItemCount - 1; j++) {
             bagItems[j] = bagItems[j + 1];
             bagPrices[j] = bagPrices[j + 1];
            }
            bagItemCount--;
            found = true;
            break;
           }
          }
           if(!found) {
                cout << "Item not found in the bag.\n";
       }
      } else {
            cout << "Bag is empty. No items to remove.\n";
    }
  }
  
void display_items() {
        if (storeItemCount > 0) {
            cout << "Items available in the store:\n";
            for (int i = 0; i < storeItemCount; i++) {
                cout << storeItems[i] << " - $" << storePrices[i] << endl;
            }
        } else {
            cout << "No items in the store.\n";
        }
    }
  
void display() {
    double totalCost = 0;
      if(bagItemCount > 0) {
        cout << "Items in your bag:\n";
         for(int i = 0; i < bagItemCount; i++) {
            cout << bagItems[i] << " - $" << bagPrices[i] << endl;
            totalCost += bagPrices[i];
           }
            cout << "Total cost: $" << totalCost << endl;
        } else {
            cout << "Your bag is empty.\n";
        }
    }
};

int main(){
  store myStore;
  int choice;
 
  do{
    cout << "\nStore Menu:\n";
    cout << "1. Item Input\n";
    cout << "2. Adding Item\n";
    cout << "3. Remove Item\n";
    cout << "4. Display Items Present In Store\n";
    cout << "5. Display Cost\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
  switch(choice) {
      case 1:
         myStore.items();
          break;
      case 2:
           myStore.add_item();
           break;
      case 3:
           myStore.remove_item();
           break;
      case 4:
           myStore.display_items();
           break;
      case 5:
           myStore.display();
           break; 
      case 6:
           cout << "Exiting program.\n";
           break;
      default:
           cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);

    return 0;
}
