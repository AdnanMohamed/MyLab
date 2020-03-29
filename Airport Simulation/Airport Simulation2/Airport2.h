// header file containing class: Plane , Arguments. Also it has helping functions for the airport simulation.
// Plane, Arguments and functions are within namespace (airport2_adnan)
/*
-------- Copyright © ---------
  @Author: Adnan Hashem Mohamed

-------------------------------
*/
//  ****    DOCUMENTATION   *****
//
// --- CLASS Arguments ---
// CONSTRUCTOR:
//  Arguments(
//    double landing_time = LAND_TIME,
//    double dep_time = DEP_TIME,
//    double dep_prob = MIN_PROBABILITY,
//    double land_prob = MIN_PROBABILITY,
//    double total_time = TOTAL_SIMULATION_TIME,
//    double profit_per_plane = 10,
//    double crash_loss = 255
//   )throw(std::invalid_argument())
//     Postcondition: The object is initialized with the specified arguments.
//     EXCEPTION: throws an exception if any of the arguments are less than the allowed minimum.
//
// Arguments(std::vector<double>args)throw(std::invalid_argument, std::size_t)
//  Precondition: args has the following arguments in this order:
//  landing_time, dep_time, dep_prob, land_prob, total_time
//  Postcondition: the members are set to have the specified arguments.
//  EXCEPTION: throws the size of args if size != number of arguments specified above.
//  throws an exception with a message using std::invalid_argument for any invalid element in args
//
// ACCESSORS FOR THE PERMITED BOUNDS FOR THE ARGUMENTS IN THE CONSTRUCTOR:
//  int min_landing_time()const
//  int min_dep_time()const
//  int min_probability()const
//  int max_probability()const
//  int min_simulation_time()const
//  int number_of_args()const
//
// CLASS Plane
//  CONSTRUCTOR:
//   Plane(double time = 0, double fuel = 0, double consumption = 1 )
//    Precondition: all parameter should be POSITIVE
//    Postcondition: the time the plane arrived to the landing/departure queue, amount of fuel it has,
//    and its engine consumption are set.
//
//  ACCESSORS:
//   double fuel()const
//    Postcondition: The amount of fuel in the plane is returned. (in gallons)
//
//   double timestamp()const
//    Postcondition: The timestamp for when the plane arrived in the
//    deparure/landing queue is returned. (in seconds)
//
//   double consumption()const
//    Postcondition: The engine's efficiency (in gallon/sec) is returned
//
//   bool is_empty()const
//    Postcondition: returns true if the plane has no fuel (fuel == 0)
//    else it returns false
//
// MODIFICATION MEMBERS FUNCTIONS:
//   void consume_fuel(double seconds = 1)through(double)
//    Precondition: 0 ≤ seconds
//    Postcondition: (consumption() * seconds) gallons is burned.
//    If no sufficient fuel to burn, a double is thrown. (the seconds argument is thrown)
//
//   void set_fuel(double fuel);
//    Precondition: 0 ≤ fuel
//    Postcondition: The plane has the given amount of fuel (in gallons)
//
//   void set_timestamp(double timestamp)
//    Precondition: 0 ≤ timestamp
//    Postcondition: The plane's arriving to departure/ landing queue time
//    is set to be equal to the given arument.
//
//   void set_engine_consumption(double consumption = 1);
//    Precondition: 0 ≤ consumption 
//    Postcondition: The plane's engine consumption equals the given argument.
//
// NON-MEMBER FUNCTIONS:
//   bool operator<(const Plane& p1, const Plane& p2)
//    Postcondition: returns true if p1 will run out of fuel before p2
//    else returns false.
//
//   bool operator<=(const Plane& p1, const Plane& p2)
//    Postcondition: returns true if p1 will run out of fuel before OR at 
//    the same time of p2. Else returns false.
//
//   bool operator>(const Plane& p1, const Plane& p2);
//    Postcondition: returns true if p2 will run out of fuel before 
//    p1. Else returns false.
//
//   bool operator>=(const Plane& p1, const Plane& p2);
//    Postcondition: returns true if p2 will run out of fuel before OR at 
//    the same time of p1. Else returns false.   
//
//   bool operator==(const Plane& p1, const Plane& p2);
//    Postcondition: returns true if p1 will run out of fuel at 
//    the same time of p2. Else returns false.
//
//   bool operator!=(const Plane& p1, const Plane& p2)
//    Postcondition: returns true if p1 will run out of fuel at 
//    the different time then p2. Else returns false.
//
//   double give_fuel(double min, double max)
//    Postcondition: returns random amount of fuel ranging from min_fuel gallons to max_fuel gallons (included)
//
//   std::size_t consume_fuel(priority_queue_adnan::priority_queue<Plane>& planes, double seconds = 1)
//    Postcondition: consumes amount of fuel from each plane in 'planes' depending on the
//    given seconds and each plane engine efficiency. Returns number of crashed planes due to lack of fuel.

