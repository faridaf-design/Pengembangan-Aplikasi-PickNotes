#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    int id;
    string name;
    int age;
    string city;
    string country;
    string phone;

public:
    Person();
    Person(int id, const string& name, int age, const string& city,
        const string& country, const string& phone);

    int getId() const;
    string getName() const;
    int getAge() const;
    string getCity() const;
    string getCountry() const;
    string getPhone() const;

 
    void setName(const string&);
    void setAge(int);
    void setCity(const string&);
    void setCountry(const string&);
    void setPhone(const string&);
};

#endif

