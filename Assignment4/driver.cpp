/**
 * Start of a driver file to test orgtree.cpp
 * CS 210 Fall 2022
 * @author Mitchell Shapiro <mshapiro6805@sdsu.edu>
 * @date Nov 2022
 */

#include "connectedcities.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * THIS DRIVER FILE IS ONLY A START!
 * IT IS CRITICAL THAT YOU ADD YOUR
 * OWN TEST CASES. MOST CASES ARE
 * HIDDEN ON GRADESCOPE.
 */

/**
 * Print whether the given test case passed or failed
 * @param didPass - The test condition (true to pass, false to fail)
 * @param message - Description of what is being tested
 */
void asserts(bool didPass, string message) {
    if (didPass) {
        cout << "Passed: " << message << endl;
    } else {
        cout << "FAILED: " << message << endl;
        // Halts execution, comment out to
        // continue testing other parts
		// If you do comment this out, ignore the
		// "All test cases passed!" printout
        exit(EXIT_FAILURE);
    }
}

//TODO
int main(int argc, char **argv) {
    
    // Begin Testing
    // A few sample testing code are provided below  
    
    /* Construct a graph for testing
        *    SD ---> DL <--------
        *    ^                   |
        *    |                   |
        *    OD <--- JL <--------|--
        *                        |  |
        *    BV <---             |  |
        *    --->  LA ---> BU    |  |
        *          ^             |  |
        *          |             |  |
        *  SJ ---> SK ---> IV ---|  |
        *                           |
        *  <---------------         |
        *  SF ---> HT ---> NH ------|
        * */

    vector<string> cities_1 {"SD", "LA", "SK", "IV", "JL", "SF", 
                             "DL", "HT", "OD", "NH", "BV", "SJ", "BU"};

    vector<pair<string, string>> trainRoutes;

    trainRoutes.emplace_back("JL", "OD");
    trainRoutes.emplace_back("OD", "SD");
    trainRoutes.emplace_back("SD", "DL");
    trainRoutes.emplace_back("BV", "LA");
    trainRoutes.emplace_back("LA", "BV");
    trainRoutes.emplace_back("LA", "BU");
    trainRoutes.emplace_back("SK", "IV");
    trainRoutes.emplace_back("SK", "LA");
    trainRoutes.emplace_back("SJ", "SK");

    trainRoutes.emplace_back("IV", "DL");
    
    trainRoutes.emplace_back("SF", "HT");
    trainRoutes.emplace_back("HT", "NH");
    trainRoutes.emplace_back("NH", "SF");
    trainRoutes.emplace_back("NH", "JL");

    vector<CityNode> cities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_1, trainRoutes);

    //cities returned from the above call are sorted according to 
    //the ascending order of the city names and 
    //the descending order of the size of reachableCities starting from those cities
    
    asserts(cities.at(0).getCity() == "HT", "First city should be HT");
    //Reachable cities from HT are [HT, NH, SF, JL, OD, SD, DL]
    asserts(cities.at(0).getReachableCities().size() == 7, "Train starting from city HT can reach 7 cities"); 
    
    asserts(cities.at(1).getCity() == "NH", "Second city should be NH");
    //Reachable cities from NH are [NH, SF, HT, JL, OD, SD, DL]
    asserts(cities.at(1).getReachableCities().size() == 7, "Train starting from city NH can reach 7 cities");
    
    asserts(cities.at(2).getCity() == "SF", "Third city should be SF");
    //Reachable cities from SF are [SF, HT, NH, JL, OD, SD, DL]
    asserts(cities.at(2).getReachableCities().size() == 7, "Train starting from city SF can reach 7 cities");
    
    asserts(cities.at(3).getCity() == "SJ", "Fourth city should be SJ");
    //Reachable cities from SJ are [SJ, SK, IV, DL, LA, BV, BU]
    asserts(cities.at(3).getReachableCities().size() == 7, "Train starting from city SJ can reach 7 cities");

    asserts(cities.at(4).getCity() == "SK", "Fifth city should be SK");
    //Reachable cities from SK are [SK, IV, DL, LA, BV, BU]
    asserts(cities.at(4).getReachableCities().size() == 6, "Train starting from city SK can reach 6 cities");
    
    asserts(cities.at(5).getCity() == "JL", "Sixth city should be JL");
    //Reachable cities from JL are [JL, OD, SD, DL]
    asserts(cities.at(5).getReachableCities().size() == 4, "Train starting from city JL can reach 4 cities");
    
    asserts(cities.at(6).getCity() == "BV", "Seventh city should be BV");
    //Reachable cities from BV are [BV, LA, BU]
    asserts(cities.at(6).getReachableCities().size() == 3, "Train starting from city BV can reach 3 cities");
        
    asserts(cities.at(7).getCity() == "LA", "Eighth city should be LA");
    //Reachable cities from LA are [LA, BV, BU]
    asserts(cities.at(7).getReachableCities().size() == 3, "Train starting from city LA can reach 3 cities");

    asserts(cities.at(8).getCity() == "OD", "Ninth city should be OD");
    //Reachable cities from OD are [OD, SD, DL]
    asserts(cities.at(8).getReachableCities().size() == 3, "Train starting from city OD can reach 3 cities");

    asserts(cities.at(11).getCity() == "BU", "Twelfth city should be BU");
    //Reachable cities from BU are [BU]
    asserts(cities.at(11).getReachableCities().size() == 1, "Train starting from city BU can reach 1 city");

    // IMPORTANT:
    // TODO: write your own testing code similar to above as part of the coding required for assignment 4




    // IMPORTANT: You should construct at least one different city graph similar to the one above
    //
    // Also make sure to construct graphs for testing the edge cases, 
    // such as empty graph (NO node), one node graph, two nodes graph, etc.


    /* Test case with no nodes */
    cout << "\n\n***No nodes test***" << endl;

    vector<string> cities_2 {};
    vector<pair<string, string>> trainRoutes2;

    vector<CityNode> cities2Nodes = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_2, trainRoutes2);

    // No reachable cities
    asserts(cities2Nodes.empty(), "There should be no trains");



    /* Test case with 1 node */
    cout << "\n\n***1 node test***" << endl;

    vector<string> cities_3 {"SD"};
    vector<pair<string, string>> trainRoutes3;

    vector<CityNode> cities3Nodes = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_3, trainRoutes3);

    asserts(cities3Nodes.at(0).getCity() == "SD", "First city should be SD");
    //Reachable cities from SD are [SD]
    asserts(cities3Nodes.at(0).getReachableCities().size() == 1, "Train starting from city SD can reach 1 city");

    /* Test case with 2 nodes */

    /*
     *        LA -----> SD
     *          <------
     */

    vector<string> cities_4 {"SD", "LA"};
    vector<pair<string, string>> trainRoutes4;

    trainRoutes4.emplace_back("LA", "SD");
    trainRoutes4.emplace_back("SD", "LA");

    vector<CityNode> cities4Nodes = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_4, trainRoutes4);

    asserts(cities4Nodes.at(0).getCity() == "LA", "First city should be LA");
    //Reachable cities from LA are [LA,SD]
    asserts(cities4Nodes.at(0).getReachableCities().size() == 2, "Train starting from city LA can reach 2 cities");

    asserts(cities4Nodes.at(1).getCity() == "SD", "First city should be SD");
    //Reachable cities from SD are [SD,LA]
    asserts(cities4Nodes.at(1).getReachableCities().size() == 2, "Train starting from city SD can reach 1 cities");


    /* Test case with multiple nodes */
    cout << "\n\n***Multi-node test with 2/3 letter keys & disconnected graph***" << endl;

    /*
     *
     *    DEN --------> CHI ----> NY---|
     *    ^                     ^      |
     *    |                     |      |
     *    |                     NO <---|
     *    |                     ^
     *    |  <------            |
     *    LA -----> SD -------> DAL
     *     ^        ^           |
     *     |        |           |
     *     |-----|--|           |
     *           |              |
     *           |- SF <--- SA<-|
     *
     *
     *
     *      LDN -----> PAR
     *

     */

    vector<string> cities_5 {"DEN","CHI","NY","NO","DAL","SA","SF","SD","LA", "LDN", "PAR"};
    vector<pair<string, string>> trainRoutes5;

    trainRoutes5.emplace_back("LA", "SD");
    trainRoutes5.emplace_back("LA", "DEN");
    trainRoutes5.emplace_back("SD", "LA");
    trainRoutes5.emplace_back("DEN", "CHI");
    trainRoutes5.emplace_back("CHI", "NY");
    trainRoutes5.emplace_back("SD", "DAL");
    trainRoutes5.emplace_back("DAL", "NO");
    trainRoutes5.emplace_back("NO", "NY");
    trainRoutes5.emplace_back("DAL", "SA");
    trainRoutes5.emplace_back("SA", "SF");
    trainRoutes5.emplace_back("SF", "SD");
    trainRoutes5.emplace_back("SF", "LA");
    trainRoutes5.emplace_back("NY", "NO");
    trainRoutes5.emplace_back("LDN", "PAR");


    vector<CityNode> cities5Nodes = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_5, trainRoutes5);

    asserts(cities5Nodes.at(0).getCity() == "DAL", "First city should be DAL");
    //Reachable cities from DAL are [DAL,SA,SF,SD,LA,DEN,CHI,NY,NO]
    asserts(cities5Nodes.at(0).getReachableCities().size() == 9, "Train starting from city DAL can reach 9 cities");

    asserts(cities5Nodes.at(1).getCity() == "LA", "Second city should be LA");
    //Reachable cities from LA are [LA,SD,DAL,SA,SF,DEN,CHI,NY,NO]
    asserts(cities5Nodes.at(1).getReachableCities().size() == 9, "Train starting from city LA can reach 9 cities");

    asserts(cities5Nodes.at(2).getCity() == "SA", "Third city should be SA");
    //Reachable cities from SA are [SA,SF,SD,LA,DEN,CHI,NY,NO,DAL]
    asserts(cities5Nodes.at(2).getReachableCities().size() == 9, "Train starting from city SA can reach 9 cities");

    asserts(cities5Nodes.at(3).getCity() == "SD", "Fourth city should be SD");
    //Reachable cities from SA are [SD,LA,DEN,CHI,NY,NO,DAL,SA,SF]
    asserts(cities5Nodes.at(3).getReachableCities().size() == 9, "Train starting from city SD can reach 9 cities");

    asserts(cities5Nodes.at(4).getCity() == "SF", "Fifth city should be SF");
    //Reachable cities from SF are [SF,SD,LA,DEN,CHI,NY,NO,DAL,SA]
    asserts(cities5Nodes.at(4).getReachableCities().size() == 9, "Train starting from city SF can reach 9 cities");

    asserts(cities5Nodes.at(5).getCity() == "DEN", "Sixth city should be DEN");
    //Reachable cities from DEN are [DEN,CHI,NY,NO]
    asserts(cities5Nodes.at(5).getReachableCities().size() == 4, "Train starting from city DEN can reach 4 cities");

    asserts(cities5Nodes.at(6).getCity() == "CHI", "Seventh city should be CHI");
    //Reachable cities from CHI are [CHI,NY,NO]
    asserts(cities5Nodes.at(6).getReachableCities().size() == 3, "Train starting from city CHI can reach 3 cities");

    asserts(cities5Nodes.at(7).getCity() == "LDN", "Eight city should be LDN");
    //Reachable cities from LDN are [LDN,PAR]
    asserts(cities5Nodes.at(7).getReachableCities().size() == 2, "Train starting from city LDN can reach 2 cities");

    asserts(cities5Nodes.at(8).getCity() == "NO", "Ninth city should be NO");
    //Reachable cities from NO are [NO,NY]
    asserts(cities5Nodes.at(8).getReachableCities().size() == 2, "Train starting from city NO can reach 2 cities");

    asserts(cities5Nodes.at(9).getCity() == "NY", "Tenth city should be NY");
    //Reachable cities from NY are [NY,NO]
    asserts(cities5Nodes.at(9).getReachableCities().size() == 2, "Train starting from city NY can reach 2 cities");

    asserts(cities5Nodes.at(10).getCity() == "PAR", "Eleventh city should be PAR");
    //Reachable cities from PAR are [PAR]
    asserts(cities5Nodes.at(10).getReachableCities().size() == 1, "Train starting from city PAR can reach 1 cities");

    cout << endl << "All test cases passed!" << endl;
    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}