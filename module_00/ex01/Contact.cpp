/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:07:09 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/04 14:47:57 by learodri@st      ###   ########.fr       */
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

void    Contact::number(std::string name){
    this->_number = name;
}

std::string  Contact::p_first(void){
    return this->_first;
}

std::string  Contact::p_last(void){
    return this->_last;
}

std::string  Contact::p_nick(void){
    return this->_nick;
}

std::string  Contact::p_dark(void){
    return this->_dark;
}

std::string  Contact::p_number(void){
    return this->_number;
}