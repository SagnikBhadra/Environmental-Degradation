#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

const double NUM_TREES_TO_REMOVE_CO2 = 42;
const double NUM_TREES_TO_PRODUCE_CO2 = 8;
const double FIVE_PERCENT = 0.05;
const double VALUE_DECREASE_PER_FEET = 4.2;
const double MAX_FEET_AWAY = 3200;
const double RECREATIONAL_VALUE = 150,153.04;
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

        inputStream >> obj.priceOfCrop >> obj.numAcresOfFarmland >> 
            obj.numPeopleImDevelopedArea >> obj.moneySpentOnAirPollution >> population >>
            obj.numOfIndustries >> obj.numAirPollutionByIndustries >> obj.avgWaterUsage >>
            obj.co2Generated >> obj.co2Removed >> obj.tippingFee >>
            obj.costOfO2 >> obj.numOfTrees >>
            obj.propertyValue >> obj.bDistanceWithin500Feet >> obj.feetAwayFromPark >> 
            obj.salesTax >> obj.revenueFromEventsHosted >> obj.numAcresOfParks >> obj.numPeopleInCity >>
            obj.runoffReduced >> obj.costOfrunoffTreatment;

        obj.provisioningCost = obj.priceOfCrop * obj.numAcresOfFarmland;
        obj.regulatoryCost = ((obj.moneySpentOnAirPollution / obj.population) * obj.numPeopleImDevelopedArea) + 
            (obj.numPeopleImDevelopedArea * obj.avgWaterUsage) + (obj.numOfIndustries * (obj.moneySpentOnAirPollution / obj.numAirPollutionByIndustries)) +
            (obj.co2Generated * obj.co2Removed) + (obj.population * obj.tippingFee);
        obj.supportingCost = ((obj.co2Removed / NUM_TREES_TO_REMOVE_CO2) + (obj.costOfO2 / NUM_TREES_TO_PRODUCE_CO2)) * obj.numOfTrees;
        obj.culturalCost = ((FIVE_PERCENT * obj.propertyValue) * obj.bDistanceWithin500Feet) + 
            (VALUE_DECREASE_PER_FEET * (MAX_FEET_AWAY - obj.feetAwayFromPark)) + obj.salesTax + obj.revenueFromEventsHosted +
            RECREATIONAL_VALUE + (FIVE_PERCENT * obj.numAcresOfParks * obj.numPeopleInCity) + 
            (COMMUNITY_COHESION_BENEFITS * obj.numPeopleInCity) + (obj.runoffReduced * obj.costOfrunoffTreatment) + 
            (PER_ACRE_PARTICULATE_CLEANUP * obj.numAcresOfParks);

            obj.totalCost = obj.provisioningCost + obj.regulatoryCost + obj.supportingCost + obj.culturalCost;
        inputStream.close();
    }
    else 
    {
        cout << "Could not read file:" + fileName;
    }


    return 0;
}