/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:31 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 20:36:12 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter {

	public:
		virtual ~ICharacter() {}
		virtual std::string const &getName( void ) const = 0;
		virtual void equip( AMateria* materia ) = 0;
		virtual void unequip( int idex ) = 0;
		virtual void use( int idex, ICharacter &user ) = 0;

};

#endif
