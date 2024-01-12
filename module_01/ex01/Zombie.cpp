/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:59:40 by learodri          #+#    #+#             */
/*   Updated: 2024/01/12 11:19:17 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Zombie.hpp"


Zombie::Zombie(void){
   
}

Zombie::~Zombie(){
    
}

void    Zombie::setName(std::string name){
    _name = name;
}

void    Zombie::announce(void){
    std::cout << _name << " - has been created" << std::endl;
}