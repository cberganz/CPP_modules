/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:29:03 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/06 23:08:33 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <iomanip>
# include <cstring>

template <typename T>
class Array {

	public:
		Array() : m_array(0), m_size(0) {}
		~Array() { delete[] this->m_array; }

		Array(const Array<T> &src) : m_array(0), m_size(0) {
			if (this != &src)
				*this = src;
		}

		Array(unsigned int size) : m_array(new T[size]), m_size(size) {
			std::memset(m_array, 0, sizeof(T) * m_size);
		}

		Array	&operator=(const Array<T> &rhs)	{
			if (this == &rhs)
				return (*this);
			if (not this->m_array)
				delete[] this->m_array;
			this->m_size = rhs.getSize();
			if (rhs.getSize())
				this->m_array = new T[rhs.getSize()];
			for (std::size_t i = 0 ; i < rhs.getSize() ; i++)
				this->m_array[i] = rhs.m_array[i];
			return (*this);
		}

		T	&operator[](std::size_t index) const {
			if (index < 0 or index >= this->m_size)
				throw OutOfRangeException();
			return (this->m_array[index]);
		}

		std::size_t	getSize() const { return (this->m_size); }

		class OutOfRangeException : public std::exception {
			public:
        	    virtual const char* what() const throw()
        	    {
        		    return ("Index does not exist.");
        		}
		};

	private:
		T			*m_array;
		std::size_t	m_size;

};

#endif
