/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:59:40 by learodri          #+#    #+#             */
/*   Updated: 2024/02/05 19:42:54 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Zombie.hpp"


Zombie::Zombie(void){
   std::cout << "default constructor called" << std::endl;
}

Zombie::~Zombie(){
    std::cout << "default destructor called" << std::endl;
}

void    Zombie::setName(std::string name){
    _name = name;
}

void    Zombie::announce(void){
    std::cout << _name << " - has been created : BraiiiiiiinnnzzzZ..." << std::endl;
}