# Covid 19 Vaccination Management Project
This project, developed in C for the CSE115L - Programming Language I Lab course at NSU, provides comprehensive information about patients, including their vaccination status. This program ulitises a command-line based system for managing Covid-19 vaccination registrations and generating vaccination certificates. The system has separate functionalities for admins and users, allowing administrators to manage user information and certificates, and users to register for vaccination and view their certificates.

## Features

### Admin Features
- **Admin Registration/Login:** Register and login as an admin.
- **View Registered Users:** Admins can view the information of all users who have registered for vaccination.
- **Mark Vaccination:** Admins can mark a user as vaccinated and generate their vaccination certificate.

### User Features
- **User Registration/Login:** Register and login as a user.
- **Register for Vaccination:** Users can register themselves for vaccination by providing personal details such as name, gender, age, and NID.
- **View Vaccination Certificate:** Once vaccinated, users can retrieve their vaccination certificates.


### File Storage
- **User Information:** The user information is stored in `userinfo.txt`.
- **Admin Information:** Admin credentials are stored in `adminID.txt`.
- **User Credentials:** User credentials are stored in `userID.txt`.
- **Vaccination Certificates** Certificates are saved as `vaccinated<serial_number>.txt`.

### Program Flow
1. **Main Menu:** The system displays options for Admin or User Registration/Login.
2. **Admin Panel:** After successful login, admins can view registered users or generate vaccination certificates.
3. **User Panel:** After login, users can register for vaccination or view their vaccination certificate.

### Code Overview
The project includes the following main functionalities:

- **Admin Registration/Login:** Manages the registration and login for admins.
- **User Registration/Login:** Handles user registration and login.
- **Vaccination Registration:** Captures personal details for vaccination.
- **Certificate Generation:** Marks a user as vaccinated and generates a certificate.
- **File Management:** Handles reading and writing data to files.

### Known Limitations
- The system currently supports only up to 100 users.
- User and admin data are stored in plain text files, which may raise security concerns.

### Future Enhancements
- Improve security by encrypting passwords.
- Expand user storage and switch to a database for better scalability.
- Add validation and error handling for edge cases.


## Setup and Usage

### Prerequisites
- This program is designed for Windows, as it uses libraries like `conio.h` and `windows.h`.
- Make sure you have a C compiler installed (e.g., GCC or MSVC).

### Cloning the Repository
To clone this repository, run the following command in your terminal:

```bash
git clone https://github.com/LyFIzH3LL/Covid-19-Vaccination-Management-Project.git
```

### Navigate to the project directory
```bash
cd Covid-19-Vaccination-Management-Project
```

## Compilation

To compile the program, use a C compiler. For example, with GCC:

```bash
gcc labproject.c -o vaccination_system
```

### Running the program
After compilation, run this executable:
```bash
./vaccination_system
```
