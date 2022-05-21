/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 00:36:12 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
	    WrongCat( void );
	    WrongCat( WrongCat const &instance );
	    ~WrongCat( void );
	    WrongCat	&operator=( WrongCat const &other );
	    void		makeSound( void ) const;

};

#endif
