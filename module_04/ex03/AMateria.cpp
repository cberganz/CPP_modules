/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:13:57 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 13:23:03 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "Unspecified" )
{
	std::cout << "AMateria default constructor called !" << std::endl;
}

AMateria::AMateria( std::string const &type ): _type( type )
{
	std::cout << "AMateria constructor called for " << _type << " !" << std::endl;
}

AMateria::AMateria( AMateria const &instance )
{
	*this = instance;
	std::cout << "AMateria copy constructor called for " << instance.getType() << " !" << std::endl;
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria destructor called for " << this->getType() << " !" << std::endl;
}

AMateria	&AMateria::operator=( AMateria const &other )
{
	(void)other;
	return (*this);
}

std::string const &AMateria::getType( void ) const
{
	return (this->_type);
}

void AMateria::use( ICharacter &user )
{
	(void)user;
}
