/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:42:16 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 19:53:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &other);
		~FragTrap();

		FragTrap &operator=(FragTrap const &other);

		void		attack(std::string const &target);
		void		highFivesGuys() const;

};

std::ostream &operator<<(std::ostream &outStream, FragTrap const &frag);

#endif
