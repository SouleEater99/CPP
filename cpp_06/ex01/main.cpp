#include "Serializer.hpp"


int main()
{
    Data data;

    data.i = 1337;
    data.msg = "Serialize Work Properly\n";


    std::cout << "before using serialize method : i = " << data.i << "\n"; 
    std::cout << "before serialize msg : " << data.msg;
    std::cout << "Data Addresss: " << &data << std::endl;
    
    uintptr_t   value =  Serializer::serialize(&data);
    Data        *ptr  =  Serializer::deserialize(value);

    std::cout << "\n========================================\n\n";

    std::cout << "after using deserialize method: i = " <<  ptr->i << "\n" ; 
    std::cout << "after deserailize msg : " << data.msg;
    std::cout << "uintptr_t Address after serializer : " << value << std::endl;


}