/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:42:35 by learodri          #+#    #+#             */
/*   Updated: 2024/01/10 19:42:35 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"


Zombie::Zombie(std::string str){
    _name = str;
    std::cout << "Zombie created: " << _name << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie has been killed :" << _name << std::endl;
}


void    Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

