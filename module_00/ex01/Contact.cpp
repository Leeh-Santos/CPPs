/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:07:09 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 21:23:28 by learodri         ###   ########.fr       */
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

