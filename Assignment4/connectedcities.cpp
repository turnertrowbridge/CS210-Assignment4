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

/**
 * <p>
 * Part A 
 * ---------------------------------------------------------------------------------------
 * For each city in a city list, find the list of reachable cities starting from the city 
 * following the train routes, and sort the cities in the descending order based on the 
 * number of their reachable cities.  
 * 
 * Required specifications - 
 *
 * Given a list of cities, and a list of one-way train routes from one city to another:
 *
 * 1) Create a graph with each node in the graph as an instance of the CityNode class,
 *    the graph can use any STL collection by your choice.
 *
 * 2) Populate the direct routes information to each CityNode's directRoutedCities collection.
 *    This is like an adjacency list graph representation.
 *
 * 3) For each city node in the graph, use Depth First Search algorithm to find all reachable 
 *    cities starting from the city following the train routes and store those reachable cities to 
 *    the CityNode's reachableCities collection. 
 *
 *    IMPORTANT: The reachable cities must include the starting city itself.  
 *
 *    Note: The train route can go from the starting city and stop at several cities 
 *          before reaching the destination city, all cities including the starting city and 
 *          the destination city along the path would be counted as reachable cities from 
 *          the city where the train starts.
 *
 * 4) Sort the cities in the descending order based on the number of their reachable cities,
 *    so that after sorting, starting from the first city in the sorted order, the train can 
 *    reach the greatest number of destination cities following the given one-way routes. 
 *
 * 5) You must use a RECURSIVE algorithm to implement the Depth First Search part to find
 *    all reachable cities from a starting city given the train routes, using an iterative 
 *    approach would result in a 30% penalty to your assignment 4 grade.  
 *
 * 6) You may add necessary helper functions as needed. Follow the comments for hints.
 * 
 * Assumptions - 
 * 1) Each city is represented by a unique two-letter code like "SD", "LA", 
 *    "SF", "SJ", "NY", etc.
 * 2) Each one-way train route is represented by a pair of city codes; for example, 
 *    route {"SD", "LA"} means train can drive one-way from San Diego (SD) to 
 *    Los Angeles (LA). 
 *
 * <p>
 * Part B
 * ---------------------------------------------------------------------------------------
 * Show the upper bound of the time complexity of this function would be O(c^2 + c * r) 
 * where:
 * c is the number of cities
 * r is the number of direct routes between cities
 * 
 * ---------------------------------------------------------------------------------------
 * @param  cities  a list of cities with each city identified by a two letter code
 * @param  routes  pairs of one-way train routes with each one-way train route represented 
 *                 by a pair of city codes; for example, route {"SD", "LA"} means train 
 *                 can go one-way from San Diego (SD) to Los Angeles (LA).
 *
 *                 NOTE: examples of routes are { {"SD", "LA"},
 *                                                {"LA", "SJ"},
 *                                                {"SJ", "SF"}
 *                                              }   
 *                       refer to driver.cpp for more examples.  
 *
 * @return       A list of CityNode in the descending order based on the number of their 
 *               reachable cities following the train routes
 
* @see         
*/
map<string, CityNode> ConnectedCities::createGraph(vector<string> cities) {
    // create a map containing all cities added using city name as key
    // and an instance of CityNode as value
    map<string, CityNode> cityGraph;
    for (auto city: cities){
        cityGraph.insert({city, CityNode(city)});
    }
    return cityGraph;
}

void ConnectedCities::populateDirectedRoutes(map<string, CityNode> &cityGraph,
                                             vector<pair<string, string>> trainRoutes) {
    // add the adjacent cities to each city
    for (auto city: trainRoutes){
        if (cityGraph.count(city.first) == 1){
//            cout << "added city" << endl;
            cityGraph.at(city.first).addADirectRoutedCity(city.second);
        }
    }

//    //for(auto test1: cityGraph) {
//        for (auto test: cityGraph.at("NH").getDirectRoutedCities()){
//        }
//   // }

}


