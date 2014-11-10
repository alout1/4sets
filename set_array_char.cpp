#include "set_array_char.h"

namespace set_array_char{

bool Set::contains(char c)
{
    for (int i = 0; i < this->size(); ++i)
        if (Data[i] == c)
            return true;
    return false;
}

char& Set::operator [](int index)
{
        return Data[index];
}

Set::Set()
{
    Data = nullptr;
}

Set::Set(const char* new_data)
{
    Data = new char[strlen(new_data)];
    memcpy(Data, new_data, strlen(new_data));
}

Set::Set(Set& s)
{
    Data = new char[s.size()];
    memcpy(Data, s.Data, s.size());
}

Set::~Set()
{
    delete[] Data;
}

Set& Set::operator =(Set rhs) 
{
    std::swap(Data, rhs.Data);
    return *this;
}

Set& Set::operator ~() 
{
    int new_size = MAX_SIZE - this->size() + 2; 
    char* new_data = new char[new_size]; 
    int i,j;
    
    for (i = 0, j = 0; i < MAX_SIZE; ++i) 
        if (this->contains(Vocabulary[i]))
            continue;
        else
            new_data[j++] = Vocabulary[i];
   
    Set* s = new Set(new_data);
    return *s;
}

Set& Set::operator &(Set& rhs)
{  
   char new_data[MAX_SIZE];
   int i,j;
   
   for (i = 0, j = 0; i < size(); ++i )
       if (rhs.contains(Data[i])) 
            new_data[j++] = Data[i];
   new_data[j] = '\0';
   
   Set* s = new Set(new_data);
   return *s;        
}

std::ostream& operator<<(std::ostream& out, Set& s)
{
    out << '{';
    if (s[0] != 0)
        for (int i=0; i < s.size(); ++i)
            out << s[i];
    else
        out << "empty";
    out << '}';
    return out;
}

} // namespace set_array_char