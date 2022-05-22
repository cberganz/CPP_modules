/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:07 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 14:56:30 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string name ) : _name( name )
{
	this->_initInventory();
	std::cout << "Character constructor called for " << name << " !" << std::endl;
}

Character::Character( void ) : _name( "default" )
{
	this->_initInventory();
	std::cout << "Character default constructor called !" << std::endl;
}

Character::Character( Character const &instance )
{
	this->_initInventory();
	*this = instance;
	std::cout << "Character copy constructor called for " << instance.getName() << " !" << std::endl;
}

Character::~Character( void )
{
	for( int i = 0 ; i < MAX_ITENS ; i++ )
		if( this->_inventory[i] )
			delete this->_inventory[i];
	std::cout << "Character destructor called for " << this->getName() << " !" << std::endl;
}

void Character::_initInventory( void )
{
	for( int i = 0 ; i < MAX_ITENS ; i++ )
		this->_inventory[i] = NULL;
}

Character	&Character::operator=( Character const &other )
{
	this->_name = other.getName();
	for ( int i = 0 ; i < MAX_ITENS ; i++ )
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return ( *this );
}

std::string const &Character::getName( void ) const
{
	return ( this->_name );
}

void Character::setName( std::string name )
{
	this->_name = name;
}

void Character::_fillInventory( AMateria *materia, int index )
{
	for( int j = 0 ; j < MAX_ITENS ; j++ )
	{
		if( this->_inventory[j] == materia )
		{
			std::cout << this->_name << " does not need more " << materia->getType() << std::endl;
			return ;
		}
	}
	this->_inventory[index] = materia;
	std::cout << this->getName() << " has taken a " << this->_inventory[index]->getType() << " at his inventory slot No " << index << std::endl;
}

void Character::equip( AMateria *materia )
{
	for( int i = 0 ; i < MAX_ITENS && materia != NULL ; i++ )
		if( not this->_inventory[i] )
			return( this->_fillInventory( materia, i ) );
}

void Character::unequip( int idex )
{
	if ( this->_inventory[idex] )
	{
		std::cout << this->getName() << " just throw his inventory slot No " << idex << " (" << this->_inventory[idex]->getType() << ") to the floor !" << std::endl;
		this->_inventory[idex] = NULL;
	}
}

void Character::use( int idex, ICharacter &user )
{
	if ( this->_inventory[idex] )
		this->_inventory[idex]->use( user );
}
