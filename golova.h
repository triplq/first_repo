//
// Created by Алексей Ярошенко on 21.06.2024.
//

#ifndef UNTITLED_GOLOVA_H
#define UNTITLED_GOLOVA_H

#include <iostream>
#include <ctime>
#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <exception>
#include <string>
#include <map>

using namespace std;
using namespace soci;

bool price_checker(const string&);
void insert_into_purchases(session&);
void insert_into_flights(session&);
void insert_into_db(session&);
void admin(session&);
void user(session&);
class timestamp
{
private:
    int g_year{};
    int g_month{};
    int g_day{};
    int g_hour{};
    int g_minute{};
    int g_second{};
public:
    bool digital(const string&);
    bool checker(const string&);
    operator tm() const;
    timestamp();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void print() const;
};
//bool digital(const string&);
//bool checker(const string&, tm&);
//tm getTime();

#endif //UNTITLED_GOLOVA_H

ostream& operator<<(ostream& os, const timestamp& ts)
{
    return os << "'" << ts.getYear() << '-' << ts.getMonth() << '-' << ts.getDay() << ' ' << ts.getHour() << ':' << ts.getMinute() << ':' << ts.getSecond() << "'";
}

bool price_checker(const string& price)
{
    for(short i = price.size()-1; i >= 0; i--)
        if(price[i] == '.' && i == price.size()-3)
            continue;
        else if(!isdigit(price[i]))
            return false;

    return true;
}

void insert_into_purchases(session& sql)
{
    int flight_id{-1};
    int count_flight_id;
    sql << "SELECT count(flight_id) FROM flights", into(count_flight_id);
    while(flight_id > count_flight_id || flight_id <= 0)
    {
        cout << "flight_id: ";
        cin >> flight_id;
    }
    sql << "INSERT INTO purchases(flight_id) VALUES(:fl_id)", use(flight_id, "fl_id");
    cout << "succes\n";

} //done

void insert_into_flights(session& sql)
{
    int plane_id{-1};
    int first_port{-1};
    int end_port{-1};
    bool stops{false};
    float price;
    int seats;
    unsigned seats_reserved{0};

    unsigned n;
    sql << "SELECT count(plane_id) FROM planes", into(n);
    while(plane_id < 0 || plane_id > n)
    {
        cout << "enter a plane_id: ";
        cin >> plane_id;
    }
    sql << "SELECT seats FROM planes WHERE plane_id = " << plane_id, into(seats);

    while(first_port > n || first_port < 1)
    {
        cout << "enter first port: ";
        cin >> first_port;
    }

    while((end_port > n || end_port < 1) && end_port != first_port)
    {
        cout << "enter end port: ";
        cin >> end_port;
    }

    auto answer{make_unique<short>(-1)};
    while(*answer < 1 || *answer > 2)
    {
        cout << "there is will be stops?: \n1.Yes\n2.No\n";
        cin >> *answer;
    }
    if(*answer == 1)
        //insert_into_stops;
    answer.reset();

    auto price_str{make_unique<string>()};
    while(true)
    {
        cout << "enter a cost(X.XX): ";
        cin.ignore();
        getline(cin, *price_str);
        if(price_checker(*price_str))
            break;
    }
    price = stof(*price_str);
    price_str.reset();

    cout << "enter deportation time: ";
    timestamp dep_time;
    cout << "enter arrival time: ";
    timestamp arr_time;

//    vector<int> busy_planes;
    vector<int> busy_planes{-1};
    tm t1 = tm(arr_time);
    mktime(&t1);
    sql << "SELECT plane_id FROM flights WHERE arr_time ",into(busy_planes), use(t1, "t1");



    return;

}

void insert_into_db(session& sql)
{
    while(true)
    {
        int table;
        cout << "in what table insert?:\n1.purchase\n2.flights\n3.planes\n4.airports\n5.stops\n6.exit\n";
        cin >> table;
        switch (table)
        {
            case 1:
                insert_into_purchases(sql);
                break;
            case 2:
                insert_into_flights(sql);
                break;
//            case 3:
//                insert_into_planes(sql);
//                break;
//            case 4:
//                insert_into_airports(sql);
//                break;
//            case 5:
//                insert_into_stops(sql);
//                break;
            case 6:
                return;
            default:
                cout << "wrong\n";
        }
    }
}

//void user()
//{
//    while(true)
//    {
//        int answer;
//        cout << "what to do:\n";
//        //    1 buy a ticket
//        //    2 sell a ticket
//        //    3 output in a time
//        //    4 free seats
//        //    5 profit in a time
//        //    6 schedule
//        //    7 exit
//        cin >> answer;
//        switch (answer)
//        {
//            case 1:
//                buy_ticket();
//                break;
//            case 2:
//                sell_ticket();
//                break;
//            case 3:
//                output_in_a_time();
//                break;
//            case 4:
//                free_seats();
//                break;
//            case 5:
//                profit_in_a_time();
//                break;
//            case 6:
//                schedule();
//                break;
//            case 7:
//                return;
//            default:
//                cout << "no such command\n";
//        }
//    }
//}

