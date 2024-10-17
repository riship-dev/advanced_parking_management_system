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
class Bike : public Vehicle {
    private:
        int engineCapacity;
    public:
        Bike(string licensePlate) : Vehicle(licensePlate, "Bike"), engineCapacity(150) {}
};
class Bus : public Vehicle {
    private:
        int capacity;
    public:
        Bus(string licensePlate) : Vehicle(licensePlate, "Bus"), capacity(50) {}
};

class ParkingSlot {
    private:
        int slotID;
        bool isOccupied;
        string vehicleTypeAllowed;
    public:
        ParkingSlot(int slotID, string vehicleTypeAllowed) : slotID(slotID), vehicleTypeAllowed(vehicleTypeAllowed), isOccupied(false) {}
        
        bool assignSlot(Vehicle* vehicle) {
            if (!isOccupied && vehicleTypeAllowed == vehicle->getType()) {
                isOccupied = true;
                cout << "Slot " << slotID << " assigned to vehicle with license plate: " << vehicle->getLicensePlate() << endl;
                return true;
            } else {
                cout << "Slot " << slotID << " is either occupied or not suitable for the vehicle type." << endl;
                return false;
            }
        }
        void freeSlot() {
            isOccupied = false;
            cout << "Slot " << slotID << " is now free." << endl;
        }
        bool getIsOccupied() const { return isOccupied; }
};
class ParkingLot {
    private:
        string location;
        int totalSlots;
        int availableSlots;
        vector <ParkingSlot> slots;
    public:
        ParkingLot(string location, int totalSlots) : location(location), totalSlots(totalSlots), availableSlots(totalSlots) {
            for (int i = 1; i <= totalSlots; i++) {
                slots.push_back(ParkingSlot(i, "Any"));
            }
        }

        ParkingSlot* allocateSlot(Vehicle *vehicle) {
            for (auto& slot : slots) {
                if (!slot.getIsOccupied()) {
                    if (slot.assignSlot(vehicle)) {
                        availableSlots--;
                        return &slot;
                    }
                }
            }
            cout << "No available slot for vehicle with license plate: " << vehicle->getLicensePlate() << endl;
            return nullptr;
        }
        void freeSlot(ParkingSlot *slot) {
            slot->freeSlot();
            availableSlots++;
        }
        int getAvailableSlots() const { return availableSlots; }
};