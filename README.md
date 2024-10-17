# Advanced Parking Management System (OOAD Project)

## Overview
The Advanced Parking Management System is a C++ application designed to manage parking spaces for various types of vehicles. It allows users to park vehicles, exit vehicles, and check available parking slots, all while providing real-time updates on vehicle status and parking charges.

## Features
- **Vehicle Management**: Support for different vehicle types (Cars, Bikes, and Buses).
- **Parking Slot Allocation**: Automatically assigns available parking slots based on vehicle type.
- **Exit and Charge Calculation**: Calculates parking charges based on the duration of stay.
- **Admin Management**: An admin can manage the parking system and generate reports.

## Classes

### Vehicle
- **Description**: Base class representing a vehicle.
- **Attributes**:
  - `licensePlate`: The vehicle's license plate.
  - `type`: The type of vehicle (Car, Bike, or Bus).
  - `entryTime`: The time the vehicle entered the parking.
  - `exitTime`: The time the vehicle exited the parking.
- **Methods**:
  - `park()`: Parks the vehicle.
  - `exit()`: Exits the vehicle and records the exit time.

### Car, Bike, Bus
- **Description**: Derived classes representing specific vehicle types.
- **Attributes**:
  - **Car**: Has a fixed number of seats.
  - **Bike**: Contains engine capacity information.
  - **Bus**: Contains capacity information.

### ParkingSlot
- **Description**: Represents a parking slot in the parking lot.
- **Attributes**:
  - `slotID`: Unique identifier for the slot.
  - `isOccupied`: Status indicating if the slot is occupied.
- **Methods**:
  - `assignSlot(Vehicle* vehicle)`: Assigns a vehicle to the slot if available.
  - `freeSlot()`: Frees the slot for use.

### ParkingLot
- **Description**: Represents a collection of parking slots.
- **Attributes**:
  - `location`: The location of the parking lot.
  - `totalSlots`: Total number of slots in the lot.
  - `availableSlots`: Number of available slots.
- **Methods**:
  - `allocateSlot(Vehicle* vehicle)`: Allocates a slot to a vehicle.
  - `freeSlot(ParkingSlot* slot)`: Frees a specified parking slot.

### Payment
- **Description**: Handles payment calculations.
- **Methods**:
  - `calculateCharge(time_t entryTime, time_t exitTime, string vehicleType)`: Calculates the parking charge based on vehicle type and duration.

### Admin
- **Description**: Represents an admin user who can manage the parking system.
- **Methods**:
  - `manageParking()`: Manages the parking system.
  - `generateReport(double totalRevenue)`: Generates a revenue report.