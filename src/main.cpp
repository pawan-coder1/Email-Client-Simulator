#include "EmailClient.hpp"
#include <iostream>

void showMenu()
{
  std::cout << "Email Client Simulator\n";
  std::cout << "1. Send Email\n";
  std::cout << "2. View Inbox\n";
  std::cout << "3. View Outbox\n";
  std::cout << "4. Search Emails\n";
  std::cout << "5. Exit\n";
}

int main()
{
  Inbox inbox;
  Outbox outbox;

  // Load emails from files
  inbox.loadFromFile("inbox.txt");
  outbox.loadFromFile("outbox.txt");

  int choice;
  do
  {
    showMenu();
    std::cout << "Choose an option: ";
    std::cin >> choice;

    if (choice == 1)
    {
      std::string sender, recipient, subject, body;
      std::cout << "Enter sender email: ";
      std::cin >> sender;
      std::cout << "Enter recipient email: ";
      std::cin >> recipient;
      std::cout << "Enter subject: ";
      std::cin.ignore(); // To ignore leftover newline character
      std::getline(std::cin, subject);
      std::cout << "Enter body: ";
      std::getline(std::cin, body);

      Email email(sender, recipient, subject, body);
      outbox.sendEmail(email);
      inbox.receiveEmail(email);
      std::cout << "Email sent and received successfully!\n";
    }
    else if (choice == 2)
    {
      inbox.displayInbox();
    }
    else if (choice == 3)
    {
      outbox.displayOutbox();
    }
    else if (choice == 4)
    {
      std::string keyword;
      std::cout << "Enter keyword to search: ";
      std::cin >> keyword;
      std::vector<Email> results = inbox.searchEmails(keyword);
      std::cout << "Search Results:\n";
      for (const auto &email : results)
      {
        email.displayEmail();
        std::cout << "-------------------\n";
      }
    }

    // Save emails to files after every operation
    inbox.saveToFile("inbox.txt");
    outbox.saveToFile("outbox.txt");

  } while (choice != 5);

  std::cout << "Exiting Email Client Simulator.\n";
  return 0;
}
