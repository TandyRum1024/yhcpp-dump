/*
    열혈CPP 문제 #01-3

    @ MjölkforDunk
*/
#include <iostream>
using std::cout;
using std::endl;

// Default param version
int SimpleFunc (int a = 10)
{
    return a + 1;
}
// Void version
int SimpleFunc ( void )
{
    return 10;
}


/// MAIN
//  ========================================
int main ()
{
    cout << "Def. Param : " << SimpleFunc( 42 );

    // SimpleFunc() will call both :
    // SimpleFunc( void );
    // SimpleFunc( int a = 10 );
    // So this is fucking bad and you should avoid this kind of overloading.
    // cout << "This will make error : " << SimpleFunc(); 

    return 0xDEADBEEF;
}