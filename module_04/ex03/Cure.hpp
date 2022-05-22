/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 20:35:57 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria {

    public:
    	Cure( void );
    	Cure( Cure const &instance );
    	virtual	~Cure( void );
    
    	Cure	&operator=( Cure const &other );

    	Cure*   clone( void ) const;
    	void 	use( ICharacter &user );

};

#endif