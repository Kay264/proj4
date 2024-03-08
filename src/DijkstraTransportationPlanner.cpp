//includes





/*
_________________________________________NOTES___________________________________________________________________________

                                  GIVEN CLASS DESCRIPTION

-the CDijkstraTransportationPlanner class will implement the CTransportationPlanner abstract inface

-You will build upon the street map, bus system, bus system indexer, and path router to implement the transportation planner

-The configuration of the transportation system will be provided as a parameter to the constructor
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 

                                      NOTES FOR WORK

-will need to rework for SImplementation!!!!!

________________________________________________________________________________________________________________________
*/


//Constructor for the Dijkstra Transportation Planner
CDijkstraTransportationPlanner(std::shared_ptr<SConfiguration> config);


//Destructor for the Dijkstra Transportation Planner
~CDijkstraTransportationPlanner();


//Returns the number of nodes in the street map
std::size_t NodeCount() const noexcept override;


//returns the street map node specified by index if index is less than the NodeCount()
//nullptr is returned if index is greater than or equal to NodeCount()
//The nodes are sorted by Node ID
std::shared_ptr<CStreetMap::SNode> SortedNodeByIndex(std::size_t index) const noexcept override;


//returns the distance in miles between the src and dest nodes of the shortest path if one exists
//NoPathExists is returned if no path exists
//The nodes of the shortest path are filled in the path parameter
double FindShortestPath(TNodeID src, TNode dest, std::vector< TNodeID > &Path) override;


//returns the time in hours for the fastest path between the src and dest
//nodes of the if one exists
//NoPathExists is returned if no path exists
//The transportation mode and nodes of the fastest path are filled in the path parameter
double FindFastestPath(TNodeID src, TNode dest, std::vector< TTripStep > &path) override;


//returns true if the path description is created
//takes the trip steps path and converrts it into a human readable set of steps
bool GetPathDescription(const std::vector< TTripStep > &path, std::vector< std::string > &desc) const override;

