// This is the interface for the following classes: averager, runway
// and other useful functions used in the simulation.
// Classes + functions are within namespace (airport_adnan)
/*
-------- Copyright © ---------
  @Author: Adnan Hashem Mohamed

-------------------------------  
*/
//*** DOCUMENTATION ***
//
// For averager class:
//  CONSTRUCTOR:
//   averager()
//    Postcondition: This averager is initialized. (No numbers to be averaged)
//  
//  MODIFICATION MEMBERS:
//   void add_number(double value)     
//    Postcondition: value is added to the total numbers to be averaged.
//  
//  ACCESSORS:
//   std::size_t how_many_numbers() const
//    Postcondition: returns how many numbers to be averaged.
//   
//   double average() const
//    Precondition: There are numbers to be averaged.
//    Postcondition: returns the average.
//
// CLASS: runway
// CONSTRUCTOR:
//  runway(unsigned long int dep_time = 1800, unsigned long int land_time = 1800) 
//   Postcondition: The runway is initializes both departure/landing 
//   times to be 's' seconds (if not given both are 1800s = 30 min)
// MODIFICATION functions
//  void one_second()
//   Precondition: the runway is busy.
//   Postcondition: records the passage of one second
//
//  void departure()
//   Precondition: The runway is not busy.
//   Postcondition: The runway is experiencing departure.
//   The runway is busy for the number of seconds given as the amount of time to departure.
//  
//  void land()
//   Precondition: The runway is not busy.
//   Postcondition: The runway is experiencing landing.
//   The runway is busy for the number of seconds given as the amount of time to departure.
//
// CONST FUNCTIONS:
//  bool is_busy() const
//   Postcondition: returns true if no departure/ landing is happening. else returns false.
//
// NON-MEMBER FUNCTIONS:
//  void display_time(unsigned long int seconds)
//   Precondition: seconds is NOT negative
//   Postcondition: displays the amount of seconds in the form "hh:mm:ss"
//
//  bool query(double probability)
//   Precondition: 0 <= probability <= 1
//   Postcondition: returns true depending on the probability.
//   So if probability = 1, it will return true all the time.
//   and if probability = 0 it will never return true.

#ifndef AIRPORT_SIMULATION_H
#define AIRPORT_SIMULATION_H
#include<cstdlib> // Provides std::size_t

namespace airport_adnan {

    class averager
    {
    public:
        // CONSTRUCTOR
        averager():sum(0), count(0){}
        // MODIFICATION function
        void add_number(double value) { count++; sum += value; }
        // CONSTANT functions
        std::size_t how_many_numbers() const { return count; }
        double average() const;
    private:
        std::size_t count; // How many numbers have been given to the averager
        double sum;   // Sum of all the numbers given to the averager
    };

    class runway
    {
    public:
        // CONSTRUCTOR
        runway(unsigned long int dep_time = 1800, unsigned long int land_time = 1800)
        {
            seconds_for_departure = dep_time;
            seconds_for_landing = land_time;
            time_left = 0;
        }
        // MODIFICATION functions
        void one_second();
        void departure();
        void land();
        // CONSTANT function
        bool is_busy() const { return (time_left > 0); }
    private:
        unsigned long int seconds_for_departure; // Seconds for a single airplane to departure
        unsigned long int seconds_for_landing; // Seconds for a single airplane to land
        unsigned long int time_left;   // Seconds until the runway is free.
    };

    void display_time(unsigned long int seconds);
    bool query(double probability);

#endif // !AIRPORT_SIMULATION_H




} // end of namespace
