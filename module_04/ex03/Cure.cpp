/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:15 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 20:32:50 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" )
{
	std::cout << "Constructor called for cure !" << std::endl;
}

Cure::Cure( Cure const &instance ) : AMateria( "cure" )
{
	*this = instance;
	std::cout << "Copy constructor called for cure !" << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "Destructor called for cure !" << std::endl;
}

Cure	&Cure::operator=( Cure const &other )
{
	( void )other;
	return ( *this ) ;
}

Cure	*Cure::clone( void ) const
{
	return ( new Cure( *this ) );
}

void 	Cure::use( ICharacter &user )
{
	std::cout << "* heals " << user.getName() << "’s wounds *" << std::endl;
}
