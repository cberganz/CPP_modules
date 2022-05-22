/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:35 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 20:36:18 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {

	public:
	    virtual ~IMateriaSource() {}
	    virtual void learnMateria( AMateria* ) = 0;
	    virtual AMateria* createMateria( std::string const &type ) = 0;

};

#endif
