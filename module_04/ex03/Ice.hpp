/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:28 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 20:36:06 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice : public AMateria {

    public:
    	Ice( void );
    	Ice( Ice const &instance );
    	virtual	~Ice( void );
    
    	Ice	&operator=( Ice const &other );

    	Ice		*clone( void ) const;
    	void	use( ICharacter &user );

};

#endif