void ConnectedCities::RecursiveDFS_ToFind_ReachableCities(map<string, CityNode> &cityGraph, string startCity){
    set<string> visitedCities;
    vector<string> reachableCities;
    RecursiveDFS(cityGraph, startCity, reachableCities, visitedCities);
    cityGraph.at(startCity).setReachableCities(reachableCities);
}

void ConnectedCities::RecursiveDFS(map<string, CityNode> &cityGraph, string startCity, vector<string> &reachableCities, set<string> &visitedCities){

//    cout << endl << endl;
//    cout << startCity << endl;

    if(visitedCities.count(startCity)){        // base case: stop if city has already been visited
        return;
    }

    // store the city as reachable and visited
    reachableCities.push_back(startCity);
//    cout << "a city travels to " << startCity << endl;
    visitedCities.insert(startCity);

    // search each adjacentCity
    for(auto adjacentCity: cityGraph.at(startCity).getDirectRoutedCities()) {
            RecursiveDFS(cityGraph, adjacentCity, reachableCities, visitedCities);
    }
}

vector<CityNode> ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(
                                    vector<string> cities, 
                                    vector<pair<string, string>> trainRoutes) {


  // Write your implementation here.
    
  // Follow the steps in the specification above to implement. 

  // You may want to implement each step in the above specification in 
  // a separate function.

  // Think what would be a good data structure to store the City Graph.
  // Each node/vertice represents a city and each has an adjacent list of cities
  // that can be reached directly from the city.
  // You can use a STL collection to store
  // the graph of city nodes, so that given a city code,
  // you can find the corresponding CityNode object instantaneously.
  // Think Which data structure would give you the best lookup ability
  // by using a key.


    map<string, CityNode> cityGraph = createGraph(cities);
    populateDirectedRoutes(cityGraph, trainRoutes);

//    for(auto adjacent : cityGraph.at("SD").getDirectRoutedCities()){
//        cout << "SD Adjacents: " << adjacent << endl;
//    }
//    RecursiveDFS_ToFind_ReachableCities(cityGraph, "SD");
//
//    for(auto adjacent : cityGraph.at("NH").getDirectRoutedCities()){
//        cout << "NH Adjacents: " << adjacent << endl;
//    }
//    RecursiveDFS_ToFind_ReachableCities(cityGraph, "NH");

    for(auto currentCity : cities) {
        cout << currentCity << endl;
        RecursiveDFS_ToFind_ReachableCities(cityGraph, currentCity);

    }
    for(auto city1 : cities) {
        for (auto endCities: cityGraph.at(city1).getReachableCities()) {
            cout << city1 << " can reach " << endCities << endl;
        }
    }

  // Hint for DFS:
  // You may want to use a separate function to implement the 
  // recursive Depth-First-Search algorithm for finding all reachable cities
  // starting from a city using its direct routes to other cities, and their
  // connected cities, and so on and so forth until all cities along
  // reachable paths are traversed.

  // Use the general approach described in zyBook 20.6 Graphs: Depth-first search
  // Follow what Figure 20.6.1 presents

  // A suggested separate recursive function for the DFS part could be:
  // void depthFirstSearchReachableCities(
  //      cityGraph, // a collection of a STL collection type  
  //      string startingCity, 
  //      vector<string> &reachableCities, // list of cities to add reachable cities along the recursive call  
  //      set<string> &visitedCities); // list of cities to track if a city is already visited along DFS search
  // what would be the base condition? --> the startingCity is already visited

  // Hint for sorting: descending order of number of reachable cities and 
  //                   ascending alphabetical order of the city code as the tiebreaker
  // you can leverage the std::sort()
  // one way to do the two-level of sorting here is to first sort the list 
  // by City code in ascending order, 
  // then sort by number of reachable cities in descending order.   

  cout << "the end" << endl;
  return vector<CityNode>(); // vector<CityNode>() here is a placeholder, you need to change it to 
                             // whichever the vector your logic comes up with and return
}



