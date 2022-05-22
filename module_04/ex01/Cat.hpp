/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:59:47 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	public:
	    Cat( void );
	    Cat( Cat const &instance );
	    ~Cat( void );
	    Cat	&operator=( Cat const &other );
	    virtual void	makeSound( void ) const;
		void			getIdea( int index );
		Brain			*getBrain( void ) const;

	private:
		Brain	*_brain;

};

#endif
