#include "Harl.hpp"

int	main( void )
{
	Harl	harl;
	std::string	tests[] = { "DEBUG", "INFO", "WARNING", "ERROR", "OTHER", "END" };

	for (std::string::size_type i = 0 ; tests[i] != "END" ; i++)
		harl.complain(tests[i]);
}
