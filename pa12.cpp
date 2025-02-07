/**
 * @file pa12.cpp
 * @author Daniel O'Neill
 * @date 9/25/2024
 * @section 1003
 *
 * @note I pledge my word of honor that I have abided by the
 * CSN Academic Integrity Policy while completing this assignment.
 *
 * @brief this program takes any number of  values for a rocket launch and
 * finds the largenst and smallest intervals for the rocket launce. It also
 * finds the time it took and outputs the informatin.
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#include "Vector.h"
// prototypes
int shortest(Vector& copy);
int longest(Vector& copy);
int time(Vector& copy);
void output(Vector& copy);

int main() {
    using namespace std;
    Vector vector;
    int value;  // value being passed to push_back

    cin >> value;
    vector.push_back(value);

    while (vector.back() != -1)
    {
        cin >> value;
        vector.push_back(value);
    }

    output(vector);
}

/**
 * @param copy is a refrence to the class
 * @brief gets the smallest interval in array
 */
int shortest(Vector& copy)
{
    int small = 10000;  // setting a value
    int comp = 0;                            // copmarison
    int comp2 = 0;                           // comparison
    int compf = 0;                           // comparison

    for (size_t i = 0; i < copy.size() - 1; i++)
    {
        if (i > 0)
        {
            comp = copy.at(i);
            comp2 = copy.at(i - 1);
            compf = comp - comp2;
        }
        if (i > 0 && small > compf)
        {
            small = compf;
        }
    }
    return small;
}

/**
 * @param copy is a refrence to the class
 * @brief gets the largest interval in array
 */
int longest(Vector& copy)
{
    int larg = 0;                            // setting a value
    int comp = 0;                            // copmarison
    int comp2 = 0;                           // comparison
    int compf = 0;                           // comparison

    for (size_t i = 0; i < copy.size() - 1; i++)
    {
        if (i > 0)
        {
            comp = copy.at(i);
            comp2 = copy.at(i - 1);
            compf = comp - comp2;
        }
        if (larg < compf)
        {
            larg = compf;
        }
    }
    return larg;
}

/**
 * @param copy is a refrence to the class
 * @brief gets the total time of the event
 */
int time(Vector& copy)
{
    int time = 0;   // The total time of event
    int last = 0;   // last input
    int first = 0;  // fist input

    for (size_t i = 0; i < copy.size() - 1; i++)
    {
        if (i == 0)
        {
            first =copy.at(i);
        }
        last = copy.at(i);
    }

    time = last - first;

    return time;
}

/**
 * @param copy is a refrence to the class
 * @brief formats and outputs the array
 */
void output(Vector& copy)
{
    using namespace std;
    cout << fixed << showpoint << setprecision(1);  // Formating

    cout << "Total Thruster Burns: " << setw(2) << copy.size() -1 << endl;
    cout << "Shortest Interval: " << setw(6) << shortest(copy) << endl;
    cout << "Longest Interval: " << setw(8) << longest(copy) << endl;
    cout << "Total Time Span: " << setw(9) << time(copy) << endl;

}
