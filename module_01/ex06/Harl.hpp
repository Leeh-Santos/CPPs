#ifndef HARL_H
# define HARL_H

# include <iostream> 
# include <string.h>

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
    void  (Harl::*ptr[4])();

public:
    Harl(void);
    ~Harl(void);
    void    complain(std::string level);

};

#endif
