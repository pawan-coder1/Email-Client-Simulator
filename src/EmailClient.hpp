#ifndef EMAIL_CLIENT_HPP
#define EMAIL_CLIENT_HPP

#include <string>
#include <vector>
#include <ctime>

// Email Class Declaration
class Email
{
public:
  std::string sender;
  std::string recipient;
  std::string subject;
  std::string body;
  time_t timestamp;

  Email(std::string sender, std::string recipient, std::string subject, std::string body);
  void displayEmail() const;
  std::string serialize() const;
  static Email deserialize(const std::string &data);
};

// Inbox Class Declaration
class Inbox
{
private:
  std::vector<Email> emails;

public:
  void receiveEmail(const Email &email);
  void displayInbox() const;
  void saveToFile(const std::string &filename) const;
  void loadFromFile(const std::string &filename);
  std::vector<Email> searchEmails(const std::string &keyword) const;
};

// Outbox Class Declaration
class Outbox
{
private:
  std::vector<Email> emails;

public:
  void sendEmail(const Email &email);
  void displayOutbox() const;
  void saveToFile(const std::string &filename) const;
  void loadFromFile(const std::string &filename);
};

#endif
