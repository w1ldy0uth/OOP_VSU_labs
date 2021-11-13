#include <ctime>
#include <string>

typedef unsigned int uint;
const uint SECONDS_IN_DAY = 86400;

class Time {
    uint hours;
    uint minutes;
    uint seconds;

    void normalizeTime();

public:
    Time();
    Time(uint, uint, uint);
    Time(std::string);
    Time(uint);
    Time(std::tm);

    uint getHours();
    uint getMinutes();
    uint getSeconds();
    void setHours(uint);
    void setMinutes(uint);
    void setSeconds(uint);

    uint toMinutes() const;
    uint toSeconds() const;

    friend std::ostream& operator<<(std::ostream&, const Time&);

    friend bool operator==(Time, Time);
    friend bool operator!=(Time, Time);
    friend bool operator>=(Time, Time);
    friend bool operator<=(Time, Time);
    friend bool operator>(Time, Time);
    friend bool operator<(Time, Time);

    friend Time operator+(Time, uint);
    friend Time operator+(Time, Time);
    friend Time operator-(Time, uint);
    friend uint operator-(Time, Time);
};
