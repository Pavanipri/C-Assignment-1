Car Rental Management System Documentation
1. Introduction
The Car Rental Management System is a software application designed to facilitate the management of cars, customers, and employees within a car rental company. This system provides functionalities for renting and returning cars, updating customer and employee records, and managing the inventory of available cars.

2. Features
Customers
Rent a car: Customers can rent available cars by specifying the car ID.
Return a car: Customers can return rented cars by specifying the car ID.
Browse rented cars: Customers can view a list of cars they have currently rented.
Update customer record: Customers can update their record, such as loyalty points or rental history.
Employees
Rent a car: Employees can rent available cars on behalf of customers.
Return a car: Employees can process the return of cars rented by customers.
Browse rented cars: Employees can view a list of cars currently rented out.
Update employee record: Employees can update their record, such as performance metrics or service history.
Manager
Add, update, delete customers: Managers can manage customer information, including adding new customers, updating existing records, and deleting customers.
Add, update, delete employees: Managers can manage employee information, including adding new employees, updating existing records, and deleting employees.
Add, update, delete cars: Managers can manage the inventory of cars, including adding new cars, updating car details, and removing cars from the system.
See customers, employees, cars: Managers can view lists of customers, employees, and available cars.
3. Implementation Details
The system is implemented using C++ and consists of several classes:

Car: Represents a car with attributes such as ID, model, and availability.
Customer: Represents a customer with ID, name, and rental history.
Employee: Represents an employee with ID, name, and rental activity.
Manager: Manages customers, employees, and cars.
The system utilizes vectors to store collections of customers, employees, and cars. Methods are implemented within each class to perform operations such as renting/returning cars, updating records, and data retrieval.

4. Getting Started
To run the Car Rental Management System:

Compile the main.cpp file using a C++ compiler.
Execute the compiled program.
Follow the prompts to interact with the system as a customer, employee, or manager.
Ensure that you have a C++ compiler installed on your system to compile and run the program.

5. Usage
Customer:
Choose the option to rent or return a car by entering the corresponding number.
Enter the car ID when prompted to complete the operation.
Follow similar steps to browse rented cars or update your record.
Employee:
Follow the same steps as the customer to rent, return, browse rented cars, or update employee records.
Manager:
Choose from various options to add, update, or delete customers, employees, and cars.
Use the "see" options to view lists of customers, employees, and cars.
6. Testing
The system can be tested by simulating various user interactions and verifying that the expected results are achieved. Unit tests can also be implemented to validate individual components and functionalities of the system.

7. Conclusion
The Car Rental Management System provides a convenient solution for managing car rental operations within a company. With its user-friendly interface and comprehensive features, it streamlines the process of renting and returning cars, updating customer and employee records, and managing the inventory effectively.
