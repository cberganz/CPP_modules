/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/21 23:42:28 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

	public:
	    Cat( void );
	    Cat( Cat const &instance );
	    ~Cat( void );
	    Cat	&operator=( Cat const &other );
	    virtual void makeSound( void ) const;

};

#endif
