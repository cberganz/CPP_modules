/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:09:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/31 16:15:04 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::Weapon()
{
}

Weapon::~Weapon(void)
{
}

const std::string&	Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(const std::string type)
{
	this->_type = type;
}
