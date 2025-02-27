#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;

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
        time_t getEntryTime() const { return entryTime; }
        time_t getExitTime() const { return exitTime; }
        
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
            if (!isOccupied && (vehicleTypeAllowed == "Any" || vehicleTypeAllowed == vehicle->getType())) {
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

class Payment {
    private:
        double amount;
        string paymentMethod;
    public:
        Payment(double amount, string paymentMethod) : amount(amount), paymentMethod(paymentMethod) {}

        double calculateCharge(time_t entryTime, time_t exitTime, string vehicleType) {
            double duration = difftime(exitTime, entryTime) / 3600;
            double rate = 0;

            if (vehicleType == "Car") {
                rate = 10.0;
            } else if (vehicleType == "Bike") {
                rate = 5.0;
            } else if (vehicleType == "Bus") {
                rate = 20.0;
            }

            return round(duration * rate * 100.0) / 100.0;
        }
};

class Admin {
    private:
        int adminID;
        string name;
    public:
        Admin(int adminID, string name) : adminID(adminID), name(name) {}
        
        void manageParking() { cout << "Admin " << name << " is managing the parking system." << endl; }
        void generateReport(double totalRevenue) { cout << "Total revenue generated: $" << totalRevenue << endl; }
};

int main() {
    
}