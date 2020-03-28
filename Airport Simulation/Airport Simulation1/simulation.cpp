// This program simulates a one-runway airport. Airplanes arrives and departures on
// one runway. This program takes the input for a particular simulation then represents
// the following info.:-
//	(1) The number of planes that took off in the simulated time; 
//	(2) the number of planes that landed in the simulated time;
//  (3) the number of planes that crashed because they ran out of fuel before they could land;
//  (4) the average time that a plane spent in the takeoff queue; 
//  (5) the average time that a plane spent in the landing queue.

#include"Airport.h"
#include"../Queue/queue.h"
#include<iostream>

using std::cout; using std::endl;
using queue_adnan::queue; using namespace airport_adnan;


void airport_simulation(unsigned long int land_time, unsigned long int dep_time, unsigned long int max_time,
	double dep_possibility, double land_possibility, unsigned long int total_time);

int main()
{

	// Simulating the runway with landing time: 22 min, departure time: 14 min,
	// Max waiting time for landing plane before not having fuel: 1 hour
	// planes arriving in the departure queue: 1 plane each 10 minutes,
	// planes arriving in the landing queue: 1 plane each 20 minutes,
	// Total simulation time: 10 hours.

	airport_simulation(1320, 840, 3600, 1 / 600., 1 / 1200., 36000);
}

void airport_simulation(unsigned long int land_time, unsigned long int dep_time,unsigned long int max_time,
	double dep_probability, double land_probability, unsigned long int total_time)
{

	queue<unsigned long int>departures;			// This is the queue for depaturing airplanes' timestamps.
	queue<unsigned long int> landing;			// This priority queue is for landing airplanes' timestamps
	runway airport_runway(dep_time, land_time);
	averager departure_waiting;	 // holds the waiting times for the departured planes.
	averager landing_waiting;    // holds the waiting times for the landing planes.
	unsigned long int next_plane; // takes the next plane which will dep. OR land
	std::size_t crashed_planes = 0;   // counts the number of planes crashing because running out of fuel due to long waiting queue
	
	// Display initial info.
	cout << "Each plane takes "; display_time(land_time); cout << " to land,\n";
	display_time(dep_time); cout << " to departure.\n"
		<< "The total time of simulation: "; display_time(total_time); cout << endl;
	cout << "------------------\n";
	cout << "------------------\n\n";

	for (unsigned long int current = 0; current < total_time; ++current)
	{
		// Check for landing arrivals
		if (query(land_probability))
		{
			landing.push(current);
		}
		else if (query(dep_probability)) // departure arrivals checking...
		{
			departures.push(current);
		}

		if (!airport_runway.is_busy())
		{
			if (!landing.empty())
			{

				next_plane = landing.front();
				// while the planes are not having sufficient fuel
				// remove them from the queue and count how many are they.
				while (current - next_plane > max_time)
				{
					crashed_planes++;
					landing.pop();
					if (!landing.empty())
						next_plane = landing.front();
					else
						break;
				}

				// check whether the landing queue is still not empty
				// because it may be the case that all planes ran-out-of fuel
				if (!landing.empty())
				{
					landing.pop();
					landing_waiting.add_number(current - next_plane);
					airport_runway.land();
				}

			}
			else if (!departures.empty())
			{
				next_plane = departures.front();
				departures.pop();
				departure_waiting.add_number(current - next_plane);
				airport_runway.departure();
			}
		}
		// declare a passage of a second to the runway
		airport_runway.one_second();
	}
	
	// Display the results:
	cout << "Planes that departured: " << departure_waiting.how_many_numbers() << endl;
	cout << "Planes that landed: " << landing_waiting.how_many_numbers() << endl;
	if (departure_waiting.how_many_numbers() != 0)
	{
		cout << "Average waiting time in depature line: "; display_time(departure_waiting.average()); cout << endl;
	}
	if (landing_waiting.how_many_numbers() != 0)
	{
		cout << "Average waiting time in landing line: "; display_time(landing_waiting.average()); cout << endl;
	}
	cout << crashed_planes << " planes crashed due to long waiting times in the landing queue.\n";
}

