#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Vehicle;
class Car; // class Car : public Vehicle;
class Bike; // class Bike : public Vehicle;
class Bus; // class Bus : public Vehicle;
class ParkingSlot;
class ParkingLot;
class Payment;
class Admin;

int main() {

}

class Vehicle {
    private:
        string licensePlate;
        string type;
        time_t entryTime;
        time_t exitTime;
    protected:
        void setEntryTime() { time(&entryTime); }
        void setExitTime() { time(&exitTime); }
    public:
        Vehicle(string licensePlate, string type) : licensePlate(licensePlate), type(type) { setEntryTime(); }
        
        string getLicensePlate() const { return licensePlate; }
        string getType() const { return type; }
        
        virtual void park() { cout << "Vehicle with license plate " << licensePlate << " is parked." << endl; }
        virtual void exit() {
            setExitTime();
            cout << "Vehicle with license plate " << licensePlate << " is exiting." << endl;
        }
};
class Car : public Vehicle {
    private:
        int seats;
    public:
        Car(string licensePlate) : Vehicle(licensePlate, "Car"), seats(5) {}
};