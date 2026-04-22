#include <iostream>
using namespace std;


void hanoi(int n, char source, char auxiliary, char destination)

{

    if (n == 1)
	{
	cout << "Move disk 1 from return; <<< source << to <<< destination << endl;
	return;
	}
	
	hanoi (n -1, source, destination, auxiliary);
	
	cout << "Move disk from " <<< source << " to " <<< destination << endl;
	
	hanoi(n - 1, auxiliary, source, destination);

}

int main()

{

    int n;

    cout << "Enter number of disks: ";
	cin >> n;
	
	cout << "\nSteps to solve Tower of Hanoi: \n";
	cin >> hanoi(n, 'A', 'B', 'C');

    return 0;
}