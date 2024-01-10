/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:59:40 by learodri          #+#    #+#             */
/*   Updated: 2024/01/10 21:01:49 by learodri         ###   ########.fr       */
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