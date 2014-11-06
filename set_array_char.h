#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>

#ifndef SET_ARRAY_CHAR_H
#define	SET_ARRAY_CHAR_H

namespace set_array_char
{
  const int MAX_SIZE = 16;
  const char Vocabulary[] = "0123456789ABCDEF";
      
  class Set{
  private:
      char* Data;
      bool contains(char c);
      inline size_t size() { return strlen(Data); }
      void shuffle(char *array, size_t n); 
      
  public:     
      Set();
      Set(const char* new_data);
      Set(Set& s);
      ~Set();

      char& operator[](int index);
      Set& operator =(Set rhs); // http://stackoverflow.com/a/3279550
      Set& operator~();
      Set& operator&(Set& rhs);
      friend std::ostream& operator<<(std::ostream& out, Set& s);
  };  
    
} // namespace set_array_char

#endif	/* SET_ARRAY_CHAR_H */

