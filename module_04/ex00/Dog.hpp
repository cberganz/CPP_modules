/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:56 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/21 23:43:25 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

	public:
	    Dog( void );
	    Dog( Dog const &instance );
	    ~Dog( void );
	    Dog	&operator=( Dog const &other );
	    virtual void makeSound( void ) const;

};

#endif
