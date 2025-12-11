#include "Reminder.h"
#include <sstream>
#include <vector>

static vector<string> split(const string& s, char d) {
    vector<string> out;
    string cur;
    for (char c : s) {
        if (c == d) { out.push_back(cur); cur.clear(); }
        else cur.push_back(c);
    }
    out.push_back(cur);
    return out;
}

Reminder::Reminder() : id(0), title(""), date(""), time(""), notes("") {}

Reminder::Reminder(int id, const string& title, const string& date,
    const string& time, const string& notes)
    : id(id), title(title), date(date), time(time), notes(notes) {
}

int Reminder::getId() const { return id; }
string Reminder::getTitle() const { return title; }
string Reminder::getDate() const { return date; }
string Reminder::getTime() const { return time; }
string Reminder::getNotes() const { return notes; }

string Reminder::serialize() const {
    return to_string(id) + "|" + title + "|" + date + "|" + time + "|" + notes;
}

Reminder Reminder::deserialize(const string& line) {
    vector<string> t = split(line, '|');
    return Reminder(
        stoi(t[0]),
        t[1],
        t[2],
        t[3],
        t[4]
    );
}
