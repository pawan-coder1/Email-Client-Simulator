# Email-Client-Simulator
Email Client Simulator
Project Description
The Email Client Simulator is a C++ console application designed to emulate the basic functionalities of an email client. This project allows users to send, receive, and organize emails within a simulated environment. The application focuses on key features such as composing emails, viewing inbox and outbox, searching for specific emails, and maintaining email data persistence through file handling.

Features
Send Emails:

Users can compose new emails by entering the sender, recipient, subject, and body. Once an email is sent, it is stored in both the outbox and inbox for easy access and record-keeping.
View Inbox:

The inbox feature allows users to view all received emails, displaying the details such as sender, subject, and body.
View Outbox:

Users can review all sent emails by accessing the outbox, providing a convenient way to track outgoing communication.
Search Emails:

The application includes a search functionality that enables users to find specific emails by entering keywords. The search scans both the subject and body of emails for matches.
Data Persistence:

Email data is stored in text files (inbox.txt and outbox.txt) to ensure that the emails remain available between sessions. The application loads the emails from these files upon startup and saves any new or modified data upon exiting.
Technologies Used
C++: Core language used to build the application.
File Handling: For loading and saving email data to maintain persistence across sessions.
Object-Oriented Programming (OOP): Applied to structure the application with classes for managing emails and their operations.
Project Structure
Email.hpp and Email.cpp: Define the Email class, which encapsulates the properties and methods related to individual emails.
Inbox.hpp and Inbox.cpp: Manage the received emails, including loading, displaying, and searching within the inbox.
Outbox.hpp and Outbox.cpp: Handle sent emails, providing functionality for sending and viewing emails in the outbox.
main.cpp: The entry point of the application, managing the user interface and integrating the functionalities of sending, viewing, and searching emails.
Setup Instructions
Clone the Repository:
Download or clone the project repository to your local machine.
Compile the Project:
Use a C++ compiler like g++ to compile the project files. For example:
bash
Copy code
g++ -o email_client main.cpp Email.cpp Inbox.cpp Outbox.cpp
Run the Application:
Execute the compiled binary to start the email client simulator:
bash
Copy code
./email_client
Usage:
Follow the on-screen menu to interact with the email client, where you can send, view, and search emails.
