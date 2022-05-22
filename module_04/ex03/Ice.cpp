/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 14:58:49 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "Constructor called for ice !" << std::endl;
}

Ice::Ice( Ice const &instance ) : AMateria("ice")
{
	*this = instance;
	std::cout << "Copy constructor called for ice !" << std::endl;
}

Ice::~Ice( void )
{
	std::cout << "Destructor called for ice !" << std::endl;
}

Ice	&Ice::operator=( Ice const &other )
{
	(void)other;
	return ( *this );
}

Ice* Ice::clone( void ) const
{
	return ( new Ice( *this ) );
}

void 	Ice::use( ICharacter &user )
{
	std::cout << "* shoots an ice bolt at " << user.getName() << " *" << std::endl;
}
