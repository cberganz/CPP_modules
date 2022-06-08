/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:16:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/08 13:27:09 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

 class Awesome
 {
 	public:
 		Awesome( void ) : _n( 42 ) { return; }
 		int get( void ) const { return this->_n; }
 	private:
 		int _n;
 };
 std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

 template< typename T >
 void print( T const & x ) { std::cout << x << std::endl; return; }

 int main() {
 	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
 	Awesome tab2[5];
 	::iter( tab, 5, print );
 	::iter( tab2, 5, print );

 	return 0;
 }

//template <typename T>
//void	tests(int size, T *elements)
//{
//	T *Arr = elements;
//	::iter(Arr, std::size_t(size), print);
//	std::cout << std::endl;
//}
//
//int	main()
//{
//	int size = 9;
//	int Arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	tests<int>(size, Arr);
//
//	return (0);
//}