#include "EmailClient.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Email Class Implementation
Email::Email(std::string sender, std::string recipient, std::string subject, std::string body)
    : sender(sender), recipient(recipient), subject(subject), body(body)
{
  timestamp = std::time(nullptr); // Capture current time
}

void Email::displayEmail() const
{
  std::cout << "From: " << sender << "\n"
            << "To: " << recipient << "\n"
            << "Subject: " << subject << "\n"
            << "Body: " << body << "\n"
            << "Sent: " << std::ctime(&timestamp);
}

std::string Email::serialize() const
{
  std::ostringstream oss;
  oss << sender << "\n"
      << recipient << "\n"
      << subject << "\n"
      << body << "\n"
      << timestamp << "\n";
  return oss.str();
}

Email Email::deserialize(const std::string &data)
{
  std::istringstream iss(data);
  std::string sender, recipient, subject, body;
  time_t timestamp;

  std::getline(iss, sender);
  std::getline(iss, recipient);
  std::getline(iss, subject);
  std::getline(iss, body);
  iss >> timestamp;

  Email email(sender, recipient, subject, body);
  email.timestamp = timestamp;
  return email;
}

// Inbox Class Implementation
void Inbox::receiveEmail(const Email &email)
{
  // Simple spam filter
  if (email.subject.find("spam") != std::string::npos || email.body.find("spam") != std::string::npos)
  {
    std::cout << "Spam email detected and ignored!\n";
  }
  else
  {
    emails.push_back(email);
  }
}

void Inbox::displayInbox() const
{
  std::cout << "\nInbox:\n";
  for (const auto &email : emails)
  {
    email.displayEmail();
    std::cout << "-------------------\n";
  }
}

void Inbox::saveToFile(const std::string &filename) const
{
  std::ofstream file(filename);
  for (const auto &email : emails)
  {
    file << email.serialize() << "\n";
  }
}

void Inbox::loadFromFile(const std::string &filename)
{
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line))
  {
    std::string emailData;
    for (int i = 0; i < 5; ++i)
    {
      emailData += line + "\n";
      std::getline(file, line);
    }
    emails.push_back(Email::deserialize(emailData));
  }
}

std::vector<Email> Inbox::searchEmails(const std::string &keyword) const
{
  std::vector<Email> result;
  for (const auto &email : emails)
  {
    if (email.sender.find(keyword) != std::string::npos ||
        email.subject.find(keyword) != std::string::npos ||
        email.body.find(keyword) != std::string::npos)
    {
      result.push_back(email);
    }
  }
  return result;
}

// Outbox Class Implementation
void Outbox::sendEmail(const Email &email)
{
  emails.push_back(email);
}

void Outbox::displayOutbox() const
{
  std::cout << "\nOutbox:\n";
  for (const auto &email : emails)
  {
    email.displayEmail();
    std::cout << "-------------------\n";
  }
}

void Outbox::saveToFile(const std::string &filename) const
{
  std::ofstream file(filename);
  for (const auto &email : emails)
  {
    file << email.serialize() << "\n";
  }
}

void Outbox::loadFromFile(const std::string &filename)
{
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line))
  {
    std::string emailData;
    for (int i = 0; i < 5; ++i)
    {
      emailData += line + "\n";
      std::getline(file, line);
    }
    emails.push_back(Email::deserialize(emailData));
  }
}
