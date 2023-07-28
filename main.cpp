// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>

// #include "Student.h" // Include the Student header file

// using namespace std;

// bool authenticateStudent(const string& srn, const string& password) {
//     ifstream passwordFile("passwords.txt");
//     if (!passwordFile) {
//         cerr << "Error: passwords.txt file not found." << endl;
//         return false;
//     }

//     string line;
//     while (getline(passwordFile, line)) {
//         istringstream iss(line);
//         string storedSRN, storedPassword;
//         if (iss >> storedSRN >> storedPassword) {
//             if (storedSRN == srn && storedPassword == password) {
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// bool getDuesForDepartment(const string& srn, const string& department, int& dues) {
//     ifstream duesFile("dues.txt");
//     if (!duesFile) {
//         cerr << "Error: dues.txt file not found." << endl;
//         return false;
//     }

//     string line;
//     while (getline(duesFile, line)) {
//         istringstream iss(line);
//         string storedSRN;
//         if (iss >> storedSRN) {
//             if (storedSRN == srn) {
//                 string dept;
//                 while (iss >> dept) {
//                     string departmentName = dept.substr(0, dept.find('-'));
//                     string duesStr = dept.substr(dept.find('-') + 1);
//                     int duesAmount = stoi(duesStr);
//                     if (departmentName == department) {
//                         duesFile.close();
//                         dues = duesAmount;
//                         return true;
//                     }
//                 }
//                 break;
//             }
//         }
//     }

//     duesFile.close();
//     return false;
// }

// void displayDues(const string& srn) {
//     ifstream duesFile("dues.txt");
//     if (!duesFile) {
//         cerr << "Error: dues.txt file not found." << endl;
//         return;
//     }

//     string line;
//     while (getline(duesFile, line)) {
//         istringstream iss(line);
//         string storedSRN;
//         if (iss >> storedSRN) {
//             if (storedSRN == srn) {
//                 cout << "Dues for " << srn << ":\n";
//                 string department;
//                 while (iss >> department) {
//                     string departmentName = department.substr(0, department.find('-'));
//                     string duesStr = department.substr(department.find('-') + 1);
//                     int duesAmount = stoi(duesStr);
//                     cout << departmentName << " Department: " << duesAmount << " /- INR\n";
//                 }
//                 cout << endl;
//                 break;
//             }
//         }
//     }

//     duesFile.close();
// }

// void updateDues(const string& srn, const string& department, int amount) {
//     ifstream duesFile("dues.txt");
//     if (!duesFile) {
//         cerr << "Error: dues.txt file not found." << endl;
//         return;
//     }

//     vector<string> lines;
//     string line;
//     while (getline(duesFile, line)) {
//         lines.push_back(line);
//     }

//     duesFile.close();

//     ofstream outFile("dues.txt");
//     if (!outFile) {
//         cerr << "Error: Unable to open dues.txt for writing." << endl;
//         return;
//     }

//     for (const auto& l : lines) {
//         istringstream iss(l);
//         string storedSRN;
//         if (iss >> storedSRN) {
//             if (storedSRN == srn) {
//                 outFile << srn << " ";
//                 string dept;
//                 while (iss >> dept) {
//                     string departmentName = dept.substr(0, dept.find('-'));
//                     string duesStr = dept.substr(dept.find('-') + 1);
//                     int duesAmount = stoi(duesStr);
//                     if (departmentName == department) {
//                         duesAmount -= amount;
//                         if (duesAmount < 0) {
//                             duesAmount = 0; // Make sure dues don't go negative
//                         }
//                     }
//                     outFile << departmentName << "-" << duesAmount << " ";
//                 }
//                 outFile << endl;
//             } else {
//                 outFile << l << endl;
//             }
//         }
//     }

//     outFile.close();
// }

// bool hasRemainingDues(const string& srn) {
//     ifstream duesFile("dues.txt");
//     if (!duesFile) {
//         cerr << "Error: dues.txt file not found." << endl;
//         return false;
//     }

