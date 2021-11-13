#include "time.h"

Time::Time() {
    hours = minutes = seconds = 0;
}

Time::Time(uint _hours, uint _minutes, uint _seconds) {
    hours = _hours;
    minutes = _minutes;
    seconds = _seconds;
    normalizeTime();
}

Time::Time(std::string time) { // подавать строку в формате "чч:мм:сс"
    hours = (time[0] - '0') * 10 + (time[1] - '0');
    minutes = (time[3] - '0') * 10 + (time[4] - '0');
    seconds = (time[6] - '0') * 10 + (time[7] - '0');
    normalizeTime();
}

Time::Time(uint totalSeconds) {
    seconds = totalSeconds % 60;
    minutes = (totalSeconds / 60) % 60;
    hours = totalSeconds / 3600;
    normalizeTime();
}

Time::Time(std::tm localTime) {
    hours = localTime.tm_hour;
    minutes = localTime.tm_min;
    seconds = localTime.tm_sec;
    normalizeTime();
}

void Time::normalizeTime() {
    if (seconds > 59) {
        minutes += 1 + (seconds - seconds % 60) / 60;
        seconds %= 60;
    }
    if (minutes > 59) {
        hours += 1 + (minutes - minutes % 60) / 60;
        minutes %= 60;
    }
    if (hours > 23)
        hours %= 24;
}

uint Time::getHours() {
    return hours;
}

uint Time::getMinutes() {
    return minutes;
}

uint Time::getSeconds() {
    return seconds;
}

void Time::setHours(uint _hours) {
    hours = _hours;
}

void Time::setMinutes(uint _minutes) {
    hours = _minutes;
}

void Time::setSeconds(uint _seconds) {
    hours = _seconds;
}

uint Time::toMinutes()  const {
    return seconds > 0 ? hours * 60 + minutes + 1 : hours * 60 + minutes;
}

uint Time::toSeconds() const {
    return (hours * 60 + minutes) * 60 + seconds;
}

std::ostream& operator<<(std::ostream& out, const Time& moment) {
    std::string toOut;
    toOut += moment.hours < 10 ? "0" + std::to_string(moment.hours) + ":" : std::to_string(moment.hours) + ":";
    toOut += moment.minutes < 10 ? "0" + std::to_string(moment.minutes) + ":" : std::to_string(moment.minutes) + ":";
    toOut += moment.seconds < 10 ? "0" + std::to_string(moment.seconds) : std::to_string(moment.seconds);
    out << toOut;
    return out;
}

bool operator==(Time moment1, Time moment2) {
    return moment1.hours == moment2.hours && moment1.minutes == moment2.minutes && moment1.seconds == moment2.seconds;
}

bool operator!=(Time moment1, Time moment2) {
    return moment1.hours != moment2.hours || moment1.minutes != moment2.minutes || moment1.seconds != moment2.seconds;
}

bool operator>=(Time moment1, Time moment2) {
    bool flag = false;
    if (moment1.hours > moment2.hours)
        flag = true;
    if (moment1.minutes > moment2.minutes && moment1.hours == moment2.hours)
        flag = true;
    if (moment1.minutes == moment2.minutes && moment1.hours == moment2.hours && moment1.seconds >= moment2.seconds)
        flag = true;
    return flag;
}

bool operator<=(Time moment1, Time moment2) {
    bool flag = false;
    if (moment1.hours < moment2.hours)
        flag = true;
    if (moment1.minutes < moment2.minutes && moment1.hours == moment2.hours)
        flag = true;
    if (moment1.minutes == moment2.minutes && moment1.hours == moment2.hours && moment1.seconds <= moment2.seconds)
        flag = true;
    return flag;
}

bool operator>(Time moment1, Time moment2) {
    bool flag = false;
    if (moment1.hours > moment2.hours)
        flag = true;
    if (moment1.minutes > moment2.minutes && moment1.hours == moment2.hours)
        flag = true;
    if (moment1.minutes == moment2.minutes && moment1.hours == moment2.hours && moment1.seconds > moment2.seconds)
        flag = true;
    return flag;
}

bool operator<(Time moment1, Time moment2) {
    bool flag = false;
    if (moment1.hours < moment2.hours)
        flag = true;
    if (moment1.minutes < moment2.minutes && moment1.hours == moment2.hours)
        flag = true;
    if (moment1.minutes == moment2.minutes && moment1.hours == moment2.hours && moment1.seconds < moment2.seconds)
        flag = true;
    return flag;
}

Time operator+(Time moment, uint dst) {
    uint secs = moment.toSeconds();
    secs += dst;
    Time res(secs);
    return res;
}

Time operator+(Time moment1, Time moment2) {
    uint secs1 = moment1.toSeconds(), secs2 = moment2.toSeconds();
    Time res(secs1 + secs2);
    return res;
}

Time operator-(Time moment, uint dst) {
    int diff = (int)moment.toSeconds() - (int)dst;
    uint resSecs = diff < 0 ? SECONDS_IN_DAY + diff : diff;
    Time res(resSecs);
    return res;
}

uint operator-(Time moment1, Time moment2) {
    int secs1 = (int)moment1.toSeconds(), secs2 = (int)moment2.toSeconds();
    return (uint)std::abs(secs1 - secs2);
}