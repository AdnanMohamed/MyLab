// Implementation file for class Plane and helpful functions used in the airport simulation2
// The header file: Airport2.h
//
/*
-------- Copyright © ---------
  @Author: Adnan Hashem Mohamed

-------------------------------
*/

#include<cstdlib>
#include"../Priority Queue/priority_queue.h"
#include"Airport2.h"
#include<climits> // Provides UINT_MAX
#include<cassert> // Provides assert()
#include<vector>

namespace airport2_adnan {

    Plane::Plane(
        long double time,
        double fuel,
        double consumption
    )
    {
        assert(time >= 0 && fuel >= 0 && consumption >= 0);
        timestamp_ = time;
        fuel_ = fuel;
        consumption_ = consumption;
    }

    void Plane::consume_fuel(double seconds)throw(double)
    {
        assert(seconds >= 0);
        if (fuel_ - (consumption_ * seconds) < -min_fuel_)
            throw seconds;
        else
            fuel_ -= consumption_ * seconds;
    }

    void Plane::set_fuel(double fuel)
    {
        assert(fuel >= 0);
        fuel_ = fuel;
    }

    void Plane::set_timestamp(long double timestamp)
    {
        assert(timestamp >= 0);
        timestamp_ = timestamp;
    }

    void Plane::set_engine_conumption(double consumption)
    {
        assert(consumption >= 0);
        consumption_ = consumption;
    }

    double give_fuel(double min, double max)
    {
        double f = double(rand()) / RAND_MAX;
        return min + f * (max - min);
    }

    double engine_consumption_generator(double min, double max)
    {
        double f = double(rand()) / RAND_MAX;
        return min + f * (max - min);
    }

    bool operator<(const Plane& p1, const Plane& p2)
    {
        return p1.fuel() / p1.consumption() < p2.fuel() / p2.consumption();
    }

    bool operator<=(const Plane& p1, const Plane& p2)
    {
        return p1.fuel() / p1.consumption() <= p2.fuel() / p2.consumption();
    }

    bool operator>(const Plane& p1, const Plane& p2)
    {
        return !(p1 <= p2);
    }

    bool operator>=(const Plane& p1, const Plane& p2)
    {
        return !(p1 < p2);
    }

    bool operator==(const Plane& p1, const Plane& p2)
    {
        return p1.consumption_ == p2.consumption_ &&
            p1.fuel_ == p2.fuel_;
    }
    
    bool operator!=(const Plane& p1, const Plane& p2)
    {
        return !(p1 == p2);
    }
    
    std::size_t consume_fuel(priority_queue_adnan::priority_queue<Plane>& planes, double seconds)
    {
        std::size_t count = 0;
        if (planes.empty())
            return count;

        auto plane = planes.begin();

        while (!planes.empty())
        {
            try {
                (*plane).consume_fuel(seconds);
                ++plane;
                if (plane == planes.end())
                    break;
            }
            catch (double)
            {
                count++;
                planes.pop();
                plane = planes.begin();
            }
        }

        return count;
    }

    Arguments::Arguments(double landing_time, double dep_time,
        double dep_prob, double land_prob, double total_time,
        double profit_per_plane, double crash_loss)throw(std::invalid_argument)
    {
        if (landing_time < min_landing_time())
            throw(std::invalid_argument("landing time is less than the minimum."));
        else if(dep_time < min_dep_time())
            throw(std::invalid_argument("departure time is less than the minimum."));
        else if(dep_prob < MIN_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to departure is < 0."));
        else if(land_prob < MIN_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to landing queue is < 0."));
        else if(dep_prob > MAX_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to departure is > 1."));
        else if(land_prob > MAX_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to landing is  > 1."));
        else if(total_time < TOTAL_SIMULATION_TIME)
            throw(std::invalid_argument("Simulation time is less than the minimum."));
        else if(profit_per_plane < 0)
            throw(std::invalid_argument("The Profit cannot be negative."));
        else
        {
            landing_time_ = landing_time;
            dep_time_ = dep_time;
            dep_prob_ = dep_prob;
            land_prob_ = land_prob;
            total_simulation_time_ = total_time;
            profit_ = profit_per_plane;
            crash_loss_ = abs(crash_loss);
        }
    }

    Arguments::Arguments(std::vector<double>args)throw(std::invalid_argument, std::size_t)
    {
        if (args.size() != VALID_ARGUMENTS)
            throw args.size();
        int i = 0;
        if (args[i++] < min_landing_time())
            throw(std::invalid_argument("landing time is less than the minimum."));
        else if (args[i++] < min_dep_time())
            throw(std::invalid_argument("departure time is less than the minimum."));
        else if (args[i] < MIN_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to departure is < 0."));
        else if (args[i++] > MAX_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to departure is > 1."));
        else if (args[i] < MIN_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to landing queue is < 0."));
        else if (args[i++] > MAX_PROBABILITY)
            throw(std::invalid_argument("Probability of planes coming to landing is  > 1."));
        else if (args[i++] < TOTAL_SIMULATION_TIME)
            throw(std::invalid_argument("Simulation time is less than the minimum."));
        else if (args[i] < 0)
            throw(std::invalid_argument("The Profit cannot be negative."));
        else
        {
            i = 0;
            landing_time_ = args[i++];
            dep_time_ = args[i++];
            dep_prob_ = args[i++];
            land_prob_ = args[i++];
            total_simulation_time_ = args[i++];
            profit_= args[i++];
            crash_loss_= args[i];
        }
    }


} // end of namespace