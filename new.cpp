// Include necessary headers
#include <iostream>
#include <fstream> // For file stream operations
using namespace std;

// Function declarations
void readFile(const char fname[], int a[], int &n);
void writeFile(const char fname[], int a[], int n);
void odd(int a[], int n, int mc[], int &nc);

int main()
{
    int a[100], mc[100], n, nc;

    // Read data from file into array 'a'
    readFile("input.txt", a, n);

    // Create an array 'mc' with even numbers from 'a'
    odd(a, n, mc, nc);

    // Write the 'mc' array to an output file
    writeFile("output.txt", mc, nc);
}

// Function to read data from a file into an array
void readFile(const char fname[], int a[], int &n)
{
    ifstream fp(fname); // Create input file stream
    if (!fp.is_open())  // Check if file is opened successfully
    {
        perror("Error opening file");
        return;
    }
    fp >> n; // Read number of elements
    for (int i = 0; i < n; i++)
    {
        fp >> a[i]; // Read array elements
    }
    fp.close(); // Close the file
}

// Function to write data from an array to a file
void writeFile(const char fname[], int a[], int n)
{
    ofstream fp(fname); // Create output file stream
    if (!fp.is_open())  // Check if file is opened successfully
    {
        perror("Error opening file");
        return;
    }
    fp << n << '\n'; // Write number of elements
    for (int i = 0; i < n; i++)
    {
        fp << a[i] << ' '; // Write array elements
    }
    fp.close(); // Close the file
}

// Function to create an array of even numbers from an existing array
void odd(int a[], int n, int mc[], int &nc)
{
    nc = 0; // Initialize count of even numbers
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) // Check if number is even
        {
            mc[nc] = a[i]; // Add even number to the new array
            nc++;          // Increment count of even numbers
        }
    }
}
