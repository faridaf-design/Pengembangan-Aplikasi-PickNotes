#ifndef APP_H
#define APP_H

#include <vector>
#include "Person.h"
#include "Note.h"

class App {
private:
    vector<Person> persons;
    vector<Note> notes;

    void menu();
    void registerPerson();
    void editPerson();
    void deletePerson();
    void viewPersons();

    void addNote();
    void viewNotesByPerson();

public:
    App();
    void run();
};

#endif

