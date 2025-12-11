#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Person.h"
#include "Note.h"

class FileManager {
public:
    static void savePersons(const vector<Person>& list);
    static vector<Person> loadPersons();

    static void saveNotes(const vector<Note>& notes);
    static vector<Note> loadNotes();
};

#endif

