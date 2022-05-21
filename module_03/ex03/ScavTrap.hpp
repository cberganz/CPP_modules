/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:42:16 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/08 02:14:26 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class	ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &other);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap const &other);

		void		attack(std::string const &target);
		void		guardGate() const;

};

std::ostream &operator<<(std::ostream &outStream, ScavTrap const &scav);

#endif
