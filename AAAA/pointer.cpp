#include <iostream>
using namespace std;
void putSomethingAtChangedMemoryLocation(int& memLoc) {
    float* point = new float[9];

    point[3] = 3.14159265;

    memLoc = reinterpret_cast<int>(point);
    cout << "\nNew point: " << hex << point << "\n^ casted to int then cout hex: " << memLoc;

    point = reinterpret_cast<float*>(memLoc);
    cout << "\nNew point casted to int then float*: " << hex << point;
}

int main() {
    int memoryLocation = 0;

    cout << "\nOld Loc: " << memoryLocation;

    putSomethingAtChangedMemoryLocation(memoryLocation);

    cout << "\nNew Loc: " << memoryLocation
        << "\nTestnumber: " << *(reinterpret_cast<float*>(memoryLocation) + 3) << endl;
    return 0;
}
/*
void putSomethingAtChangedMemoryLocation(float *&memLoc) { //I could kiss post #2 "(remember, read pointers right to left. Here, ptrRef is a reference to a pointer to a float type)"
	memLoc = new float[10];
	memLoc[0] = 99.21;

}

int main() {
	float* memoryLocation = new float;
	memoryLocation[0] = 12.3;
	cout << "\nold Loc: " << memoryLocation;

	putSomethingAtChangedMemoryLocation(memoryLocation);

	cout << "\nnew Loc: " << memoryLocation;
	return 0;
}
*/