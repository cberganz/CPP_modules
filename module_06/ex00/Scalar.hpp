/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:19 by charles           #+#    #+#             */
/*   Updated: 2022/06/03 04:17:20 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <cctype>
# include <cmath>
# include <limits>

class Scalar {

    public:
    	Scalar() : m_value("error"){};
    	Scalar(std::string const &value);
    	~Scalar(){};

    	std::string const	&getValue() const;
    	char				toChar() const;
    	int					toInt() const;
    	float				toFloat() const;
    	double				toDouble() const;

    	class ImpossibleException : public std::exception
    	{
			public:
    			const char *what() const throw()
    			{
    				return ("impossible");
    			}
    	};

    	class NonDisplayableException : public std::exception
    	{
			public:
 				const char *what() const throw()
   	 			{
   		 			return ("Non displayable");
    			}
    	};

    private:
    	const std::string	m_value;
		char				m_asChar;
		int					m_asInt;
		float				m_asFloat;
		double				m_asDouble;

		void	handleChar();
		void	handleInt();
		void	handleFloat();
		void	handleDouble();

};

std::ostream &operator<<(std::ostream &os, Scalar const &scalar);

#endif
