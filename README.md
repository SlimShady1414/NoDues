**Files Description**:

main.cpp: This file contains the main function and the user interface for the dues management system. It handles user input, authentication, and displays the dues information. It also calls other functions to update dues, check for remaining dues, and generate a certificate if all dues are cleared.

Student.h: This file defines the Student class, which is used to represent a student in the system. It includes the necessary member variables and functions for student authentication.

Student.cpp: This file contains the implementation of the Student class member functions, including the authentication logic.

passwords.txt: This text file stores the student registration numbers (SRNs) and corresponding passwords for authentication. Each line contains an SRN followed by a password.

dues.txt: This text file stores the dues information for each student. It includes the SRN and the respective departments along with their due amounts.

**Program Flow Description**:

The program starts by asking the user to enter their Student Registration Number (SRN) and password for authentication.

It then reads the passwords.txt file to authenticate the student. If the provided SRN and password match any entry in the file, the student is considered authenticated, and they can proceed further.

After authentication, the program displays the dues information for the authenticated student by reading the dues.txt file. It shows the dues for various departments (Library, Laboratory, Transport, Examination) associated with the SRN.

If the student has no remaining dues, the program generates a certificate. The certificate is saved to a file with the SRN appended to its name.

If there are remaining dues, the program allows the student to clear them one by one for each department. The student can enter the amount to pay, and the dues are updated accordingly.

After clearing the dues for all departments, the program checks again if there are any remaining dues. If not, it generates the certificate

If there are still remaining dues after trying to clear them, the program will exit, and the student needs to try again later after paying all the dues.

**PLEASE NOTE**
The environment variable name is Nodues and the variable value is the path to the directory in which the files are saved.

**Program execution**

1) g++ -o main main.cpp Student.cpp

2) ./main.exe

Contributors:
1) [Abhirup MVNS](https://github.com/CodeMaster1901)
2) [Adhi Nandan J](https://github.com/SlimShady1414)
3) [Adithya S Gurikar](https://github.com/adithya-gurikar)