//     string line;
//     while (getline(duesFile, line)) {
//         istringstream iss(line);
//         string storedSRN;
//         if (iss >> storedSRN) {
//             if (storedSRN == srn) {
//                 string dept;
//                 while (iss >> dept) {
//                     string departmentName = dept.substr(0, dept.find('-'));
//                     string duesStr = dept.substr(dept.find('-') + 1);
//                     int duesAmount = stoi(duesStr);
//                     if (duesAmount > 0) {
//                         duesFile.close();
//                         return true;
//                     }
//                 }
//                 break;
//             }
//         }
//     }

//     duesFile.close();
//     return false;
// }

// void clearDues(const string& srn) {
//     vector<string> departments = {"Library", "Laboratory", "Transport", "Examination"};
//     for (const auto& department : departments) {
//         while (true) {
//             int amountToPay;
//             bool hasDues = getDuesForDepartment(srn, department, amountToPay);
//             if (!hasDues || amountToPay == 0) {
//                 break; // No dues to pay for this department or dues already cleared
//             }

//             cout << "Enter amount to pay for " << department << " Department (Due amount: " << amountToPay << "): ";
//             cin >> amountToPay;
//             if (amountToPay < 0 || amountToPay > amountToPay) {
//                 cout << "Invalid amount. Please enter a valid amount (0 <= amount <= " << amountToPay << ")." << endl;
//             } else {
//                 updateDues(srn, department, amountToPay);
//                 cout << "Payment received from student with SRN: " << srn << " in department " << department << endl;
//                 displayDues(srn);
//             }
//         }
//     }
// }
// void generateCertificate(const string& srn) {
//     const string pesUniversityText = "PES UNIVERSITY";
//     const int totalWidth = 60;
//     const int pesTextWidth = pesUniversityText.length();
//     const int borderPadding = (totalWidth - pesTextWidth - 4) / 2; // Account for borders

//     ofstream certificateFile(srn + "_no_dues_certificate.txt");
//     if (certificateFile) {
//         certificateFile << string(totalWidth, '*') << endl;
//         certificateFile << "* " << string(borderPadding, ' ') << pesUniversityText
//                         << string(borderPadding, ' ') << " *" << endl;
//         certificateFile << "* " << string(totalWidth - 4, ' ') << " *" << endl;
        
//         // Ensure that the student's SRN fits within the available space
//         if (srn.length() <= (totalWidth - 4)) {
//             certificateFile << "* " << srn << ", you have cleared all the dues." 
//                             << string(totalWidth - 9 - srn.length(), ' ') << " *" << endl;
//         } else {
//             certificateFile << "* " << srn.substr(0, totalWidth - 9) << "..., you have cleared all the dues. *" << endl;
//         }
        
//         certificateFile << "* " << string(totalWidth - 4, ' ') << " *" << endl;
//         certificateFile << string(totalWidth, '*') << endl;
//         certificateFile.close();

//         cout << "Congratulations! " << srn << ", you have cleared all the dues." << endl;
//     } else {
//         cerr << "Error: Unable to generate the certificate for " << srn << "." << endl;
//     }
// }
// int main() {
//     string srn, password;
//     bool authenticated = false;

//     while (!authenticated) {
//         cout << "Enter SRN: ";
//         cin >> srn;
//         cout << "Enter password: ";
//         cin >> password;

//         authenticated = authenticateStudent(srn, password);

//         if (!authenticated) {
//             cout << "Authentication failed. Please try again." << endl;
//         }
//     }

//     displayDues(srn);

//     if (!hasRemainingDues(srn)) {
//         return 0;
//     }

//     clearDues(srn);

//     if (!hasRemainingDues(srn)) {
//         generateCertificate(srn);
//     }


//     return 0;
// }


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Student.h" // Include the Student header file

using namespace std;

string getProjectDirectory() {
    char* noduesPath = getenv("Nodues");
    if (noduesPath == nullptr) {
        cerr << "Error: Nodues environment variable not set." << endl;
        exit(EXIT_FAILURE);
    }
    return string(noduesPath);
}

