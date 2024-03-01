#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::remove, std::remove_if
#include <ctime>
#include <cstdlib> // for rand

class Car {
public:
    Car(int id, std::string model, bool is_available) : id(id), model(model), is_available(is_available) {}

    int getId() const {
        return id;
    }

    std::string getModel() const {
        return model;
    }

    bool isAvailable() const {
        return is_available;
    }

    void setAvailable(bool is_available) {
        this->is_available = is_available;
    }
    
    std:: string setmodel(){
        this->model = model;
    }
private:
    int id;
    std::string model;
    bool is_available;
};

class Customer {
public:
    Customer(int id, std::string name, int customer_record) : id(id), name(name), customer_record(customer_record) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    int getCustomerRecord() const {
        return customer_record;
    }

    void setCustomerRecord(int customer_record) {
        this->customer_record = customer_record;
    }

    void rentCar(Car& car) {
        rented_cars.push_back(&car);
        car.setAvailable(false);
    }

    void returnCar(Car& car) {
        rented_cars.erase(std::remove(rented_cars.begin(), rented_cars.end(), &car), rented_cars.end());
        car.setAvailable(true);
    }

    void browseRentedCars() const {
        for (const Car* car : rented_cars) {
            std::cout << "Car ID: " << car->getId() << ", Model: " << car->getModel() << std::endl;
        }
    }

    void updateCustomerRecord(int factor) {
        customer_record += factor;
    }

private:
    int id;
    std::string name;
    int customer_record;
    std::vector<Car*> rented_cars;
};

class Employee {
public:
    Employee(int id, std::string name, int employee_record) : id(id), name(name), employee_record(employee_record) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    int getEmployeeRecord() const {
        return employee_record;
    }

    void setEmployeeRecord(int employee_record) {
        this->employee_record = employee_record;
    }

    void rentCar(Car& car) {
        rented_cars.push_back(&car);
        car.setAvailable(false);
    }

    void returnCar(Car& car) {
        rented_cars.erase(std::remove(rented_cars.begin(), rented_cars.end(), &car), rented_cars.end());
        car.setAvailable(true);
    }

    void browseRentedCars() const {
        for (const Car* car : rented_cars) {
            std::cout << "Car ID: " << car->getId() << ", Model: " << car->getModel() << std::endl;
        }
    }

    void updateEmployeeRecord(int factor) {
        employee_record += factor;
    }

private:
    int id;
    std::string name;
    int employee_record;
    std::vector<Car*> rented_cars;
};

class Manager {
public:
    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void updateCustomer(Customer* customer) {
        for (Customer* c : customers) {
            if (c->getId() == customer->getId()) {
                c->setCustomerRecord(customer->getCustomerRecord());
                break;
            }
        }
    }

    void deleteCustomer(int id) {
        customers.erase(std::remove_if(customers.begin(), customers.end(), [id](Customer* c) { return c->getId() == id; }), customers.end());
    }

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void updateEmployee(Employee* employee) {
        for (Employee* e : employees) {
            if (e->getId() == employee->getId()) {
                e->setEmployeeRecord(employee->getEmployeeRecord());
                break;
            }
        }
    }

    void deleteEmployee(int id) {
        employees.erase(std::remove_if(employees.begin(), employees.end(), [id](Employee* e) { return e->getId() == id; }), employees.end());
    }

    void addCar(Car* car) {
        cars.push_back(car);
    }

    void updateCar(Car* car) {
        for (Car* c : cars) {
            if (c->getId() == car->getId()) {
                break;
            }
        }
    }

    void deleteCar(int id) {
        cars.erase(std::remove_if(cars.begin(), cars.end(), [id](Car* c) { return c->getId() == id; }), cars.end());
    }

    void seeCars() const {
        for (const Car* car : cars) {
            std::cout << "Car ID: " << car->getId() << ", Model: " << car->getModel() << ", Available: " << (car->isAvailable() ? "Yes" : "No") << std::endl;
        }
    }

    void seeCustomers() const {
        for (const Customer* customer : customers) {
            std::cout << "Customer ID: " << customer->getId() << ", Name: " << customer->getName() << std::endl;
        }
    }

    void seeEmployees() const {
        for (const Employee* employee : employees) {
            std::cout << "Employee ID: " << employee->getId() << ", Name: " << employee->getName() << std::endl;
        }
    }

    Customer* getCustomer(int id) {
        for (Customer* c : customers) {
            if (c->getId() == id) {
                return c;
            }
        }
        return nullptr;
    }

    Employee* getEmployee(int id) {
        for (Employee* e : employees) {
            if (e->getId() == id) {
                return e;
            }
        }
        return nullptr;
    }

    Car* getCar(int id) {
        for (Car* c : cars) {
            if (c->getId() == id) {
                return c;
            }
        }
        return nullptr;
    }

private:
    std::vector<Customer*> customers;
    std::vector<Employee*> employees;
    std::vector<Car*> cars;
};

int main() {
    // Initialize cars
    std::vector<Car*> car_database = {
        new Car(1, "BMW i7", true),
        new Car(2, "Jaguar F-Type", true),
        new Car(3, "Volvo XC90", true),
        new Car(4, "Audi Q3", true),
        new Car(5, "Mercedes-Benz GLE", true)
    };

    // Initialize customers
    std::vector<Customer*> customer_database = {
        new Customer(1, "Deepak Kumar", 10),
        new Customer(2, "Jagdeesh Sharma", 15),
        new Customer(3, "Sharda Mukherjee", 5),
        new Customer(4, "Vasuki Mittal", 8),
        new Customer(5, "Siddharth Nayak", 12)
    };

    // Initialize employees
    std::vector<Employee*> employee_database = {
        new Employee(1, "Priya Patel", 10),
        new Employee(2, "Ananya Sharma", 15),
        new Employee(3, "Rahul Singh", 8),
        new Employee(3, "Pooja Gupta", 12),
        new Employee(3, "Rajesh Kumar", 5)
    };

    Manager manager;

    // Add cars, customers, and employees to the manager
    for (Car* car : car_database) {
        manager.addCar(car);
    }

    for (Customer* customer : customer_database) {
        manager.addCustomer(customer);
    }

    for (Employee* employee : employee_database) {
        manager.addEmployee(employee);
    }

    // Main loop
    int choice;
    do {
        std::cout << "1. Customer\n2. Employee\n3. Manager\n4. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Customer functionality
                int customerChoice;
                do {
                    std::cout << "1. Rent a car\n2. Return a car\n3. Browse rented cars\n4. Update customer record\n5. Back to main menu\n";
                    std::cin >> customerChoice;

                    switch (customerChoice) {
                        case 1: {
                            std::cout << "Enter car ID to rent: ";
                            int carId;
                            std::cin >> carId;
                            Car* carToRent = manager.getCar(carId);
                            if (carToRent) {
                                if (carToRent->isAvailable()) {
                                    Customer* customer = manager.getCustomer(1); // Assume customer ID 1 for now
                                    if (customer) {
                                        customer->rentCar(*carToRent);
                                        std::cout << "Car rented successfully!\n";
                                    } else {
                                        std::cout << "Customer not found!\n";
                                    }
                                } else {
                                    std::cout << "Car is not available for rent.\n";
                                }
                            } else {
                                std::cout << "Car not found!\n";
                            }
                            break;
                        }

                        case 2: {
                            std::cout << "Enter car ID to return: ";
                            int carId;
                            std::cin >> carId;
                            Car* carToReturn = manager.getCar(carId);
                            if (carToReturn) {
                                Customer* customer = manager.getCustomer(1); // Assume customer ID 1 for now
                                if (customer) {
                                    customer->returnCar(*carToReturn);
                                    std::cout << "Car returned successfully!\n";
                                } else {
                                    std::cout << "Customer not found!\n";
                                }
                            } else {
                                std::cout << "Car not found!\n";
                            }
                            break;
                        }

                        case 3: {
                            Customer* customer = manager.getCustomer(1); // Assume customer ID 1 for now
                            if (customer) {
                                std::cout << "Rented cars:\n";
                                customer->browseRentedCars();
                            } else {
                                std::cout << "Customer not found!\n";
                            }
                            break;
                        }

                        case 4: {
                            Customer* customer = manager.getCustomer(1); // Assume customer ID 1 for now
                            if (customer) {
                                int factor;
                                std::cout << "Enter record update factor: ";
                                std::cin >> factor;
                                customer->updateCustomerRecord(factor);
                                std::cout << "Customer record updated successfully!\n";
                            } else {
                                std::cout << "Customer not found!\n";
                            }
                            break;
                        }

                        case 5:
                            break;

                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                    }
                } while (customerChoice != 5);
                break;
            }

            case 2: {
    // Employee functionality
    int employeeChoice;
    do {
        std::cout << "1. Rent a car\n2. Return a car\n3. Browse rented cars\n4. Update employee record\n5. Back to main menu\n";
        std::cin >> employeeChoice;

        switch (employeeChoice) {
            case 1: {
                // Rent a car
                std::cout << "Enter car ID to rent: ";
                int carId;
                std::cin >> carId;
                Car* carToRent = manager.getCar(carId);
                if (carToRent) {
                    if (carToRent->isAvailable()) {
                        Employee* employee = manager.getEmployee(1); // Assume employee ID 1 for now
                        if (employee) {
                            employee->rentCar(*carToRent);
                            std::cout << "Car rented successfully!\n";
                        } else {
                            std::cout << "Employee not found!\n";
                        }
                    } else {
                        std::cout << "Car is not available for rent.\n";
                    }
                } else {
                    std::cout << "Car not found!\n";
                }
                break;
            }

            case 2: {
                // Return a car
                std::cout << "Enter car ID to return: ";
                int carId;
                std::cin >> carId;
                Car* carToReturn = manager.getCar(carId);
                if (carToReturn) {
                    Employee* employee = manager.getEmployee(1); // Assume employee ID 1 for now
                    if (employee) {
                        employee->returnCar(*carToReturn);
                        std::cout << "Car returned successfully!\n";
                    } else {
                        std::cout << "Employee not found!\n";
                    }
                } else {
                    std::cout << "Car not found!\n";
                }
                break;
            }

            case 3: {
                // Browse rented cars
                Employee* employee = manager.getEmployee(1); // Assume employee ID 1 for now
                if (employee) {
                    std::cout << "Rented cars:\n";
                    employee->browseRentedCars();
                } else {
                    std::cout << "Employee not found!\n";
                }
                break;
            }

            case 4: {
                // Update employee record
                Employee* employee = manager.getEmployee(1); // Assume employee ID 1 for now
                if (employee) {
                    int factor;
                    std::cout << "Enter record update factor: ";
                    std::cin >> factor;
                    employee->updateEmployeeRecord(factor);
                    std::cout << "Employee record updated successfully!\n";
                } else {
                    std::cout << "Employee not found!\n";
                }
                break;
            }

            case 5:
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (employeeChoice != 5);
    break;
}

             case 3: {
                // Manager functionality
                int managerChoice;
                do {
                    std::cout << "1. Add a customer\n2. Add an employee\n3. Add a car\n4. Delete a customer\n5. Delete an employee\n6. Delete a car\n7. See customers\n8. See employees\n9. See cars\n10. Back to main menu\n";
                    std::cin >> managerChoice;

                    switch (managerChoice) {
                        case 1: {
                            // Add a customer
                            int id;
                            std::string name;
                            int customerRecord;
                            std::cout << "Enter customer ID: ";
                            std::cin >> id;
                            std::cout << "Enter customer name: ";
                            std::cin.ignore();
                            std::getline(std::cin, name);
                            std::cout << "Enter customer record: ";
                            std::cin >> customerRecord;
                            manager.addCustomer(new Customer(id, name, customerRecord));
                            std::cout << "Customer added successfully!\n";
                            break;
                        }

                        case 2: {
                            // Add an employee
                            int id;
                            std::string name;
                            int employeeRecord;
                            std::cout << "Enter employee ID: ";
                            std::cin >> id;
                            std::cout << "Enter employee name: ";
                            std::cin.ignore();
                            std::getline(std::cin, name);
                            std::cout << "Enter employee record: ";
                            std::cin >> employeeRecord;
                            manager.addEmployee(new Employee(id, name, employeeRecord));
                            std::cout << "Employee added successfully!\n";
                            break;
                        }

                        case 3: {
                            // Add a car
                            int id;
                            std::string model;
                            bool isAvailable;
                            std::cout << "Enter car ID: ";
                            std::cin >> id;
                            std::cout << "Enter car model: ";
                            std::cin.ignore();
                            std::getline(std::cin, model);
                            std::cout << "Is car available? (1 for Yes, 0 for No): ";
                            std::cin >> isAvailable;
                            manager.addCar(new Car(id, model, isAvailable));
                            std::cout << "Car added successfully!\n";
                            break;
                        }

                        case 4: {
                            // Delete a customer
                            int id;
                            std::cout << "Enter customer ID to delete: ";
                            std::cin >> id;
                            manager.deleteCustomer(id);
                            std::cout << "Customer deleted successfully!\n";
                            break;
                        }

                        case 5: {
                            // Delete an employee
                            int id;
                            std::cout << "Enter employee ID to delete: ";
                            std::cin >> id;
                            manager.deleteEmployee(id);
                            std::cout << "Employee deleted successfully!\n";
                            break;
                        }

                        case 6: {
                            // Delete a car
                            int id;
                            std::cout << "Enter car ID to delete: ";
                            std::cin >> id;
                            manager.deleteCar(id);
                            std::cout << "Car deleted successfully!\n";
                            break;
                        }

                        case 7: {
                            // See customers
                            manager.seeCustomers();
                            break;
                        }

                        case 8: {
                            // See employees
                            manager.seeEmployees();
                            break;
                        }

                        case 9: {
                            // See cars
                            manager.seeCars();
                            break;
                        }

                        case 10:
                            break;

                        default:
                            std::cout << "Invalid choice. Please try again.\n";
                    }
                } while (managerChoice != 10);
                break;
            }

            case 4:
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    // Clean up memory
    for (Car* car : car_database) {
        delete car;
    }

    for (Customer* customer : customer_database) {
        delete customer;
    }

    for (Employee* employee : employee_database) {
        delete employee;
    }

    return 0;
}