void admin(session& sql)
{
    insert_into_db(sql);//    add smth in a table
//    3 output in a time
//    4 free seats
//    5 profit in a time
//    6 schedule
}

bool timestamp::digital(const string& str)
{
    for(int i = 0; i < str.size()-1; i++)
    {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

bool timestamp::checker(const string& date_time)
{
    map<unsigned, vector<unsigned>> ends;
    ends[30] = {4, 6, 9, 11};
    ends[31] = {1, 3, 5, 7, 8, 10, 12};

    if(!digital(date_time.substr(0,4)))
    {
        cout << "year not a digit\n";
        return false;
    }
    auto year {make_unique<int>(stoi(date_time.substr(0,4)))};
    if(*year > 2300 || *year < 2024)
    {
        cout << *year << '\n';
        cout << "year_wrong\n";
        return false;
    }
    else
        this->g_year = *year;

    if(date_time[4] != '-')
    {
        cout << "first_pass_wrong\n";
        return false;
    }

    if(!digital(date_time.substr(5,2)))
    {
        cout << "month isnt a digit\n";
        return false;
    }
    auto month {make_unique<int>(stoi(date_time.substr(5,2)))};
    if(*month < 1 || *month > 12)
    {
        cout << "month_wrong\n";
        return false;
    }
    else
        this->g_month = *month;

    unsigned i;
    if(isdigit(date_time[5]) && isdigit(date_time[6]))
        i = 8;
    else if(isdigit(date_time[5]) && date_time[6] == '-')
        i = 7;
    else
    {
        cout << "second_pass_wrong\n";
        return false;
    }

    if(!digital(date_time.substr(i, 2)))
    {
        cout << "day isnt a digit\n";
        return false;
    }
    auto day {make_unique<int>(stoi(date_time.substr(i, 2)))};

    unsigned max_days;
    if (ends[31].end() != find(ends[31].begin(), ends[31].end(), *month))
        max_days = 31;
    else if (ends[30].end() != find(ends[30].begin(), ends[30].end(), *month))
        max_days = 30;
    else if (*month == 2 && *year % 4 == 0)
        max_days = 29;
    else if (*month == 2)
        max_days = 28;
    if (*day < 1 || *day > max_days)
    {
        cout << "day_wrong\n";
        cout << *day << ' ';
        cout << max_days << '\n';
        return false;
    }
    else
        this->g_day = *day;

    if(isdigit(date_time[i+1]))
        i += 2;
    else if(!isdigit(date_time[i+1]))
        i += 1;


    day.reset();
    month.reset();
    year.reset();

    if(date_time[i] != ' ')
    {
        cout << "wrong ' '\n";
        return false;
    }
    i++;

    int time[3] {-1,-1,-1};
    unsigned j = 0;
    for(; i < date_time.size(); i++)
    {
        if(!isdigit(date_time[i]) && date_time[i] != ':' || date_time[i] == ':' && i+1 != date_time.size() && date_time[i+1] == ':')
        {
            cout << "wrong symb\n";
            return false;
        }
        else if(isdigit(date_time[i]) && i+1 != date_time.size() && isdigit(date_time[i+1]))
        {
            if(i+2 != date_time.size() && date_time[i+2] != ':')
            {
                cout << "wrong time\n";
                return false;
            }
            time[j] = (date_time[i] - '0') * 10 + (date_time[i+1] - '0');
            i++;
            j++;
        }
        else if(isdigit(date_time[i]) && ((i+1 != date_time.size() && date_time[i+1] == ':') || (i+1 == date_time.size())))
        {
            time[j] = (date_time[i] - '0');
            i++;
            j++;
        }

        if(j == 4)
        {
            cout << "wrong\n";
            return false;
        }
    }

    if (time[0] > 23 || time[0] < 0 || time[1] > 59 || time[1] < 0 || time[2] > 59 || time[2] < 0)
    {
        cout << "wrong time\n";
        return false;
    }

    this->g_hour = time[0];
    this->g_minute = time[1];
    this->g_second = time[2];

    return true;
}

timestamp::timestamp()
{
    string date_time;
    cout << "enter 'xxxx-xx-xx xx:xx:xx': ";
    while(true)
    {
        getline(cin, date_time);
        if(checker(date_time))
        {
            cout << "succes\n";
            break;
        }
    }
}

void timestamp::print() const
{
    cout << this->g_year << '-' << this->g_month << '-' << this->g_day << '\n';
}

int timestamp::getYear() const {return g_year;}
int timestamp::getMonth() const {return g_month;}
int timestamp::getDay() const {return g_day;}
int timestamp::getHour() const {return g_hour;}
int timestamp::getMinute() const {return g_minute;}
int timestamp::getSecond() const {return g_second;}

timestamp::operator tm() const {
    return tm{g_second, g_minute, g_hour, g_day, g_month-1, g_year-1900, .tm_isdst = -1};
}

//tm getTime()
//{
//    string date_time;
//    tm time{};
//    cout << "enter 'xxxx-xx-xx xx:xx:xx': ";
//    while(true)
//    {
//        getline(cin, date_time);
//        if(checker(date_time, time))
//        {
//            cout << "succes\n";
//            break;
//        }
//    }
//
//    return time;
//}

//bool digital(const string& str)
//{
//    for(int i = 0; i < str.size()-1; i++)
//    {
//        if(!isdigit(str[i]))
//            return false;
//    }
//    return true;
//}
//
//bool checker(const string& date_time, tm&)
//{
//    map<unsigned, vector<unsigned>> ends;
//    ends[30] = {4, 6, 9, 11};
//    ends[31] = {1, 3, 5, 7, 8, 10, 12};
//
//    if (!digital(date_time.substr(0, 4))) {
//        cout << "year not a digit\n";
//        return false;
//    }
//    auto year{make_unique<int>(stoi(date_time.substr(0, 4)))};
//    if (*year > 2300 || *year < 2024) {
//        cout << *year << '\n';
//        cout << "year_wrong\n";
//        return false;
//    } else
//        this->g_year = *year;
//
//    if (date_time[4] != '-') {
//        cout << "first_pass_wrong\n";
//        return false;
//    }
//
//    if (!digital(date_time.substr(5, 2))) {
//        cout << "month isnt a digit\n";
//        return false;
//    }
//    auto month{make_unique<int>(stoi(date_time.substr(5, 2)))};
//    if (*month < 1 || *month > 12) {
//        cout << "month_wrong\n";
//        return false;
//    } else
//        this->g_month = *month;
//
//    unsigned i;
//    if (isdigit(date_time[5]) && isdigit(date_time[6]))
//        i = 8;
//    else if (isdigit(date_time[5]) && date_time[6] == '-')
//        i = 7;
//    else {
//        cout << "second_pass_wrong\n";
//        return false;
//    }
//
//    if (!digital(date_time.substr(i, 2))) {
//        cout << "day isnt a digit\n";
//        return false;
//    }
//    auto day{make_unique<int>(stoi(date_time.substr(i, 2)))};
//
//    unsigned max_days;
//    if (ends[31].end() != find(ends[31].begin(), ends[31].end(), *month))
//        max_days = 31;
//    else if (ends[30].end() != find(ends[30].begin(), ends[30].end(), *month))
//        max_days = 30;
//    else if (*month == 2 && *year % 4 == 0)
//        max_days = 29;
//    else if (*month == 2)
//        max_days = 28;
//    if (*day < 1 || *day > max_days) {
//        cout << "day_wrong\n";
//        cout << *day << ' ';
//        cout << max_days << '\n';
//        return false;
//    } else
//        this->g_day = *day;
//
//    if (isdigit(date_time[i + 1]))
//        i += 2;
//    else if (!isdigit(date_time[i + 1]))
//        i += 1;
//
//
//    day.reset();
//    month.reset();
//    year.reset();
//
//    if (date_time[i] != ' ') {
//        cout << "wrong ' '\n";
//        return false;
//    }
//    i++;
//
//    int time[3]{-1, -1, -1};
//    unsigned j = 0;
//    for (; i < date_time.size(); i++) {
//        if (!isdigit(date_time[i]) && date_time[i] != ':' ||
//            date_time[i] == ':' && i + 1 != date_time.size() && date_time[i + 1] == ':') {
//            cout << "wrong symb\n";
//            return false;
//        } else if (isdigit(date_time[i]) && i + 1 != date_time.size() && isdigit(date_time[i + 1])) {
//            if (i + 2 != date_time.size() && date_time[i + 2] != ':') {
//                cout << "wrong time\n";
//                return false;
//            }
//            time[j] = (date_time[i] - '0') * 10 + (date_time[i + 1] - '0');
//            i++;
//            j++;
//        } else if (isdigit(date_time[i]) &&
//                   ((i + 1 != date_time.size() && date_time[i + 1] == ':') || (i + 1 == date_time.size()))) {
//            time[j] = (date_time[i] - '0');
//            i++;
//            j++;
//        }
//
//        if (j == 4) {
//            cout << "wrong\n";
//            return false;
//        }
//    }
//
//    if (time[0] > 23 || time[0] < 0 || time[1] > 59 || time[1] < 0 || time[2] > 59 || time[2] < 0) {
//        cout << "wrong time\n";
//        return false;
//    }
//
//    this->g_hour = time[0];
//    this->g_minute = time[1];
//    this->g_second = time[2];
//
//    return true;
//}