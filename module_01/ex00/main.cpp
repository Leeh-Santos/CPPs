/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:56:12 by learodri          #+#    #+#             */
/*   Updated: 2024/04/16 19:41:57 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie teste(){
    Zombie b("leandooo");
    return b;
}

int main()
{
    randomChump("thomas turbano");

    Zombie z = teste();
    z.announce();

    Zombie *x = newZombie("Leandro");
    delete (x);
    
}