#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

class	Harl {

public:
	Harl();
	~Harl();
	void			complain( std::string level );
	void			filteredComplain( std::string filter );

private:
	void			debug();
	void			info();
	void			warning();
	void			error();
	void			other();
	typedef void	(Harl::*func)(void);
	typedef struct	s_funcPtr
	{
		std::string	name;
		func		ptr;
	} t_funcPtr;
};

#endif
