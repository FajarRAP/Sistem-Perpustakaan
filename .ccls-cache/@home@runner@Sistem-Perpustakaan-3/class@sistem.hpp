#ifndef __sistem
#define __sistem

class Sistem
{
public:
  Sistem();
  Sistem(char, const char *, const char *);
  void setTipeUser(char);
  void setUsername(const char *);
  void setPassword(const char *);
  char getTipeUser();
  std::string getUsername();
  std::string getPassword();
  bool Login(bool, bool);
  Sistem operator+(const Sistem &);
  Sistem operator==(const Sistem &);
  Sistem operator!=(const Sistem &);
  Sistem operator>(const Sistem &);
  Sistem operator>=(const Sistem &);
  Sistem operator<(const Sistem &);
  Sistem operator<=(const Sistem &);
  Sistem operator&&(const Sistem &);
  Sistem operator||(const Sistem &);
  Sistem operator=(const Sistem &);
  Sistem operator+=(const Sistem &);

private:
  char tipeUser;
  std::string username;
  std::string password;
};

#endif