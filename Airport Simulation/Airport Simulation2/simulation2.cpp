// This program simulates a one - runway airport. Airplanes arrives and departures on
// one runway. This program takes the input for a particular simulation from a text file.
// input file format:
//--------------------------
//	 landing time: SECONDS
//	 departure time: SECONDS
//	 departure probability: DECIMAL
//	 landing probability: DECIMAL
//	 total simulation time: SECONDS
//	 landing / departure profit: (in thousand $)
//	 plane crash loss: (in thousands)
//  -------------------------
//	then OUTPUTS the following info.:-
//	(1) The number of planes that took off in the simulated time; 
//	(2) the number of planes that landed in the simulated time;
//  (3) the number of planes that crashed because they ran out of fuel before they could land;
//  (4) the average time that a plane spent in the takeoff queue; 
//  (5) the average time that a plane spent in the landing queue.
//	(6) profit or loss generated.

#include"../Airport Simulation1/Airport.h"
#include"Airport2.h"
#include"../Queue/queue.h"
#include"../Priority Queue/priority_queue.h"
#include<iostream>
#include<fstream> // Provides istream
#include<ctime> // Provides time()
#include<vector>

using std::cout; using std::endl;
using queue_adnan::queue; using namespace airport_adnan;
using priority_queue_adnan::priority_queue; using namespace airport2_adnan;

double total_profit_loss(std::size_t crashed_planes, unsigned int landed_departured_planes,
	double crash_cost, double landing_dap_rate);
	// Precondition: crash_cost, landing_dep_rate is $ per plane. (cost and profit in positive)
	// Postcondition: ruturned value is the total profit or loss from the given arguments.
	// (Negative return means loss, positive means amount of profit in $)

void validate_commands(int argc, int right, const char usage[]);

void read_data(char file_name[], Arguments& arguments);

void airport_simulation(const Arguments& args);


int main(int argc, char* argv[])
{

	srand(time(NULL));
	validate_commands(argc, 2, "Usage: program_name file_name.txt");
	Arguments args; // The arguments for the simulation.
	
	// read the simulation data from the given file in the command-line arguments
	// then assign the values to args.
	read_data(argv[1], args);
	
	// start simulation.
	airport_simulation(args);
}

void airport_simulation(const Arguments& args)
{
	
	queue<unsigned long int>departures;			// This is the queue for depaturing airplanes' timestamps.
	priority_queue<Plane> landing;		  // This priority queue is for landing planes
	double land_time = args.get_landing_time(), dep_time = args.get_dep_time();
	double land_probability = args.get_land_probability(), dep_probability = args.get_dep_probability();
	double total_time = args.get_total_time();
	runway airport_runway(args.get_dep_time(), args.get_landing_time());
	averager departure_waiting;	 // holds the waiting times for the departured planes.
	averager landing_waiting;    // holds the waiting times for the landing planes.
	unsigned long int next_plane_dep;
	std::size_t crashed_planes = 0;   // counts the number of planes crashing because running out of fuel due to long waiting queue
	std::size_t total_crashed_planes = 0;
	double profit = 0; // Profit generated from this simulation in thousands $.
	
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
				// Process the landing for this plane only if the plane
				// has sufficient fuel to make the landing.
				if (landing.front().fuel() - (land_time * landing.front().consumption()) > 0)
				{
					landing_waiting.add_number(current - landing.front().timestamp());
					airport_runway.land();
				}
				else
				{
					total_crashed_planes++;
				}
				landing.pop();
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

	// calculate profit.
	profit = total_profit_loss(total_crashed_planes, landing_waiting.how_many_numbers() + departure_waiting.how_many_numbers(),
		args.get_crash_loss(), args.get_profit());
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
	cout << total_crashed_planes << " planes crashed from lacking fuel due to long waiting queues.\n";
	if (profit >= 0)
		cout << "Total Profit: $" << profit <<" Thousand"<< endl;
	else
		cout << "Total Loss: -$" << abs(profit)<<" Thousand" << endl;
}
	

void validate_commands(int argc, int right, const char usage[])
{
	try {
		if (argc != right)
			throw argc;
	}
	catch (int e)
	{
		cout << e << " arguments given, while " << right << " are expected.\n";
		cout << usage << endl;
		cout << "In visual studio only give the input_file.txt as command line argument.\n";
		exit(1);
	}

}

void read_data(char file_name[], Arguments& arguments)
{
	try {
		std::ifstream in;
		in.open(file_name);
		if (in.fail())
		{
			cout << "Failed opening \"" << file_name << "\"" << endl;
			exit(1);
		}

		// read the input data
		std::vector<double> data;
		double next;
		char ch;
		in >> ch;
		while (!in.eof())
		{
			if (ch == ':')
			{
				in >> next;
				data.push_back(next);
			}
			in >> ch;
		}
		in.close();
		Arguments args(data);
		arguments = args;
	}
	catch (std::size_t s)
	{
		cout << Arguments().number_of_args() << " should be the number of arguments.\n"
			<< "The file has: " << s << endl;
		exit(1);
	}
	catch (const std::invalid_argument & e)
	{
		cout << "Error: " << e.what() << endl;
		cout << "Exiting Program." << endl;
		exit(1);
	}
}

double total_profit_loss(std::size_t crashed_planes, unsigned int landed_departured_planes,
	double crash_cost, double landing_dap_rate)
{
	return landed_departured_planes * landing_dap_rate - crashed_planes * abs(crash_cost);
}


