#include "DijkstraPathRouter.h"





/*
__________________________________________NOTES________________________________________________________________________

                                  GIVEN CLASS DESCRIPTION

-the CDijkstraPathRouter class will implement the CPathRouter abstract interface

-will find the shortest path between source and destination vertices if one exists

-at the core, the shortest path finding algorithm must utilize Dijkstra's Algorithm, you may optimize whhere avaliable

-The vertex IDs do not have to match the node or stop IDs used by the other classes

-you will need to write a test program for the CDijkstrPathRouter

_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 

                                      NOTES FOR WORK

-will need to rework for SImplementation!!!!!


________________________________________________________________________________________________________________________
*/



//constructor for the Dijkstra Path Router
CDijkstraPathRouter();


//Destructor for the Dijkstra's Path Router
~CDijkstraPathRouter();


//returns the number of vertices in the path router 
std::size_t VertexCount() const noexcept;


//Adds a vertex with the tag provided
//The tag can be of any type
TVertexID AddVertex(std::any tag) noexcept;


//gets the tag of the vertex specified by id if id is in the path router
// a std::any() is returned if id is not a valid vertex ID
std::any GetVertexTag(TVertexID) const noexcept;


//Adds an edge between src and dest vertices with a weight of weight
//If bidir is set to true an additional edge between dest and src is added
//if src or dest nodes do not exist, or if the weight is negative the AddEdge will return false, otherwise it returns true
bool AddEdcge(TVertexID src, TVertexID dest, double weight bool bidir = false) noexcept;


//Allows the path router to do any desired precomputation up to the deadline 
bool Precompute(std::chrono::steady_clock::time_point deadline) noexcept;


//returns the path distance of the path from src to dest, and fills out path with vertices
//if no path exists NoPathExists is returned
double FindShortestPath (TVertexID src, TVertexID dest, std::vector<TVertexID> &path) noexcept;



