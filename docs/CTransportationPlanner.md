# Transportation Planner Doccumentation

## Included

- "StreetMap.h"

- "BusSystem.h"

- "PathRouter.h"

## Members

- TNodeID is an alias for CStreetMap::TNodeID -> identifies nodes in the street map

- ETransportationMode is an enum class representing different transportation modes: Walk, Bike, and Bus

- TTripStep is a pair consisting of a transportation mode and a node ID -> used to represent steps in a trip

- SConfiguration struct declares a set of pure virtual functions: StreetMap, BusSystem, WalkSpeed, BikeSpeed, DefaultSpeedLimit, BusStopTime, PrecomputeTime

- NodeCount returns the number of nodes

- SortedNodeByIndex returns the node at the specified index

- FindShortestPath returns a vector of node IDs representing the shortest path

- FindFastestPath returns the vector of trip steps representing the fastest path

- GetPathDescription retrieves a textual description of a path given the trip steps