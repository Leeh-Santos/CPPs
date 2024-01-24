#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:

    int                 _fixedPoint;
    static const int    _bits = 8;

public:

    Fixed(void);
    Fixed( const int& value );
    Fixed(const float& value);
    Fixed(Fixed const &copy);
    ~Fixed(void);

    Fixed   &operator=(Fixed const &obj);
    
    bool    operator>(Fixed const &obj) const;
    bool    operator>=(Fixed const &obj) const;
    bool    operator<(Fixed const &obj) const;
    bool    operator<=(Fixed const &obj) const;
    bool    operator==(Fixed const &obj) const;
    bool    operator!=(Fixed const &obj) const;

    Fixed   operator+(Fixed const &obj);
    Fixed   operator-(Fixed const &obj);
    Fixed   operator*(Fixed const &obj);
    Fixed   operator/(Fixed const &obj);
    
    Fixed   &operator++(void);  // ++i;
    Fixed   operator++(int);    // i++;
    Fixed   &operator--(void);  // --i;
    Fixed   operator--(int);    // i--;
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    float   toFloat(void) const;
    int     toInt(void) const;


    static Fixed        &min(Fixed &obj1, Fixed &obj2);
    static const Fixed  &min(Fixed const &obj1, Fixed const &obj2);
    static Fixed        &max(Fixed &obj1, Fixed &obj2);
    static const Fixed  &max(Fixed const &obj1, Fixed const &obj2);
};

std::ostream    &operator<<(std::ostream &os, Fixed const &obj);

#endif
