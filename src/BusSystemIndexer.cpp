//includes





/*
_________________________________________NOTES___________________________________________________________________________

                                  GIVEN CLASS DESCRIPTION

-this class will index the CBusSystem information provided for ease of lookup of stops and routes

-it will be helpful in the later parts of the project

_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 

                                      NOTES FOR WORK

-will need to rework for SImplementation!!!!!
-

________________________________________________________________________________________________________________________
*/



//constructor for Bus Sytem Indexer
CBusSystemIndexer(std::shared_ptr<CBusSystem> bussystem);


//destructor for Bus System Indexer
~CBusSystemIndexer();




//returns the number of stops in the CBujsSystem being indexed
std::size_t StopCount() const noexcept;


//returns the number of routes in the CBusSystem being indexed
std::size_t RouteCount() const noexcept;


//returns the SStop specified by the index where the stops are sorted by their ID
//nullptr is returned if index is greater than or equal to StopCount()
std::shared_ptr<SStop> SortedStopByIndex(std::size_t index) const noexcept;


//returns the SRoute specified by the index where the routes are sorted by their name
//nullptr is returned if index is greater than or equal to RouteCount()
std::shared_ptr<SRoute> SortedRouteByIndex(std::size_t index) const noexcept;


//returns the SStop associated with the specified node ID
//nullptr is returned if no SStop associated with the node ID exists
std::shared_ptr<SStop> StopByNodeID (TNode id) const noexcept;


//returns true if at least one route exists between the stops at the src and dest node IDs
//All routes that have a route segment between the stops at the src and the dest nodes will be placed in routes unordered set
bool RoutesByNodeIDs (TNodeID src, TNodeID dest, std::unordered_set<std::shared_ptr<SRoute>> &routes) const noexcept;


//returns true if at least one route exists between the stops at the src and dest node IDs
bool RouteBetweenNodeIDs(TNodeID src, TNodeID dest) const noexcept;



