/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:47 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 22:49:18 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MAX_LEARN 4

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const &instance );
		~MateriaSource( void );

		MateriaSource &operator=( MateriaSource const &other );

		void 			learnMateria( AMateria* ) ;
		AMateria 		*createMateria( std::string const &type );
		AMateria const	*getLearningBook( void ) const;

	private:
		AMateria	*_learningBook[MAX_LEARN];
		void		_storeMateria( AMateria *materia, int index );
		void		_initBook( void );

};

#endif
