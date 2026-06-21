#include<iostream>
using namespace std;

class Vehicle {
private:
    int vehicleID, year;

protected:
    string manufacturer, model;

public:
    static int totalVehicles;

    Vehicle(int id=0, string m="", string mo="", int y=0) {
        vehicleID = id;
        manufacturer = m;
        model = mo;
        year = y;
        totalVehicles++;
    }

    ~Vehicle() {}

    void setID(int id) { vehicleID = id; }
    int getID() { return vehicleID; }

    virtual void display() {
        cout << "\nID: " << vehicleID
             << "\nManufacturer: " << manufacturer
             << "\nModel: " << model
             << "\nYear: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
public:
    string fuelType;

    Car(int id=0,string m="",string mo="",int y=0,string f="")
        : Vehicle(id,m,mo,y) {
        fuelType = f;
    }

    void display() {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
public:
    int batteryCapacity;

    ElectricCar(int id,string m,string mo,int y,string f,int b)
        : Car(id,m,mo,y,f) {
        batteryCapacity = b;
    }
};

class Aircraft {
public:
    int flightRange;
};

class FlyingCar : public Car, public Aircraft {};

class Sedan : public Car {};
class SUV : public Car {};

int main() {
    Car cars[3];
    int id, year;
    string man, model, fuel;

    for(int i=0; i<3; i++) {
        cout << "\nEnter Vehicle " << i+1 << " Details\n";
        cout << "ID: ";
        cin >> id;
        cout << "Manufacturer: ";
        cin >> man;
        cout << "Model: ";
        cin >> model;
        cout << "Year: ";
        cin >> year;
        cout << "Fuel Type: ";
        cin >> fuel;

        cars[i] = Car(id, man, model, year, fuel);
    }

    cout << "\n--- Vehicle Records ---\n";
    for(int i=0; i<3; i++)
        cars[i].display();

    cout << "\nTotal Vehicles: " << Vehicle::totalVehicles << endl;
}

/*ouput

Enter Vehicle 1 Details
ID: 101
Manufacturer: toyota
Model: Fortuner
Year: 2025
Fuel Type: disel

Enter Vehicle 2 Details
ID: 102
Manufacturer: BMW
Model: M4
Year: 2024
Fuel Type: disel

Enter Vehicle 3 Details
ID: 103
Manufacturer: pagani
Model: Zonda
Year: 2026
Fuel Type: disel

--- Vehicle Records ---

ID: 101
Manufacturer: toyota
Model: Fortuner
Year: 2025
Fuel Type: disel

ID: 102
Manufacturer: BMW
Model: M4
Year: 2024
Fuel Type: disel

ID: 103
Manufacturer: pagani
Model: Zonda
Year: 2026
Fuel Type: disel

Total Vehicles: 6
*/