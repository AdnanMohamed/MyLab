// This program simulates a one - runway airport. Airplanes arrives and departures on
// one runway. This program takes the input for a particular simulation then 
// OUTPUTS the following info.:-
//	(1) The number of planes that took off in the simulated time; 
//	(2) the number of planes that landed in the simulated time;
//  (3) the number of planes that crashed because they ran out of fuel before they could land;
//  (4) the average time that a plane spent in the takeoff queue; 
//  (5) the average time that a plane spent in the landing queue.

#include"../Airport Simulation1/Airport.h"
#include"Airport2.h"
#include"../Queue/queue.h"
#include"../Priority Queue/priority_queue.h"
#include<iostream>
#include<ctime> // Provides time()

using std::cout; using std::endl;
using queue_adnan::queue; using namespace airport_adnan;
using priority_queue_adnan::priority_queue; using namespace airport2_adnan;


void airport_simulation(double land_time, double dep_time,
	double dep_probability, double land_probability, double total_time);

int main()
{

	// Simulating the runway with landing time: 22 min, departure time: 14 min,
	// Max waiting time for landing plane before not having fuel: 1 hour
	// planes arriving in the departure queue: 1 plane each 15 minutes,
	// planes arriving in the landing queue: 1 plane each 15 minutes,
	// Total simulation time: 23:59:59

	srand(time(NULL));
	
	airport_simulation(1500, 840, 1 / 900., 1/1500., 86399);
}

void airport_simulation(double land_time, double dep_time,
	double dep_probability, double land_probability, double total_time)
{
	
	queue<unsigned long int>departures;			// This is the queue for depaturing airplanes' timestamps.
	priority_queue<Plane> landing;		  // This priority queue is for landing planes
	runway airport_runway(dep_time, land_time);
	averager departure_waiting;	 // holds the waiting times for the departured planes.
	averager landing_waiting;    // holds the waiting times for the landing planes.
	unsigned long int next_plane_dep;
	std::size_t crashed_planes = 0;   // counts the number of planes crashing because running out of fuel due to long waiting queue
	std::size_t total_crashed_planes = 0;
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
			Plane p(current, give_fuel(), engine_consumption_generator());
			landing.push(p);
		}
		else if (query(dep_probability)) // departure arrivals checking...
		{
			departures.push(current);
		}

		if (!airport_runway.is_busy())
		{

			if (!landing.empty())
			{
				landing_waiting.add_number(current - landing.front().timestamp());
				landing.pop();
				airport_runway.land();
			}
			else if (!departures.empty())
			{
				next_plane_dep = departures.front();
				departures.pop();
				departure_waiting.add_number(current - next_plane_dep);
				airport_runway.departure();
			}

		}


		// declare a passage of a second to the runway
		airport_runway.one_second();
		// fuel consumption ( gallon/ sec ) and record crashed planes due to lack of fuel
		crashed_planes = consume_fuel(landing);
		total_crashed_planes += crashed_planes;
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
	cout << total_crashed_planes << " planes crashed due to long waiting times in the landing queue.\n";
}
	




