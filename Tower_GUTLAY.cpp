#include <iostream>
#include <cmath>
using namespace std;

// Function to move a disk between two pegs
void moveDisk(char from, char to, int disk) {
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    char A = 'A', B = 'B', C = 'C';

    // If number of disks is even, swap destination and auxiliary
    if (n % 2 == 0) {
        char temp = B;
        B = C;
        C = temp;
    }

    int totalMoves = pow(2, n) - 1;

    // Initialize rods (arrays to simulate stacks)
    int source[100], auxiliary[100], destination[100];
    int topA = n - 1, topB = -1, topC = -1;

    // Fill source rod
    for (int i = 0; i < n; i++)
        source[i] = n - i;

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            // Move between A and C
            if (topA == -1 || (topC != -1 && destination[topC] < source[topA])) {
                source[++topA] = destination[topC--];
                moveDisk(C, A, source[topA]);
            } else {
                destination[++topC] = source[topA--];
                moveDisk(A, C, destination[topC]);
            }
        }
        else if (i % 3 == 2) {
            // Move between A and B
            if (topA == -1 || (topB != -1 && auxiliary[topB] < source[topA])) {
                source[++topA] = auxiliary[topB--];
                moveDisk(B, A, source[topA]);
            } else {
                auxiliary[++topB] = source[topA--];
                moveDisk(A, B, auxiliary[topB]);
            }
        }
        else if (i % 3 == 0) {
            // Move between B and C
            if (topB == -1 || (topC != -1 && destination[topC] < auxiliary[topB])) {
                auxiliary[++topB] = destination[topC--];
                moveDisk(C, B, auxiliary[topB]);
            } else {
                destination[++topC] = auxiliary[topB--];
                moveDisk(B, C, destination[topC]);
            }
        }
    }


}