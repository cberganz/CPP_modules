/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:02 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 20:35:06 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {

	public:
		AMateria( std::string const &type );
		AMateria( void );
		AMateria( AMateria const &instance );
		virtual	~AMateria( void );
		
		AMateria	&operator=( AMateria const &other );

		std::string const	&getType( void ) const;
		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter &user ) = 0;

	protected:
		std::string	_type;

};

#endif
