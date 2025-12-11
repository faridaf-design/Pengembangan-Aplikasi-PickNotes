#include "Person.h"

Person::Person() : id(0), name(""), age(0), city(""), country(""), phone("") {}

Person::Person(int id, const string& name, int age, const string& city,
    const string& country, const string& phone)
    : id(id), name(name), age(age), city(city), country(country), phone(phone) {
}

int Person::getId() const { return id; }
string Person::getName() const { return name; }
int Person::getAge() const { return age; }
string Person::getCity() const { return city; }
string Person::getCountry() const { return country; }
string Person::getPhone() const { return phone; }

void Person::setName(const string& n) { name = n; }
void Person::setAge(int a) { age = a; }
void Person::setCity(const string& c) { city = c; }
void Person::setCountry(const string& c) { country = c; }
void Person::setPhone(const string& p) { phone = p; }
