#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw GradeTooLowException();
    }
    if (gradeToSign < 1   || gradeToExec < 1) {
        throw GradeTooHighException();
    }
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExec() const {
    return _gradeToExec;
}

void AForm::beSigned(const Bureaucrat& bur) {
    if (bur.getGrade() <= _gradeToSign) {
        _isSigned = true;
    }
    else {
        throw GradeTooLowException();
    }
}

void AForm::execute(const Bureaucrat& executor) const {
    if (_isSigned == false) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExec) {
        throw GradeTooLowException();
    }
    doItYourself(executor);
}

std::ostream& operator<<(std::ostream& s, const AForm& f) {
    s << f.getName() << ", required grade to sign " << f.getGradeToSign() << ", required grade to execute " << f.getGradeToExec();
    if (f.getIsSigned()) {
        s << ", is signed.";
    }
    else {
        s << ", is not signed.";
    }
    return s;
}
