/*
    열혈CPP 문제 #01-3
    
    @ MjölkforDunk
*/

#include <iostream>
using std::cout;
using std::endl;

// pre-decl
int BoxVolume (int length, int width, int height); // 3 3 3
int BoxVolume (int length, int width);             // 5 5 D
int BoxVolume (int length);                        // 7 D D


/// MAIN
//  ========================================
int main ()
{
    cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
    cout << "[5, 5, D] : " << BoxVolume(5, 5)    << endl;
    cout << "[7, D, D] : " << BoxVolume(7)       << endl;

    return 0xDEADBEEF;
}


/// FUNC
//  ========================================
int BoxVolume (int length, int width, int height)
{
    return length * width * height;
}

int BoxVolume (int length, int width)
{
    return length * width;
}

int BoxVolume (int length)
{
    return length;
}