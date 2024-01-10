/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:39:21 by learodri          #+#    #+#             */
/*   Updated: 2024/01/10 19:42:31 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
#include <string>

class Zombie
{
    private:
    std::string _name;
    
    public:
        Zombie(std::string str);
        ~Zombie();
        void    announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif

