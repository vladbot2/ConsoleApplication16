#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() : age(0) {}

    Person(const string& name, int age) : name(name), age(age) {}

    Person(const Person& other) : name(other.name), age(other.age) {}

    void display() const {
        cout << "Name: " << name << "Age: " << age << endl;
    }
};

class Apartment {
private:
    Person residents[2];
    int currentResidents;

public:
    Apartment() : currentResidents(0) {}

    void addResident(const Person& person) {
        if (currentResidents < 2) {
            residents[currentResidents++] = person;
        }
    }

    void displayResidents() const {
        cout << "Residents in the apartment:" << endl;
        for (int i = 0; i < currentResidents; i++) {
            residents[i].display();
        }
    }
};

class Building {
private:
    Apartment apartments[3];

public:
    void addResidentToApartment(int apartmentIndex, const Person& person) {
        if (apartmentIndex >= 0 && apartmentIndex < 3) {
            apartments[apartmentIndex].addResident(person);
        }

    }

    void displayAll() const {
        for (int i = 0; i < 3; i++) {
            cout << "Apartment " << (i + 1) << ":" << endl;
            apartments[i].displayResidents();
        }
    }
};

int main() {
    Building building;

    Person person1("Alice", 30);
    Person person2("Bob", 25);
    Person person3("Charlie", 35);
    Person person4("Diana", 28);

    building.addResidentToApartment(0, person1);
    building.addResidentToApartment(0, person2);
    building.addResidentToApartment(1, person3);
    building.addResidentToApartment(2, person4);

    building.displayAll();
}
