/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:54:51 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 21:50:24 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

Phonebook::Phonebook(int nb)
{
    this->i = nb;
}

Phonebook::~Phonebook()
{
}

void    Phonebook::add(void)
{

    std::string str;
    
    system("clear");
    std::cout << "provide first name:  " << std::endl;
    getline(std::cin, str);
    contact[i].first(str);
    std::cout << std::endl;
    
    std::cout << "provide last name:  " << std::endl;
    getline(std::cin, str);
    contact[i].last(str);
    std::cout << std::endl;
    
    std::cout << "provide  nickname:  " << std::endl;
    getline(std::cin, str);
    contact[i].nick(str);
    std::cout << std::endl;

    std::cout << "provide  number:  " << std::endl;
    getline(std::cin, str);
    contact[i].number(str);
    std::cout << std::endl;

    std::cout << "provide  secret:  " << std::endl;
    getline(std::cin, str);
    contact[i].number(str);
    std::cout << std::endl;
    i++;
   
    std::cin.clear();
}