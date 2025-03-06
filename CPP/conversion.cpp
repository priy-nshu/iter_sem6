#include <iostream>
using namespace std;

class DB;  // Forward declaration of DB class

class DM {
    float meters, centimeters;

public:
    void getDistance() {
        cout << "Enter distance in meters and centimeters:" << endl;
        cin >> meters >> centimeters;
    }

    void displayDM() const {
        cout << meters << " meters " << centimeters << " cm" << endl;
    }

    friend DM addDistance(DM, DB);
    friend DB toMeters(DM &dm); // Declaring toMeters as friend function

    void toFeetAndInches(DB &db) const;  // Declare function here, define outside class
};

class DB {
    float feet, inches;

public:
    void getDistance() {
        cout << "Enter distance in feet and inches:" << endl;
        cin >> feet >> inches;
    }

    void displayDB() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    friend DB addDistanceDB(DM, DB);
    friend  DM toFeetAndInches(DB &db) const; // Declaring toFeetAndInches as friend function

    void toMeters(DM &dm);  // Declare function here, define outside class
};

DM toFeetAndInches(DB &db) const {
    float totalMeters = meters + centimeters / 100;
    float totalInches = totalMeters * 39.3701;
    db.feet = totalInches / 12;
    db.inches = totalInches - (db.feet * 12);
}

 DB toMeters(DM &dm) {
    float totalInches = feet * 12 + inches;
    float totalMeters = totalInches * 0.0254;
    dm.meters = totalMeters;
    dm.centimeters = (totalMeters - static_cast<int>(totalMeters)) * 100;
}

DM addDistance(DM dm, DB db) {
    DM result;
    db.toMeters(result);
    result.centimeters += dm.centimeters;
    result.meters += dm.meters + (result.centimeters / 100);
    result.centimeters -= static_cast<int>(result.centimeters / 100) * 100;
    return result;
}

DB addDistanceDB(DM dm, DB db) {
    DB result;
    dm.toFeetAndInches(result);  
    result.inches += db.inches;
    result.feet += db.feet + (result.inches / 12);
    result.inches -= (static_cast<int>(result.inches / 12) * 12);
    return result;
}

int main() {
    DM dm;
    DB db;
    
    dm.getDistance();  
    db.getDistance();  
    
    char choice;
    cout << "Do you want the result in meters (M) or feet (F)? ";
    cin >> choice;

    if (choice == 'M' || choice == 'm') {
        DM result = addDistance(dm, db); 
        cout << "Resulting Distance in meters and centimeters: ";
        result.displayDM();
    } else if (choice == 'F' || choice == 'f') {
        DB result = addDistanceDB(dm, db);
        cout << "Resulting Distance in feet and inches: ";
        result.displayDB();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

