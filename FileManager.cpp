#include "FileManager.h"
#include <fstream>

void FileManager::savePersons(const vector<Person>& list) {
    ofstream fout("Data/persons.txt");

    for (auto& p : list) {
        fout << p.getId() << "|"
            << p.getName() << "|"
            << p.getAge() << "|"
            << p.getCity() << "|"
            << p.getCountry() << "|"
            << p.getPhone() << endl;
    }
}

vector<Person> FileManager::loadPersons() {
    vector<Person> out;
    ifstream fin("Data/persons.txt");

    if (!fin.is_open()) return out;

    string id, name, age, city, country, phone;

    while (getline(fin, id, '|')) {
        getline(fin, name, '|');
        getline(fin, age, '|');
        getline(fin, city, '|');
        getline(fin, country, '|');
        getline(fin, phone);

        out.emplace_back(stoi(id), name, stoi(age), city, country, phone);
    }

    return out;
}

void FileManager::saveNotes(const vector<Note>& notes) {
    ofstream fout("Data/notes.txt");

    for (auto& n : notes) {
        fout << n.getPersonId() << "|"
            << n.getContent() << "|"
            << n.getReminder() << endl;
    }
}

vector<Note> FileManager::loadNotes() {
    vector<Note> out;
    ifstream fin("Data/notes.txt");

    if (!fin.is_open()) return out;

    string pid, content, reminder;

    while (getline(fin, pid, '|')) {
        getline(fin, content, '|');
        getline(fin, reminder);

        out.emplace_back(stoi(pid), content, reminder);
    }

    return out;
}
