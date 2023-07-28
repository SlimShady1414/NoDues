#ifndef STUDENT_H
#define STUDENT_H

#include <string>

namespace University {
    class Student {
    private:
        std::string srn;
        std::string password;

    public:
        Student(const std::string& srn, const std::string& password);
        bool authenticate() const;
        const std::string& getSRN() const;
        const std::string& getPassword() const;
    };
}

#endif // STUDENT_H
