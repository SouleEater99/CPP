#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
    std::string Name;
public:
    void announce(void);
    Zombie(const std::string& name);
    ~Zombie();
};

 Zombie* newZombie(std::string& name);
 void    randomChump(std::string& name);

#endif