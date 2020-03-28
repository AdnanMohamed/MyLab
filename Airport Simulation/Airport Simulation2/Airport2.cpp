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


} // end of namespace