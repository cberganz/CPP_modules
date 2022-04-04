#include "Harl.hpp"

int	main( int argc, char *argv[] )
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Error: invalid arguments !\n";
		return (0);
	}
	harl.filteredComplain(argv[1]);
	return (0);
}
