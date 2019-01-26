#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

#pragma pack (push, 1)

struct EnvironmentalDegradation
{
    double culturalCost;
    double propertyValue;
    bool bDistanceWithin500Feet;
    double salesTax;
    double revenueFromEventsHosted;
    double numAcresOfParks;
    double numPeopleInCity;
    double runoffReduced;
    double costOfrunoffTreatment;
};

#pragma pack (pop)

int main ()
{
    string fileName = "test.txt";
    EnvironmentalDegradation obj = {};
    //ofstream outputStream;
    ifstream inputStream;

    cout << "Hello World!" << endl;

    //outputStream.open(fileName, ios::binary);
    inputStream.open(fileName, ios::binary);

    //  if (outputStream.is_open()) 
    // {
    //     //outputStream.write (reinterpret_cast<char *>(&obj), sizeof (EnvironmentalDegradation));
    //     outputStream.write ("Hello World!", 12);

    //     outputStream.close();
    // }
    // else 
    // {
    //     cout << "Could not create file:" + fileName;
    // }

    

    if (inputStream.is_open()) 
    {
        //inputStream.read (reinterpret_cast<char *>(&obj), sizeof (double));

        inputStream >> obj.culturalCost;

        cout << obj.culturalCost << endl;

        inputStream.close();
    }
    else 
    {
        cout << "Could not read file:" + fileName;
    }


    return 0;
}