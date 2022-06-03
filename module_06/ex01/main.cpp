/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:27:30 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/04 00:21:33 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <stdint.h>

struct Data
{
	int i;
	std::string s;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
	//return ((uintptr_t)(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
	//return ((Data*)(raw));
}

int main()
{
    Data *data = new Data;
    data->i = 42;
    data->s = "42";
    std::cout << "Data ptr : " << data << std::endl;
    uintptr_t ptr = serialize(data);
    std::cout << "Casted uintptr_t : " << ptr << std::endl;
    std::cout << "Recasted to Data* : " << deserialize(ptr) << std::endl;

    delete data;

    return (0);
}