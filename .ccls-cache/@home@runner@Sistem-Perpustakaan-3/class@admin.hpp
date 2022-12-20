#ifndef __admin
#define __admin

class Admin
{
  public:
    Admin();
    Admin(const char *, const char *);
    Admin(const char *, const char *, const char *);
    void setNama(const char *);
    void setId(const char *);
    void setPassword(const char *);
    std::string getNama();
    std::string getId();
    std::string getPassword();
    bool isAdmin(std::string, std::string);
    Admin operator+(const Admin &);
    Admin &operator=(const Admin &);
    Admin &operator+=(const char *);
    Admin operator==(const Admin &);
    Admin operator!=(const Admin &);
    Admin operator>(const Admin &);
    Admin operator>=(const Admin &);  
    Admin operator<(const Admin &);
    Admin operator<=(const Admin &);
    Admin operator&&(const Admin &);
    Admin operator||(const Admin &);

  private:
    std::string nama;
    std::string id;
    std::string password;
};

#endif