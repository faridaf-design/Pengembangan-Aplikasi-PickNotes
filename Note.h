#ifndef NOTE_H
#define NOTE_H

#include <string>
using namespace std;

class Note {
private:
    int personId;
    string content;
    string reminder;

public:
    Note();
    Note(int personId, const string& content, const string& reminder);

    int getPersonId() const;
    string getContent() const;
    string getReminder() const;
};

#endif

