/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:08:02 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 19:55:13 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("defaultName", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called for " << this->getName() << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << this->getName() << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->getName() << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
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

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->getName() << " wants his victory high five :)" << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	if (this->_life <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is already dead and cannot attack. RIP." << std::endl;
		return ;
	}
	if (this->getEnergy() == 0)
	{
		std::cout << "FragTrap " << this->getName() << " tried to attack but he is out of energy" << std::endl;
		return ;
	}
	if (this->getDamage() == 0)
	{
		std::cout << "FragTrap " << this->getName() << " tried to attack but has no damage point" << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "FragTrap " << this->getName() << " attacks " << target
				<< ", causing " << this->getDamage()
				<< " points of damage !" << std::endl;
}

std::ostream &operator<<(std::ostream &outStream, FragTrap const &frag)
{
	std::cout << "Name: " << frag.getName() << " | "
				<< "Life points: " << frag.getLife() << " | "
				<< "Energy points: " << frag.getEnergy() << " | "
				<< "Damage: " << frag.getDamage();
	return outStream;
}
