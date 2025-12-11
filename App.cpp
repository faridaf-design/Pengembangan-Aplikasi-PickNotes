#include "App.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

App::App() {
    persons = FileManager::loadPersons();
    notes = FileManager::loadNotes();
}

void App::menu() {
    cout << "\n===== PickNotes Menu =====\n";
    cout << "1. Register new person\n";
    cout << "2. Edit person data\n";
    cout << "3. Delete person\n";
    cout << "4. View all persons\n";
    cout << "5. Add note\n";
    cout << "6. View notes by person\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

void App::run() {
    int choice;

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: registerPerson(); break;
        case 2: editPerson(); break;
        case 3: deletePerson(); break;
        case 4: viewPersons(); break;
        case 5: addNote(); break;
        case 6: viewNotesByPerson(); break;
        case 0:
            FileManager::savePersons(persons);
            FileManager::saveNotes(notes);
            cout << "Exiting..." << endl;
            return;
        default:
            cout << "Invalid input!\n";
        }
    }
}

void App::registerPerson() {
    int id = persons.size() + 1;
    string name, city, country, phone;
    int age;

    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "City: "; cin >> city;
    cout << "Country: "; cin >> country;
    cout << "Phone: "; cin >> phone;

    persons.emplace_back(id, name, age, city, country, phone);
}

void App::editPerson() {
    int id;
    cout << "Enter ID to edit: ";
    cin >> id;

    for (auto& p : persons) {
        if (p.getId() == id) {
            string name, city, country, phone;
            int age;

            cout << "New name: "; cin >> name;
            cout << "New age: "; cin >> age;
            cout << "New city: "; cin >> city;
            cout << "New country: "; cin >> country;
            cout << "New phone: "; cin >> phone;

            p.setName(name);
            p.setAge(age);
            p.setCity(city);
            p.setCountry(country);
            p.setPhone(phone);
            return;
        }
    }
    cout << "ID not found.\n";
}

void App::deletePerson() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    persons.erase(
        remove_if(persons.begin(), persons.end(),
            [id](const Person& p) { return p.getId() == id; }),
        persons.end());

    cout << "Deleted.\n";
}

void App::viewPersons() {
    for (auto& p : persons) {
        cout << p.getId() << ". " << p.getName()
            << " (" << p.getAge() << ", " << p.getCity() << ")\n";
    }
}

void App::addNote() {
    int id;
    cout << "Enter person ID: ";
    cin >> id;

    string content, reminder;
    cout << "Note content: "; cin >> content;
    cout << "Reminder: "; cin >> reminder;

    notes.emplace_back(id, content, reminder);
}

void App::viewNotesByPerson() {
    int id;
    cout << "Enter person ID: ";
    cin >> id;

    for (auto& n : notes) {
        if (n.getPersonId() == id) {
            cout << "- " << n.getContent()
                << " (Reminder: " << n.getReminder() << ")\n";
        }
    }
}
