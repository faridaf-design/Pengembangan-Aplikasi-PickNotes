#include "ReminderManager.h"
#include <fstream>
#include <iostream>

ReminderManager::ReminderManager(const string& filename)
    : filename(filename) {
}

void ReminderManager::loadFromFile() {
    reminders.clear();
    ifstream in(filename);
    if (!in.is_open()) return;

    string line;
    while (getline(in, line)) {
        if (!line.empty()) {
            reminders.push_back(Reminder::deserialize(line));
        }
    }

    in.close();
}

void ReminderManager::saveToFile() {
    ofstream out(filename);
    for (const auto& r : reminders) {
        out << r.serialize() << "\n";
    }
    out.close();
}

void ReminderManager::addReminder(const Reminder& r) {
    reminders.push_back(r);
    saveToFile();
}

void ReminderManager::deleteReminder(int id) {
    for (size_t i = 0; i < reminders.size(); ++i) {
        if (reminders[i].getId() == id) {
            reminders.erase(reminders.begin() + i);
            break;
        }
    }
    saveToFile();
}

void ReminderManager::listReminders() const {
    if (reminders.empty()) {
        cout << "Belum ada reminder.\n";
        return;
    }

    cout << "\n=== Daftar Reminder ===\n";
    for (const auto& r : reminders) {
        cout << "ID: " << r.getId() << "\n"
            << "Judul: " << r.getTitle() << "\n"
            << "Tanggal: " << r.getDate() << "\n"
            << "Waktu: " << r.getTime() << "\n"
            << "Catatan: " << r.getNotes() << "\n\n";
    }
}
