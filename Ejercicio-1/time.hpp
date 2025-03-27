#pragma once
#include <string>

class Time {
    private:
        int hour;
        int minutes;
        int seconds;
        std::string daytime;
    public:
        Time(int hour=0, int minutes=0, int seconds=0, std::string daytime="a.m.");
        int getHour();
        int getMinutes();
        int getSeconds();
        std::string getDaytime();
        void getTime();
        void setHour(int hour);
        void setMinutes(int minutes);
        void setSeconds(int seconds);
        void setDaytime(std::string daytime);
        void printTime();
};