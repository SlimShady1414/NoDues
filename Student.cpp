#include "Student.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace University {
    Student::Student(const string& srn, const string& password)
        : srn(srn), password(password) {}

    bool authenticateStudent(const string& srn, const string& password) {
        ifstream passwordFile("passwords.txt");
        if (!passwordFile) {
            cerr << "Error: passwords.txt file not found." << endl;
            return false;
        }

        string line;
        while (getline(passwordFile, line)) {
            istringstream iss(line);
            string storedSRN, storedPassword;
            if (iss >> storedSRN >> storedPassword) {
                if (storedSRN == srn && storedPassword == password) {
                    return true;
                }
            }
        }

        return false;
    }

    bool Student::authenticate() const {
        return authenticateStudent(srn, password);
    }

    const string& Student::getSRN() const {
        return srn;
    }

    const string& Student::getPassword() const {
        return password;
    }
}
