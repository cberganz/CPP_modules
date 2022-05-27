/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:19 by charles           #+#    #+#             */
/*   Updated: 2022/05/26 15:38:44 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>

class Scalar {

    public:
    	Scalar(std::string const &value) : value(value){};
    	~Scalar(){};
    	std::string const &getValue() const;
    	char toChar() const;
    	int toInt() const;
    	float toFloat() const;
    	double toDouble() const;

    	class ImpossibleException : public std::exception
    	{
    		const char *what() const throw()
    		{
    			return "impossible";
    		}
    	};
    	class NonDisplayableException : public std::exception
    	{
    		const char *what() const throw()
    		{
    			return "Non displayable";
    		}
    	};

    private:
    	const std::string value;
    	Scalar() : value("error"){};

};

std::ostream &operator<<(std::ostream &os, Scalar const &scalar);

#endif
