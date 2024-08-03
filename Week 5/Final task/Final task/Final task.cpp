#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <locale.h>
using namespace std;

struct Year {
    int value;
    explicit Year(int new_value) : value(new_value) {}
};
struct Month {
    int value;
    explicit Month(int new_value) : value(new_value) {}
};
struct Day {
    int value;
    explicit Day(int new_value) : value(new_value) {}
};


class Date {
public:
    Date(Year new_year, Month new_month, Day new_day) :
        year(new_year.value), month(new_month.value), day(new_day.value) {}
    int GetYear() const { return year; };
    int GetMonth() const { return month; };
    int GetDay() const { return day; };
private:
    int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) { return true; }
    else if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() < rhs.GetMonth()) {
            return true;
        }
        else if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
    }
    return false;
}

void PrintDate(const Date& date) {
    cout << setw(4) << setfill('0') << date.GetYear() << "-"
        << setw(2) << setfill('0') << date.GetMonth() << "-"
        << setw(2) << setfill('0') << date.GetDay();
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        map_db[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        bool findDeleteEvent = false;
        if (map_db.count(date)) {
            if (map_db[date].count(event)) {
                map_db[date].erase(event);
                findDeleteEvent = true;
                return findDeleteEvent;
            }
            else { return findDeleteEvent; }
        }
        else { return findDeleteEvent; }
    }
    int  DeleteDate(const Date& date) {
        if (map_db.count(date)) {
            int deletedEvents = map_db[date].size();
            map_db.erase(date);
            return deletedEvents;
        }
        else {
            return 0;
        }
    }
    set <string> Find(const Date& date) const {
        set <string> empty_set;
        if (map_db.count(date)) {
            return map_db.at(date);
        }
        else {
            return empty_set;
        }
    }

    void Print() const {
        for (const auto& [date, set_events] : map_db) {
            if (date.GetYear() >= 0) {
                PrintDate(date);
                for (const auto& event : set_events) {
                    cout << " " << event;
                }
                cout << "\n";
            }
        }
    }

private:
    map <Date, set <string>> map_db;
};

bool parseCommand(const string& command, string& command_word, int& year, int& month, int& day, string& event) {
    bool flagDoParse = false;
    if (command.size() != 0) {
        flagDoParse = true;
        stringstream stream1(command);
        vector <string> s{ 2 };
        for (int i = 0; i < 2; ++i) {
            stream1 >> s[i];
        }
        stringstream stream(command);
        stream >> command_word;
        if (command_word == "Add" || command_word == "Del" || command_word == "Find") {
            stream.ignore(1);
            stream >> year;
            string incorrect_date_format;
            string error;
            if (stream.peek() != '-') {
                error = "Wrong date format: " + s[1];
                throw runtime_error(error);
            }
            stream.ignore(1);
            stream >> month;
            if (stream.peek() != '-') {
                error = "Wrong date format: " + s[1];
                throw runtime_error(error);
            }
            stream.ignore(1);
            stream >> day;
            stream.ignore(1);
            stream >> event;
            if (month < 1 || month > 12) {
                error = "Month value is invalid:" + to_string(month);
                throw runtime_error(error);
            }
            else if (day < 1 || day > 31) {
                error = "Day value is invalid:" + to_string(day);
                throw runtime_error(error);
            }
        }
        return flagDoParse;
    }
    else {
        return flagDoParse;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Database db;
    string command, command_word;
    while (getline(cin, command)) {
        int day = 0, month = 0, year = 0;
        string event;
        try {
            if (parseCommand(command, command_word, year, month, day, event)) {
                Date date(Year{ year }, Month{ month }, Day{ day });
                if (command_word == "Add") {
                    db.AddEvent(date, event);
                }
                else if (command_word == "Del") {
                    if (event == "") { cout << "Deleted " << db.DeleteDate(date) << " events" << endl; }
                    else {
                        if (db.DeleteEvent(date, event)) { cout << "Deleted successfully" << endl; }
                        else { cout << "Event not found" << endl; }
                    }
                }
                else if (command_word == "Find") {
                    if (db.Find(date).size() == 0) {
                        cout << "Нет событий на этот день!" << endl;
                    }
                    else {
                        for (const auto& item : db.Find(date)) {
                            cout << item << endl;
                        }
                    }
                }
                else if (command_word == "Print") {
                    db.Print();
                }
                else {
                    cout << "Unknown " << command_word << endl;
                }
            }
            else {
                continue;
            }
        }
        catch (exception& ex) {
            cout << ex.what() << endl;
        }
    }
    return 0;
}