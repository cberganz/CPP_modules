/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:19 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/03 23:45:32 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERT_HPP
# define CONVERT_HPP

# define PRECISION 1

# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cstdlib>

class Convert {

    public:
    	Convert() : m_value("error"), m_invalidCharFlag(false), m_invalidIntFlag(false), m_invalidFloatFlag(false) {};
    	Convert(std::string const &value);
    	~Convert(){};

    	std::string const	&getValue() const;

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

		bool				m_invalidCharFlag;
		bool				m_invalidIntFlag;
		bool				m_invalidFloatFlag;

		void	handleChar();
		void	handleInt();
		void	handleFloat();
		void	handleDouble();

};

#endif
