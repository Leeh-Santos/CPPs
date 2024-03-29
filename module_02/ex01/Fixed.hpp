#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed{
	private:
		int					_fixedPoint;
		static const int	_bits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed& copy );
		Fixed& operator=( const Fixed& copy );
		~Fixed( void );

		Fixed( const int& value );
		Fixed( const float& value );

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed& obj );

#endif