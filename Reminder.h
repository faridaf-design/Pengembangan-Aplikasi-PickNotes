#ifndef REMINDER_H
#define REMINDER_H

#include <string>
using namespace std;

class Reminder {
private:
    int id;
    string title;
    string date;  
    string time;  
    string notes;

public:
    Reminder();
    Reminder(int id, const string& title, const string& date,
        const string& time, const string& notes);

    int getId() const;
    string getTitle() const;
    string getDate() const;
    string getTime() const;
    string getNotes() const;

    string serialize() const;              
    static Reminder deserialize(const string& line); 
};

#endif

