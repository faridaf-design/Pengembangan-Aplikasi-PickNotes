#ifndef REMINDER_MANAGER_H
#define REMINDER_MANAGER_H

#include "Reminder.h"
#include <vector>
#include <string>
using namespace std;

class ReminderManager {
private:
    vector<Reminder> reminders;
    string filename;

public:
    ReminderManager(const string& filename);

    void loadFromFile();
    void saveToFile();

    void addReminder(const Reminder& r);
    void deleteReminder(int id);
    void listReminders() const;
};

#endif

