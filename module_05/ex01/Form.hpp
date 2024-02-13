# ifndef FORM_HPP
# define FORM_HPP


# include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool		_signed;
	const int	_signGrade;
	const int	_requiredGrade;  
public:
    Form(/* args */);
    ~Form();
    Form( const Form& copy);
	Form& operator=( const Form& copy );
    Form(std::string name, int signgrade, int requiredgrade);

    const std::string getName();
    int     getSignGrade() const;
    int     getRequiredGrade() const;
    bool	beSigned( Bureaucrat &obj);
    bool                isSigned(void) const;
};




#endif