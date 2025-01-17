#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
    std::string Name;
public:
    void    announce(void);
    void    setName(const std::string & name);
    Zombie(void);
    Zombie(const std::string& name);
    ~Zombie();

};

Zombie* zombieHorde( int N, std::string& name);

#endif