/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:05:44 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:44:39 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

	public:
		std::string _ideas[100];
		Brain( void );
		Brain( Brain const &instance );
		~Brain( void );
		void operator=( Brain const &other );

};

#endif
