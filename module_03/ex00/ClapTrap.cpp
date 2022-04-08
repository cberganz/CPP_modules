/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:41:09 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/08 02:39:46 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "defaultName";
	this->_life = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
	this->_name = name;
	this->_life = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_energy = other.getEnergy();
		this->_life = other.getLife();
		this->_damage = other.getDamage();
	}
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " tried to attack but he is out of energy" << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_damage
				<< " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_life == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	if (amount > this->_life)
		this->_life = 0;
	else
		this->_life -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
				<< " points of damage !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " tried to repair but he is out of energy" << std::endl;
		return ;
	}
	this->_energy--;
	if (this->_life + amount > 10)
		this->_life = 10;
	else
		this->_life += amount;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount
				<< " points of life !" << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getDamage(void) const
{
	return (this->_damage);
}

unsigned int	ClapTrap::getLife(void) const
{
	return (this->_life);
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}
