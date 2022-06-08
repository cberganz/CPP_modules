/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:24:48 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/07 00:42:34 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <algorithm>

class ElementNotFoundException : public std::exception {

	public:
		virtual const char *what() const throw()
		{
			return ("Element not found.");
		}

};

template <typename T>
void	easyFind(const T &cont, unsigned int elem)
{
	if (std::find(cont.begin(), cont.end(), elem) == cont.end())
		throw ElementNotFoundException();
}

#endif