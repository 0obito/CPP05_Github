#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
        const std::string& _target;
    public:
        RobotomyRequestForm();
        (const std::string& target);
        (const & other);
        & operator=(const & other);
        ~();

        void doItYourself (const Bureaucrat& executor) const;
};

#endif /*ROBOTOMYREQUESTFORM_HPP*/
