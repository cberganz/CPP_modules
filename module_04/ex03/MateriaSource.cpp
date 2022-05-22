/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:44 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 22:49:17 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource( void )
{
	this->_initBook();
	std::cout << "Constructor called for MateriaSource !" << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const &instance )
{
	this->_initBook();
	*this = instance;
	std::cout << "Copy constructor called for MateriaSource !" << std::endl;
}

MateriaSource::~MateriaSource( void )
{
	for( int i = 0 ; i < MAX_LEARN ; i++)
		if( this->_learningBook[i] )
			delete this->_learningBook[i];
	std::cout << "Destructor called for MateriaSource !" << std::endl;
}

MateriaSource &MateriaSource::operator=( MateriaSource const &other )
{
	for( int i = 0 ; i < MAX_LEARN ; i++ )
	{
		if (other._learningBook[i])
			this->_learningBook[i] = other._learningBook[i]->clone();
	}
	return ( *this );
}

void MateriaSource::_initBook( void )
{
	for( int i = 0 ; i < MAX_LEARN ; i++ )
		this->_learningBook[i] = NULL;
}

void MateriaSource::_storeMateria( AMateria *materia, int index ) 
{
	this->_learningBook[index] = materia;
	std::cout << "Materia " << materia->getType() << " learned !" << std::endl;
}

void MateriaSource::learnMateria( AMateria *materia ) 
{
	for( int i = 0 ; i < MAX_LEARN ; i++ )
		if ( not this->_learningBook[i] )
			return ( _storeMateria( materia, i ) );
	std::cout << "Already learned too much materia, no more space.." << std::endl;
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for( int i = 0 ; i < MAX_LEARN && this->_learningBook[i] ; i++ )
		if ( this->_learningBook[i]->getType() == type )
			return ( this->_learningBook[i]->clone() );
	std::cout << "Unknown " << type <<  " !" << std::endl;
	return ( NULL );
}

AMateria const	*MateriaSource::getLearningBook( void ) const
{
	return ( *this->_learningBook );
}
