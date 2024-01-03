/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:07:09 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 16:40:06 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"


void    Contact::first(std::string name){
    this->_first = name;
}

void    Contact::last(std::string name){
    this->_last = name;
}

void    Contact::nick(std::string name){
    this->_nick = name;
}

void    Contact::dark(std::string name){
    this->_dark = name;
}

void    Contact::number(int nb){
    this->_number = nb;
}

int    Contact::spit(void){
    return this->_number;
}