bool authenticateStudent(const string& srn, const string& password) {
    string projectDirectory = getProjectDirectory();
    ifstream passwordFile(projectDirectory + "/passwords.txt");
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

bool getDuesForDepartment(const string& srn, const string& department, int& dues) {
    string projectDirectory = getProjectDirectory();
    ifstream duesFile(projectDirectory + "/dues.txt");
    if (!duesFile) {
        cerr << "Error: dues.txt file not found." << endl;
        return false;
    }

    string line;
    while (getline(duesFile, line)) {
        istringstream iss(line);
        string storedSRN;
        if (iss >> storedSRN) {
            if (storedSRN == srn) {
                string dept;
                while (iss >> dept) {
                    string departmentName = dept.substr(0, dept.find('-'));
                    string duesStr = dept.substr(dept.find('-') + 1);
                    int duesAmount = stoi(duesStr);
                    if (departmentName == department) {
                        duesFile.close();
                        dues = duesAmount;
                        return true;
                    }
                }
                break;
            }
        }
    }

    duesFile.close();
    return false;
}

void displayDues(const string& srn) {
    ifstream duesFile("dues.txt");
    if (!duesFile) {
        cerr << "Error: dues.txt file not found." << endl;
        return;
    }

    string line;
    while (getline(duesFile, line)) {
        istringstream iss(line);
        string storedSRN;
        if (iss >> storedSRN) {
            if (storedSRN == srn) {
                cout << "Dues for " << srn << ":\n";
                string department;
                while (iss >> department) {
                    string departmentName = department.substr(0, department.find('-'));
                    string duesStr = department.substr(department.find('-') + 1);
                    int duesAmount = stoi(duesStr);
                    cout << departmentName << " Department: " << duesAmount << " /- INR\n";
                }
                cout << endl;
                break;
            }
        }
    }

    duesFile.close();
}

void updateDues(const string& srn, const string& department, int amount) {
    ifstream duesFile("dues.txt");
    if (!duesFile) {
        cerr << "Error: dues.txt file not found." << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(duesFile, line)) {
        lines.push_back(line);
    }

    duesFile.close();

    ofstream outFile("dues.txt");
    if (!outFile) {
        cerr << "Error: Unable to open dues.txt for writing." << endl;
        return;
    }

    for (const auto& l : lines) {
        istringstream iss(l);
        string storedSRN;
        if (iss >> storedSRN) {
            if (storedSRN == srn) {
                outFile << srn << " ";
                string dept;
                while (iss >> dept) {
                    string departmentName = dept.substr(0, dept.find('-'));
                    string duesStr = dept.substr(dept.find('-') + 1);
                    int duesAmount = stoi(duesStr);
                    if (departmentName == department) {
                        duesAmount -= amount;
                        if (duesAmount < 0) {
                            duesAmount = 0; // Make sure dues don't go negative
                        }
                    }
                    outFile << departmentName << "-" << duesAmount << " ";
                }
                outFile << endl;
            } else {
                outFile << l << endl;
            }
        }
    }

    outFile.close();
}

bool hasRemainingDues(const string& srn) {
    ifstream duesFile("dues.txt");
    if (!duesFile) {
        cerr << "Error: dues.txt file not found." << endl;
        return false;
    }

    string line;
    while (getline(duesFile, line)) {
        istringstream iss(line);
        string storedSRN;
        if (iss >> storedSRN) {
            if (storedSRN == srn) {
                string dept;
                while (iss >> dept) {
                    string departmentName = dept.substr(0, dept.find('-'));
                    string duesStr = dept.substr(dept.find('-') + 1);
                    int duesAmount = stoi(duesStr);
                    if (duesAmount > 0) {
                        duesFile.close();
                        return true;
                    }
                }
                break;
            }
        }
    }

    duesFile.close();
    return false;
}

void clearDues(const string& srn) {
    vector<string> departments = {"Library", "Laboratory", "Transport", "Examination"};
    for (const auto& department : departments) {
        while (true) {
            int amountToPay;
            bool hasDues = getDuesForDepartment(srn, department, amountToPay);
            if (!hasDues || amountToPay == 0) {
                break; // No dues to pay for this department or dues already cleared
            }

            cout << "Enter amount to pay for " << department << " Department (Due amount: " << amountToPay << "): ";
            cin >> amountToPay;
            if (amountToPay < 0 || amountToPay > amountToPay) {
                cout << "Invalid amount. Please enter a valid amount (0 <= amount <= " << amountToPay << ")." << endl;
            } else {
                updateDues(srn, department, amountToPay);
                cout << "Payment received from student with SRN: " << srn << " in department " << department << endl;
                displayDues(srn);
            }
        }
    }
}
// void generateCertificate(const string& srn) {
//     const string pesUniversityText = "PES UNIVERSITY";
//     const int totalWidth = 60;
//     const int pesTextWidth = pesUniversityText.length();
//     const int borderPadding = (totalWidth - pesTextWidth - 4) / 2; // Account for borders

//     ofstream certificateFile(srn + "_no_dues_certificate.txt");
//     if (certificateFile) {
//         certificateFile << string(totalWidth, '*') << endl;
//         certificateFile << "* " << string(borderPadding, ' ') << pesUniversityText
//                         << string(borderPadding, ' ') << " *" << endl;
//         certificateFile << "* " << string(totalWidth - 4, ' ') << " *" << endl;
        
//         // Ensure that the student's SRN fits within the available space
//         if (srn.length() <= (totalWidth - 4)) {
//             certificateFile << "* " << srn << ", you have cleared all the dues." 
//                             << string(totalWidth - 9 - srn.length(), ' ') << " *" << endl;
//         } else {
//             certificateFile << "* " << srn.substr(0, totalWidth - 9) << "..., you have cleared all the dues. *" << endl;
//         }
        
//         certificateFile << "* " << string(totalWidth - 4, ' ') << " *" << endl;
//         certificateFile << string(totalWidth, '*') << endl;
//         certificateFile.close();

//         cout << "Congratulations! " << srn << ", you have cleared all the dues." << endl;
//     } else {
//         cerr << "Error: Unable to generate the certificate for " << srn << "." << endl;
//     }
// }

void generateCertificate(const string& srn) {
    string projectDirectory = getProjectDirectory();
    const string pesUniversityText = "PES UNIVERSITY";
    const int totalWidth = 60;
    const int pesTextWidth = pesUniversityText.length();
    const int borderPadding = (totalWidth - pesTextWidth - 4) / 2; // Account for borders

    ofstream certificateFile(projectDirectory + "/" + srn + "_no_dues_certificate.txt");
    if (certificateFile) {
        certificateFile << string(totalWidth, '*') << endl;
        certificateFile << "* " << string(borderPadding, ' ') << pesUniversityText
                        << string(borderPadding, ' ') << " *" << endl;
        certificateFile << "* " << string(totalWidth - 4, ' ') << " *" << endl;
        
        // Ensure that the student's SRN fits within the available space
        if (srn.length() <= (totalWidth - 4)) {
            certificateFile << "* " << srn << ", you have cleared all the dues." 
                            << string(totalWidth - 9 - srn.length(), ' ') << " *" << endl;
        } else {
            certificateFile << "* " << srn.substr(0, totalWidth - 9) << "..., you have cleared all the dues. *" << endl;
        }
        
        certificateFile << "* " << string(totalWidth - 4, ' ') << " *" << endl;
        certificateFile << string(totalWidth, '*') << endl;
        certificateFile.close();

        cout << "Congratulations! " << srn << ", you have cleared all the dues." << endl;
    } else {
        cerr << "Error: Unable to generate the certificate for " << srn << "." << endl;
    }
}

// int main() {
//     string srn, password;
//     bool authenticated = false;

//     while (!authenticated) {
//         cout << "Enter SRN: ";
//         cin >> srn;
//         cout << "Enter password: ";
//         cin >> password;

//         authenticated = authenticateStudent(srn, password);

//         if (!authenticated) {
//             cout << "Authentication failed. Please try again." << endl;
//         }
//     }

//     displayDues(srn);

//     if (!hasRemainingDues(srn)) {
//         return 0;
//     }

//     clearDues(srn);

//     if (!hasRemainingDues(srn)) {
//         generateCertificate(srn);
//     }


//     return 0;
// }

int main() {
    string srn, password;
    bool authenticated = false;

    while (!authenticated) {
        cout << "Enter SRN: ";
        cin >> srn;
        cout << "Enter password: ";
        cin >> password;

        authenticated = authenticateStudent(srn, password);

        if (!authenticated) {
            cout << "Authentication failed. Please try again." << endl;
        }
    }

    displayDues(srn);

    if (!hasRemainingDues(srn)) {
        return 0;
    }

    clearDues(srn);

    if (!hasRemainingDues(srn)) {
        generateCertificate(srn);
    }

    return 0;
}
