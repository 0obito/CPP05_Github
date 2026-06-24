#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw GradeTooLowException();
    }
    if (gradeToSign < 1   || gradeToExec < 1) {
        throw GradeTooHighException();
    }
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExec() const {
    return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& bur) {
    if (bur.getGrade() <= _gradeToSign) {
        _isSigned = true;
    }
    else {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& s, const Form& f) {
    s << f.getName() << ", required grade to sign " << f.getGradeToSign() << ", required grade to execute " << f.getGradeToExec();
    if (f.getIsSigned()) {
        s << ", is signed";
    }
    else {
        s << ", is not signed";
    }
    return s;
}
