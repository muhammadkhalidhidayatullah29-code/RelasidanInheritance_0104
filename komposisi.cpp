#include <iostream>
#include <string>
using namespace std;

#include "jantung.h"
#include "manusia.h"

int main() 
{
    manusia *varManusia = new manusia("Markus");
    
    delete varManusia; // Menambahkan delete untuk membersihkan memori
    return 0;
}