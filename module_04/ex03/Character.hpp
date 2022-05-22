/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:11 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 20:35:46 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define MAX_ITENS 4

class Character : public ICharacter {

	public:
		Character( std::string name );
		Character( void );
		Character( Character const &instance );
		virtual	~Character( void );
	
		Character	&operator=( Character const &other );
	
		std::string const	&getName( void ) const;
		void 				setName( std::string name );
		void				equip( AMateria* materia );
		void				unequip( int index );
		void				use( int idex, ICharacter &user );

	private:
		std::string	_name;
		AMateria	*_inventory[MAX_ITENS];
		void		_fillInventory( AMateria *materia, int idex );
		void 		_initInventory( void );

};

#endif
