/* 
 * File:   main.cpp
 * Author: alex
 *
 * Created on 22 октября 2014 г., 0:57
 */

#include "set_array_char.h"
#include "set_list.h"
#include "set_array_bool.h"
#include "set_uint.h"

#include <chrono>

using namespace std;
using namespace std::chrono;

char* getRandomStr();

int main(int argc, char** argv) 
{
    srand(time(NULL));
    steady_clock::time_point t1, t2; 
    duration<double> time_span;
    
    char *a = getRandomStr(),
         *b = getRandomStr(),
         *c = getRandomStr(),
         *d = getRandomStr();
    cout << "A = " << a << "\nB = " << b << "\nC = " << c << "\nD = " << d << "\n";
    
    cout<<"======================== char array\n";
    {
        t1 = steady_clock::now();
        
        using namespace set_array_char;
        Set A(a), B(b), C(c), D(d), E;
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    } 

    cout<<"======================== list\n";
    
    {
        t1 = steady_clock::now();
        
        using namespace set_list;
        Set A(a), B(b), C(c), D(d), E;
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    }
     
  
    cout<<"======================== bool array\n";
    {
        t1 = steady_clock::now();
        
        using namespace set_array_bool;
        Set A(a), B(b), C(c), D(d), E;
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    } 
    
    cout<<"======================== uint\n";
    {
        t1 = steady_clock::now();
        
        using namespace set_uint;
        Set A(a), B(b), C(c), D(d), E;
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    } 
    
    return 0;
}

#include <random>
char* getRandomStr()
{
    std::string str("0123456789ABCDEF");
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    std::shuffle(str.begin(), str.end(), generator);
    int NewSize = generator() % 16 + 1;
    char* NewStr = new char[NewSize];
    memcpy(NewStr, str.data(), NewSize);
    return NewStr;
}