#include "Note.h"

Note::Note() : personId(0), content(""), reminder("") {}

Note::Note(int personId, const string& content, const string& reminder)
    : personId(personId), content(content), reminder(reminder) {
}

int Note::getPersonId() const { return personId; }
string Note::getContent() const { return content; }
string Note::getReminder() const { return reminder; }
