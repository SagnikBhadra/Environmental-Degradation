#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

const double NUM_TREES_TO_REMOVE_CO2 = 42;
const double NUM_TREES_TO_PRODUCE_CO2 = 8;
const double FIVE_PERCENT = 0.05;
const double VALUE_DECREASE_PER_FEET = 4.2;
const double MAX_FEET_AWAY = 3200;
const double RECREATIONAL_VALUE = 150153.04;
const double COMMUNITY_COHESION_BENEFITS = 5.89;
const double PER_ACRE_PARTICULATE_CLEANUP = 4.52;


#pragma pack (push, 1)

struct EnvironmentalDegradation
{
    double totalCost; // T_C

    double provisioningCost; // P
    double priceOfCrop; // P_C
    double numAcresOfFarmland; // P_A

    double regulatoryCost; // R
    double numPeopleImDevelopedArea; // R_P
    double moneySpentOnAirPollution; // R_BD
    double population; // R_POP
    double numOfIndustries; // R_IND
    double numAirPollutionByIndustries; // R_TON
    double avgWaterUsage; // R_AWU
    double co2Generated; // R_CO2G
    double co2Removed; // R_CO2R
    double tippingFee; // R_TF

    double supportingCost; // S
    double costOfO2; // S_O2P
    double numOfTrees; // S_T

    double culturalCost; // C
    double propertyValue; // C_PV
    bool bDistanceWithin500Feet; // C_PD
    double feetAwayFromPark; // C_FA
    double salesTax; // C_ST
    double revenueFromEventsHosted; // C_EF
    double numAcresOfParks; // C_AP
    double numPeopleInCity; // C_PC
    double runoffReduced; // C_RR
    double costOfrunoffTreatment; // C_CT
};

#pragma pack (pop)

int main ()
{
    string fileName = "test.txt";
    EnvironmentalDegradation obj[4];
    string states[4] = {"Illinois", "Virginia", "North Dakota", "California"};
    //ofstream outputStream;
    ifstream inputStream;

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
        for (int i = 0; i < 4; i++)
        {
            inputStream >> obj[i].priceOfCrop >> obj[i].numAcresOfFarmland >> 
                obj[i].numPeopleImDevelopedArea >> obj[i].moneySpentOnAirPollution >> obj[i].population >>
                obj[i].numOfIndustries >> obj[i].numAirPollutionByIndustries >> obj[i].avgWaterUsage >>
                obj[i].co2Generated >> obj[i].co2Removed >> obj[i].tippingFee >>
                obj[i].costOfO2 >> obj[i].numOfTrees >>
                obj[i].propertyValue >> obj[i].bDistanceWithin500Feet >> obj[i].feetAwayFromPark >> 
                obj[i].salesTax >> obj[i].revenueFromEventsHosted >> obj[i].numAcresOfParks >> obj[i].numPeopleInCity >>
                obj[i].runoffReduced >> obj[i].costOfrunoffTreatment;

            obj[i].provisioningCost = obj[i].priceOfCrop * obj[i].numAcresOfFarmland;
            obj[i].regulatoryCost = ((obj[i].moneySpentOnAirPollution / obj[i].population) * obj[i].numPeopleImDevelopedArea) + 
                (obj[i].numPeopleImDevelopedArea * obj[i].avgWaterUsage) + (obj[i].numOfIndustries * (obj[i].moneySpentOnAirPollution / obj[i].numAirPollutionByIndustries)) +
                (obj[i].co2Generated * obj[i].co2Removed) + (obj[i].population * obj[i].tippingFee);
            obj[i].supportingCost = ((obj[i].co2Removed / NUM_TREES_TO_REMOVE_CO2) + (obj[i].costOfO2 / NUM_TREES_TO_PRODUCE_CO2)) * obj[i].numOfTrees;
            obj[i].culturalCost = ((FIVE_PERCENT * obj[i].propertyValue) * obj[i].bDistanceWithin500Feet) + 
                (VALUE_DECREASE_PER_FEET * (MAX_FEET_AWAY - obj[i].feetAwayFromPark)) + obj[i].salesTax + obj[i].revenueFromEventsHosted +
                RECREATIONAL_VALUE + (FIVE_PERCENT * obj[i].numAcresOfParks * obj[i].numPeopleInCity) + 
                (COMMUNITY_COHESION_BENEFITS * obj[i].numPeopleInCity) + (obj[i].runoffReduced * obj[i].costOfrunoffTreatment) + 
                (PER_ACRE_PARTICULATE_CLEANUP * obj[i].numAcresOfParks);

            obj[i].totalCost = obj[i].provisioningCost + obj[i].regulatoryCost + obj[i].supportingCost + obj[i].culturalCost;
        }
        
            cout << "                                          ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << states[i] << setw(8);
            }          
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl;
            cout << " Price Of Crop                            ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].priceOfCrop << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Num Acres Of Farmland                    ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].numAcresOfFarmland << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Num People In Developed Area             ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].numPeopleImDevelopedArea << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Money Spent On Air Pollution             ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].moneySpentOnAirPollution << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " U.S. Population                          ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].population << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Num Of Industries                        ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].numOfIndustries << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Num Air Pollution By Industries          ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].numAirPollutionByIndustries << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Average Water Usage                      "; 
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].avgWaterUsage << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " CO2 Generated                            "; 
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].co2Generated << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " CO2 Removed                              "; 
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].co2Removed << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Tipping Fee                              "; 
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].tippingFee << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Cost Of Generating O2                    "; 
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].costOfO2 << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Num Of Trees                             "; 
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].numOfTrees << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Property Value                           ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].propertyValue << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Park Within 500 Feet                     ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].bDistanceWithin500Feet << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Feet Away From Park                      ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].feetAwayFromPark << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Revenue From Sales Tax                   ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].salesTax << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Revenue From Events Hosted At Parks      ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].revenueFromEventsHosted << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Num Acres Of Parks In City               ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].numAcresOfParks << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Num People In City                       ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].numPeopleInCity << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Water Runoff Reduced By City Parks       ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].runoffReduced << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Cost Of Runoff Treatment                 ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].costOfrunoffTreatment << setw(8);
            }
            cout << endl;
            cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            cout << " Total Cost                               ";
            for (int i = 0; i < 4; i++)
            {
                cout << "|" << setw(13) << obj[i].totalCost << setw(8);
            }
            cout << endl;
            // cout << "__________________________________________|____________________|____________________|____________________|_____________" << endl; 
            // cout << " Total Acres Used for Development Project |" << endl;
            cout << endl;
            
        inputStream.close();
    }
    else 
    {
        cout << "Could not read file:" + fileName;
    }


    return 0;
}