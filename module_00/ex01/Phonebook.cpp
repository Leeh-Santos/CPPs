/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:54:51 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 16:39:32 by learodri@st      ###   ########.fr       */
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

    std::cout << contact[1].spit() << std::endl;
    /*std::string str;
    
    system("clear");
    std::cout << "provide first name:  " << std::endl;
    getline(std::cin, str);
    contact[i].first(str);
    std::cout << '\n';
    
    std::cout << "provide last name:  " << std::endl;
    getline(std::cin, str);
    contact[i].last(str);
    std::cout << '\n';
    
    std::cout << "provide  nickname:  " << std::endl;
    getline(std::cin, str);
    contact[i].nick(str);
    std::cout << '\n';

    std::cout << "provide  number:  " << std::endl;
    getline(std::cin, str);
    int nb = stoi(str);
    contact[i].number(nb);
    std::cout << '\n';

    std::cout << "provide  secret:  " << std::endl;
    getline(std::cin, str);
    int nb = stoi(str);
    contact[i].number(nb);
    std::cout << '\n';*/
    
}