/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:13:06 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/06 23:03:38 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

template <typename T>
void print(const Array<T> &arr)
{
	for (std::size_t i = 0 ; i < arr.getSize() ; i++) {
		try {
			std::cout << arr[i];
		}
		catch(const std::exception& e) {
			throw;
		}
		arr.getSize() - 1 > i ? std::cout << " | " : std::cout << std::endl;
	}
}

template <typename T>
void	unit_test(int size, T arg, T arg2)
{
	std::cout << "\nBASIC CONSTRUCTION TESTS :" << std::endl;
	Array<T> array(size);
	std::cout << "Array of size : " << array.getSize() << std::endl;
	for (int i = 0 ; i < size ; i++)
		array[i] = arg;
	std::cout << "Content of the array : " << std::endl;
	print(array);

	std::cout << "\n'[]' OPERATOR TESTS :" << std::endl;
	std::cout << "Trying to change the value one element : " << std::endl;
	array[size - 1] = arg2;
	std::cout << array[size - 1] << std::endl;
	std::cout << "Trying access values out of range (-1 and max + 1) : " << std::endl;
	try
	{
		std::cout << array[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << array[size] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nASSIGNEMENT OPERATOR TESTS :" << std::endl;
	std::cout << "Creating a copy of the array and printing its elements : " << std::endl;
	Array<T> arrayCpy = array;
	std::cout << "Array of size : " << arrayCpy.getSize() << std::endl;
	try
	{
		print(arrayCpy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nCOPY CONSTRUCTOR TESTS :" << std::endl;
	std::cout << "Instanciating a new array based on the previous : " << std::endl;
	Array<T> arrayCpy2(arrayCpy);
	std::cout << "Array of size : " << arrayCpy2.getSize() << std::endl;
	try
	{
		print(arrayCpy2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nDEFAULT CONSTRUCTOR TESTS :" << std::endl;
	Array<T> emptyArray;
	std::cout << "Size of the array : " << emptyArray.getSize() << std::endl;
	std::cout << "Trying to acces element index 0 : " << std::endl;
	try
	{
		std::cout << emptyArray[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
}

int	main()
{
	unit_test<int>(10000, 18, 200);
	//unit_test<std::string>(20, "There you are !", "Hey !");
	return (0);
}
