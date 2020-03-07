#include<iostream>
#include"stack.h" // Provides stack
#include<fstream> // Provides ifstream/ istream
#include"helping_functions.h" // Provides useful functions from namespace calc_adnan

using stack_adnan::stack; using namespace calc_adnan;
using std::cout; using std::endl; using std::cin;



int main(int argc, char* argv[])
{
	// handle command line arguments
	int right = 2;
	const char usage[] = "Usage: calc input_file.";
	validate_argc(argc, right, usage);

	// opening file for reading
	std::ifstream in;
	in.open(argv[1]);
	if (in.fail())
	{
		std::cerr << "FAILED OPENING: " << argv[1] << endl;
		exit(1);
	}

	double answer;
	while (in)
	{
		evaluate_line(in, answer);
		cout << answer << endl;
	}

}

