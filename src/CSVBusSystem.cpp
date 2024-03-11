#include "CSVBusSystem.h"
#include <unordered_map>

//_________________________________________________________________________________________________________________

struct CCSVBusSystem::SImplementation{

    //implementation of SStop(private)
    struct SStop : public CBusSystem::SStop {
        //members:
        TStopID StopID;
        CStreetMap::TNodeID StopNodeID; //this is the node ID associated with stop ID


        //constructor for SStop
        //initializes StopID
        //contains stop ID and associated node ID
        SStop(TStopID stop_id, CStreetMap::TNodeID node_id){
            StopID = stop_id;
            StopNodeID = node_id;
        }

        //destructor for SStop
        ~SStop(){}


        //member functions:

        //returns stop ID
        TStopID ID() const noexcept{
            return StopID;
        }

        //returns node ID associated with the stop
        CStreetMap::TNodeID NodeID() const noexcept{
            return StopNodeID;
        }
    };

    //Implmentation of SRoute (private)
    struct SRoute : public CBusSystem::SRoute {
        std::string RouteName;
        std::vector <TStopID> Stops; //represents a sequential list of stop IDs in the route

        //constructor for SRoute
        //contains route name
        SRoute(std::string route_name){
            RouteName = route_name;
        }

        //destructor for SRoute
        ~SRoute(){}

        //returns name
        std::string Name() const noexcept{
            return RouteName;
        }

        //returns the number of stored stops in the route
        std::size_t StopCount() const noexcept{
            return Stops.size();
        }

        //returns stop ID associated with the given index
        TStopID GetStopID(std::size_t index) const noexcept{
            if(index < Stops.size()) return Stops[index]; //checks to make sure given index is within the bounds of thje Stops vector
            return InvalidStopID;
        }

    };



    //stores stop ID pairs -> stop IDs and corresponding shared ptrs to SStop objects
    //maps from TStopID to std::shared_ptr<CBusSystem::SStop>
    std::unordered_map<TStopID, std::shared_ptr<CBusSystem::SStop>> StopIDMap;

    //sequentially stores stop in bus system
    //stores shared pointers to SStop objects
    std::vector <std::shared_ptr <SStop>> StopList; 

    //stores route-name pairs
    //maps from std::string to std::shared_ptr<SRoute>
    std::unordered_map<std::string, std::shared_ptr<SRoute>> RouteNameMap;

    //sequentially stores route in bus system
    //stores shared ptrs to SRoute objects
    std::vector <std::shared_ptr <SRoute>> RouteList;



    //constructor for SImplementation 
    //does parsing of routesrc and stopsrc
    SImplementation(std::shared_ptr<CDSVReader> stopsrc, std::shared_ptr< CDSVReader > routesrc){
        std::vector <std::string> Row;

        //routesrc parsing_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
        while(routesrc->ReadRow(Row)){
            if(Row.size() < 2) continue; //there needs to be two elements in a row

            std::string name;
            TStopID stop_id;


            //row is considered invalid if name and stop _id assignment fails
            try {
                name = Row[0];
                stop_id = std::stoull(Row[1]);  
            }catch(...){Row = {}; continue; }

            //checks if route already exists
            auto Search = RouteNameMap.find(name);
            if(Search != RouteNameMap.end()){

                //if the route exists, add a stop to the route
                Search->second->Stops.push_back(stop_id);
            }
            else{

                //create new route + stop
                std::shared_ptr NewRoute = std::make_shared<SRoute>(name);
                NewRoute->Stops.push_back(stop_id);

                RouteList.push_back(NewRoute);// add new route to routelist
                RouteNameMap[name] = NewRoute;// add route-name pair to map
            }
            Row = {}; //clear row for next read

        }

        //stopsrc parsing_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
         while(stopsrc->ReadRow(Row)){
            if(Row.size() < 2) continue; //need 2 elements in row
            
            TStopID stop_id;
            CStreetMap::TNodeID node_id;

            //row is considered invalid if stop_id and node_id assignment fails
            try{ 
                stop_id = std::stoull(Row[0]);
                node_id = std::stoull(Row[1]);
            } catch(...){ Row = {}; continue; }

            //new stop + stop id + node id
            std::shared_ptr NewStop = std::make_shared<SStop>(stop_id, node_id);

        
            StopList.push_back(NewStop); //add a stop in stoplist
            StopIDMap[stop_id] = NewStop; //add a stop_id pair in map
            
            Row = {}; // clears row
        }

    }

    //returns number of stops in bus system
    std::size_t StopCount() const noexcept{
        return StopList.size();
    }

    //returns number of routes in bus system
    std::size_t RouteCount() const noexcept{
        return RouteList.size();
    }

    //returns stop at given index
    std::shared_ptr<CBusSystem::SStop> StopByIndex(std::size_t index) const noexcept{
        if(index < StopList.size()) return StopList[index];
        return nullptr;
    }

    //returns stop of given id
    std::shared_ptr<CBusSystem::SStop> StopByID(TStopID id) const noexcept{
        auto Search = StopIDMap.find(id);
        if(Search != StopIDMap.end()) return Search->second;
        return nullptr;
    }

    //returns route at given index
    std::shared_ptr<CBusSystem::SRoute> RouteByIndex(std::size_t index) const noexcept{
        if(index < RouteList.size()) return RouteList[index];
        return nullptr;
    }

    //returns route of given name
    std::shared_ptr<CBusSystem::SRoute> RouteByName(const std::string &name) const noexcept{
        auto Search = RouteNameMap.find(name);
        if(Search != RouteNameMap.end()) return Search->second;
        return nullptr;
    }



};
//____________________________________________________________________________________________________________________________________________


//CCSVBusSystem constructor
CCSVBusSystem::CCSVBusSystem(std::shared_ptr< CDSVReader > stopsrc, std::shared_ptr< CDSVReader > routesrc){
    DImplementation = std::make_unique<SImplementation>(stopsrc, routesrc);
}


//destructor
CCSVBusSystem::~CCSVBusSystem(){}

//callbacks
std::size_t CCSVBusSystem::StopCount() const noexcept{
    return DImplementation->StopCount();
}
std::size_t CCSVBusSystem::RouteCount() const noexcept{
    return DImplementation->RouteCount();
}
std::shared_ptr<CBusSystem::SStop> CCSVBusSystem::StopByIndex(std::size_t index) const noexcept{
    return DImplementation->StopByIndex(index);
}
std::shared_ptr<CBusSystem::SStop> CCSVBusSystem::StopByID(TStopID id) const noexcept{
    return DImplementation->StopByID(id);
}
std::shared_ptr<CBusSystem::SRoute> CCSVBusSystem::RouteByIndex(std::size_t index) const noexcept{
    return DImplementation->RouteByIndex(index);
}
std::shared_ptr<CBusSystem::SRoute> CCSVBusSystem::RouteByName(const std::string &name) const noexcept{
    return DImplementation->RouteByName(name);
}