#ifndef AIRPORT2_H
#define AIRPORT2_H

#include"../Priority Queue/priority_queue.h"
#include<vector>

namespace airport2_adnan {

    class Plane {
    public:
        Plane(
            long double time = 0,
            double fuel = 0,
            double consumption = 1
        );
   

        // MODIFICATION MEMBERS FUNCTIONS:
        void consume_fuel(double seconds = 1)throw(double);
        void set_fuel(double fuel);
        void set_timestamp(long double timestamp);
        void set_engine_conumption(double consumption = 1);

        // CONST MEMBER FUNCTIONS:
        double fuel()const { return fuel_; }
        long double timestamp()const { return timestamp_; }
        double consumption()const { return consumption_; }
        bool is_empty()const { return fuel_ < min_fuel_; }

        friend bool operator<(const Plane& p1, const Plane& p2);
        friend bool operator<=(const Plane& p1, const Plane& p2);
        friend bool operator>(const Plane& p1, const Plane& p2);
        friend bool operator>=(const Plane& p1, const Plane& p2);
        friend bool operator==(const Plane& p1, const Plane& p2);
        friend bool operator!=(const Plane& p1, const Plane& p2);
    private:
        long double timestamp_; // in seconds
        double fuel_; // in gallons
        double consumption_;  // determines fuel consumption in gallon / second
        double min_fuel_ = 1e-6; // exceptable calculation error bound due to double inaccuracy.
    };

    double give_fuel(double min = 2000, double max = 11000);
    double engine_consumption_generator(double min = .7, double max = 2);
    std::size_t consume_fuel(priority_queue_adnan::priority_queue<Plane>& planes, double seconds = 1);
    
    class Arguments{
    public:
        Arguments(
            double landing_time = LAND_TIME,
            double dep_time = DEP_TIME,
            double dep_prob = MIN_PROBABILITY,
            double land_prob = MIN_PROBABILITY,
            double total_time = TOTAL_SIMULATION_TIME,
            double profit_per_plane = 10,
            double crash_loss = 255
        )throw(std::invalid_argument);

        Arguments(std::vector<double>args)throw(std::invalid_argument, std::size_t);

        // ACCESSORS:
        double get_landing_time()const { return landing_time_; }
        double get_dep_time()const { return dep_time_; }
        double get_dep_probability()const { return dep_prob_; }
        double get_land_probability()const { return land_prob_; }
        double get_total_time()const { return total_simulation_time_; }
        double get_profit()const { return profit_; }
        double get_crash_loss()const { return crash_loss_; }

        // ACCESSORS FOR THE CONSTANTS:
        int min_landing_time()const { return LAND_TIME; }
        int min_dep_time()const { return DEP_TIME; }
        int min_probability()const { return MIN_PROBABILITY; }
        int max_probability()const { return MAX_PROBABILITY; }
        int min_simulation_time()const { return TOTAL_SIMULATION_TIME; }
        int number_of_args()const { return VALID_ARGUMENTS; }

    private:
        double landing_time_;                        //  seconds 
        double dep_time_;                            //  seconds
        double dep_prob_;                              
        double land_prob_;                             
        double total_simulation_time_;               //  seconds
        double profit_;                              // in thousands $
        double crash_loss_;                          // in thousands $
        static const int LAND_TIME = 540;            //  seconds
        static const int DEP_TIME = 300;             //  seconds
        static const int TOTAL_SIMULATION_TIME = 350;//  seconds
        static const int MIN_PROBABILITY = 0;        
        static const int MAX_PROBABILITY = 1;    
        static const int VALID_ARGUMENTS = 7;
    };
}


#endif // !AIRPORT2_H

