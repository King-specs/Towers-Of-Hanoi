
#include <iostream>
#include <cstdlib>  

//This recursive program solves the Towers of Hanoi problem

using std::cout;
using std::endl;
// src_peg = source peg, dest_peg = destination peg, temp_peg = temporary peg, n_peg = number of pegs


void move(int n_disks, int src_peg, int dest_peg, int temp_peg) {  // recursive function
   /* Program to use a recursive function to solve the Towers of Hanoi problem
   
   //@param argc Number of command-line arguments.
   //@param argv Array of command-line arguments. 
   @return Returns 0 upon successful completion */ 
    if (n_disks == 0) {  // the number of disks to move.
        return;
    }
    //moving the disks
    move(n_disks - 1, src_peg, temp_peg, dest_peg); // temporarily moves the n-1 disks from src_pet to temp_peg
    cout << n_disks << " " << src_peg << "->" << dest_peg << endl; // moves the nth disk
    move(n_disks - 1, temp_peg, dest_peg, src_peg); // temporarily moves the n-1 disks from temp_peg to dest_peg
}
int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number of disks>" << endl;
        return 1;
    }
    // Conversion
    int n_disks = std::atoi(argv[1]);
    // Check to see if the number of disks is a positive integer
    if (n_disks <= 0) {
        std::cerr << "The number of disks must be a positive integer." << endl;
        return 1;
    }
    move(n_disks, 1, 2, 3);  // Move disks from peg 1 to peg 2 using peg 3 as a temporary peg 

    return 0;
}
