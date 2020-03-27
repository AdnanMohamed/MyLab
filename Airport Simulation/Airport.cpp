// This is the implementation file for the following classes: runway, averager
// and other functions.
// Interface is in: Airport.h
/*
-------- Copyright © ---------
  @Author: Adnan Hashem Mohamed

-------------------------------
*/

#include"Airport.h"
#include<cassert>
#include<iostream> // Provides std::cout

namespace airport_adnan {

    double averager::average() const
    {
        assert(how_many_numbers() != 0);
        return sum / how_many_numbers();
    }

    void runway::one_second()
    {
        if (is_busy())
            --time_left;
    }

    void runway::departure()
    {
        time_left = seconds_for_departure;
    }
    
    void runway::land()
    {
        time_left = seconds_for_landing;
    }

    void display_time(unsigned long int seconds)
    {
        assert(seconds >= 0);
        using std::cout;
        unsigned long int hours = seconds / double(3600);
        seconds %= 3600;
        unsigned long int minutes = seconds / double(60);
        seconds %= 60;
        if (hours < 10)
            cout << "0";
        cout << hours << ":";
        if (minutes < 10)
            cout << "0";
        cout << minutes << ":";
        if (seconds < 10)
            cout << "0";
        cout << seconds;
    }

    bool query(double probability)
    {
        assert(probability >= 0 && probability <= 1);
        return rand() < probability * RAND_MAX;
    }

} // end of namespace