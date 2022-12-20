#ifndef __user
#define __user

class User
{
public:
  User();
  User(const char *, const char *);
  void setId(const char *); 
  void setPassword(const char *); 
  std::string getId(); 
  std::string getPassword(); 
  bool isUser(std::string, std::string);
  User operator+(const User &);
  User operator==(const User &);
  User operator!=(const User &);
  User operator>(const User &);
  User operator>=(const User &);
  User operator<(const User &);
  User operator<=(const User &);
  User operator=(const User &);
  User operator+=(const User &);
  User operator&&(const User &);
  User operator||(const User &);  

private:
  std::string id;
  std::string password;
};

#endif