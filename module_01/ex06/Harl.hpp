/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:55:32 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/07 18:55:34 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

class	Harl {

public:
	Harl();
	~Harl();
	void			complain( std::string level );
	void			multipleComplain( int begin );
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
