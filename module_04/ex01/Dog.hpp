/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:56 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:59:18 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	public:
	    Dog( void );
	    Dog( Dog const &instance );
	    ~Dog( void );
	    Dog	&operator=( Dog const &other );
	    virtual void	makeSound( void ) const;
		void			getIdea( int index );
		Brain			*getBrain( void ) const;

	private:
		Brain	*_brain;

};

#endif
