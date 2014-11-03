#include "set_array_char.h"

namespace set_array_char{

bool Set::contains(char c)
{
    for (int i = 0; i < this->size(); ++i)
        if (Data[i] == c)
            return true;
    return false;
}

void Set::shuffle(char *array, size_t n) // http://stackoverflow.com/a/6127606
{ 
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          char t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
char& Set::operator [](int index)
{
    return Data[index];
}

Set::Set()
{
    char* new_data = new char[MAX_SIZE + 1];
    strcpy(new_data, Vocabulary);
    shuffle(new_data, MAX_SIZE);
    int newsize = rand()%MAX_SIZE+1;
    Data = new char[newsize];
    memcpy(Data, new_data, newsize +1);
    delete[] new_data;
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
    //std::cout << "old op=\n";
    std::swap(Data, rhs.Data);
    return *this;
}

Set& Set::operator ~()
{
    //std::cout<<"op~\n";
    int new_size = MAX_SIZE - this->size() + 2; // +2 ???
    char* new_data = new char[new_size]; 
    int i,j;
    
    for (i = 0, j = 0; i < MAX_SIZE; ++i) 
        if (this->contains(Vocabulary[i]))
            continue;
        else
            new_data[j++] = Vocabulary[i];
    
    delete[] this->Data;
    this->Data = new_data;
    return *this;
}

Set& Set::operator &(Set& rhs)
{  
   //std::cout<<"op&\n"; 
   char new_data[MAX_SIZE];
   int i,j;
   
   for (i = 0, j = 0; i < size(); ++i )
       if (rhs.contains(Data[i])) 
            new_data[j++] = Data[i];
   new_data[j] = '\0';
   
   Set* s = new Set(new_data);
   return *s; 
   
   return *this;         
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