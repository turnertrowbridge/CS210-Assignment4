#include <iostream>
#include <set>
#include "connectedcities.h"

/**
 * SINGLE EXAMINEE AFFIDAVIT
*“I, the undersigned, promise that this exam submission is my own work. I recognize that should this not
*be the case; I will be subject to plagiarism penalties as outlined in the course syllabus.”
*Student Name: Turner Trowbridge
*RED ID: 827959204
Date: 11/17/2022
*/

map<string, CityNode> ConnectedCities::createGraph(vector<string> cities) { // O(c)
    // create a map containing all cities added using city name as key
    // and an instance of CityNode as value
    map<string, CityNode> cityGraph;
    for (auto city: cities){
        cityGraph.insert({city, CityNode(city)});
    }
    return cityGraph;
}

void ConnectedCities::populateDirectedRoutes(map<string, CityNode> &cityGraph,
                                             vector<pair<string, string>> trainRoutes) {  // O(c)

    // add the adjacent cities to each city
    for (auto city: trainRoutes){
        if (cityGraph.count(city.first) == 1){
            cityGraph.at(city.first).addADirectRoutedCity(city.second);
        }
    }

}


void ConnectedCities::RecursiveDFS_ToFind_ReachableCities(map<string, CityNode> &cityGraph, string startCity){
    set<string> visitedCities;         // keeps track of all the visited cities in RecursiveDFS
    vector<string> reachableCities;    // keeps track of all the reachable cities for the startCity
    RecursiveDFS(cityGraph, startCity, reachableCities, visitedCities);
    cityGraph.at(startCity).setReachableCities(reachableCities);  // store reachableCities to the
                                                                            // CityNode of startCity in graph
}

void ConnectedCities::RecursiveDFS(map<string, CityNode> &cityGraph, string startCity, vector<string> &reachableCities, set<string> &visitedCities){

    // base case: stop if city has already been visited
    if(visitedCities.count(startCity)){
        return;
    }

    // store the city as reachable and visited
    reachableCities.push_back(startCity);
    visitedCities.insert(startCity);

    // search each adjacentCity
    for(auto adjacentCity: cityGraph.at(startCity).getDirectRoutedCities()) {
            RecursiveDFS(cityGraph, adjacentCity, reachableCities, visitedCities);
    }
}

bool ConnectedCities::sortBy_SizeDesc_And_NameAsc(pair<string, int>& a, pair<string,int>& b){ // O(1)

    // if the numbers are equal, sort by name
    if(a.second == b.second){
       return a.first < b.first;
    }

    //otherwise sort by number
    return a.second > b.second;
}

vector<CityNode> ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(
                                    vector<string> cities, 
                                    vector<pair<string, string>> trainRoutes) {

    // create map for graph and populate it with CityNodes
    map<string, CityNode> cityGraph = createGraph(cities);      // O(c)

    // populate each CityNode in graph with its adjacent nodes
    populateDirectedRoutes(cityGraph, trainRoutes);         // O(c)

    // populate each CityNodes' reachableCities vector using RDFS
    for(auto currentCity : cities) {                                              // O(c)
        RecursiveDFS_ToFind_ReachableCities(cityGraph, currentCity);         // * O(c + r)
    }                                                                                    // = O(c^2 + c * r)

    // create a vector pair storing the name of each city and it's size
    vector<pair<string , int>> cityRouteSize;
    for(auto city1 : cities) {
            cityRouteSize.emplace_back(city1, cityGraph.at(city1).getReachableCities().size());     // O(c)
    }

    // sort function that sorts cityRouteSize by size in descending order, w/ name in ascending if size is equal
    sort(cityRouteSize.begin(), cityRouteSize.end(), sortBy_SizeDesc_And_NameAsc);          // O(c log c)

    // create vector that stores each CityNodes based on the sorted cityRouteSize
    vector<CityNode> cityNodesSorted;
    for(auto city2 : cityRouteSize){                                                          // O(c)
        cityNodesSorted.push_back(cityGraph.at(city2.first));
    }

  return cityNodesSorted; // returns the cityNodes for the graph
}



