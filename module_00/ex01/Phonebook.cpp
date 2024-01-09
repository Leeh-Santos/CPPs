/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:54:51 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/09 16:41:16 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

Phonebook::Phonebook(int nb)
{
    this->i = nb;
    this->flag = nb;
}

Phonebook::~Phonebook()
{
}

void    Phonebook::add(void)
{
    if (i > 7)
    {
        i = 0;
        flag++;
    }

    std::string str;
    
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
    contact[i].dark(str);
    std::cout << std::endl;
    
    std::cin.clear();

    if (contact[i].p_first().empty() || contact[i].p_last().empty() || contact[i].p_nick().empty() || 
        contact[i].p_dark().empty() || contact[i].p_number().empty())
        {
            std::cout << "Empty field detected, try it again meu parceiro." << std::endl;
            std::cout << ">>>>> Press enter to return to menu <<<<<" << std::endl;
            std::cin.get();
            system("clear");
            return ;
        }
    std::cout << "new contact added: " << contact[i].p_first() << std::endl; 
    i++;
    std::cout << ">>>>> Press enter to return to menu <<<<<" << std::endl;
    std::cin.get();
    system("clear");
    std::cin.clear(); 
}

void    Phonebook::search(){

    ilock = i;
    if (flag)
        ilock = 7;
    
    std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

    for (int j = 0; j < ilock ; j++){
        
        std::cout << '|' << std::setw(10) << j + 1 << '|';
        
        if (contact[j].p_first().size() > 10)
            std::cout << std::setw(9) << contact[j].p_first().substr(0,9) + "." << '|'; 
        else    
            std::cout  << std::setw(10) << contact[j].p_first() << '|'; 
            
        if (contact[j].p_last().size() > 10)
            std::cout << std::setw(9) << contact[j].p_last().substr(0,9) + "." << '|'; 
        else    
            std::cout  <<  std::setw(10) << contact[j].p_last() << '|'; 
            
        if (contact[j].p_nick().size() > 10)
            std::cout <<  std::setw(9) << contact[j].p_nick().substr(0,9) + "." << '|' << std::endl; 
        else    
            std::cout  <<  std::setw(10) << contact[j].p_nick() << '|' << std::endl; 
        std::cout << "|-------------------------------------------|" << std::endl;
    }
    
    
}