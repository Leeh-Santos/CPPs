#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <string.h>


class Fixed
{
private:
    int   _fixedPoint;
    static const int _bits = 8;

public:
    Fixed();
    Fixed(const Fixed &obj);
    ~Fixed();

    void operator=(const Fixed &obj);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif
