#include "OpenStreetMap.h"
#include <unordered_map>
#include <vector>

//building up from XML files

//______________________________________________________________________________________________
//notes:
/*
-only have to worry about node and way tags and their children
-inplements the CStreetMap abstract interface]
-two structs -> SNode and SWay
-streetmap is a collection of nodes and ways
-each way is a set of nodes that specifies a street path (???)
-the nodes and ways may have attributes that appear in tag elements

*/
//______________________________________________________________________________________________

struct COpenStreetMap::SImplementation {

    //nested struct SNode is inherited from CStreetMap class

    struct SNode : public CStreetMap::SNode {
        //interface for handling attributes and properties of nodes in the OpenStreetMap Data
        ~SNode(){};
        TNodeID ID() const noexcept = override;
        TLocation Location() const noexcept = override;
        std::size_t AttributeCount() const noexcept = override;
        std::string GetAttributeKey(std::size_t index) const noexcept = override;
        bool HasAttribute(const std::string &key) const noexcept = override;
        std::string GetAttribute(const std::string &key) const noexcept = override;
    };

        struct SWay{
        //interface for handling attributes and properties of ways in the OpenStreetMap data
            virtual ~SWay(){};
            virtual TWayID ID() const noexcept = 0;
            virtual std::size_t NodeCount() const noexcept = 0;
            virtual TNodeID GetNodeID(std::size_t index) const noexcept = 0;
            virtual std::size_t AttributeCount() const noexcept = 0;
            virtual std::string GetAttributeKey(std::size_t index) const noexcept = 0;
            virtual bool HasAttribute(const std::string &key) const noexcept = 0;
            virtual std::string GetAttribute(const std::string &key) const noexcept = 0;
        };


        //member variables of the SNode struct -> represents attributes of a node in the OpenStreetMap data
        TNodeID DID;
        TLocation DLocation;
        std::unordered_map<std::string, std::string> DAttributes;
        std::vector<std::string> DAttributeKeys;

        //constructor for SNode
        //initializes DID and DLocation
        SNode(TNodeID id, TLocation loc) {
            DID = id;
            DLocation = loc;
        }

        ~SNode(){} {

        }


     //Functions:


        //returns the ID of the node
        TNodeID ID() const noexcept override{
            return DID;
        }

        //returns the location of the node
        TNodeID Location() const noexcept override{
            return DLocation;
        }


        //returns the number of attributes of the node
        std::size_t AttributeCount() const noexcept override{
            return DAttributeKeys.size();
        }


        //returns the attribute key at the given index
        std::string GetAttributeKey(std::size_t index) const noexcept override {
            if(index < DAttributeKeys.size()){
                return DAttributeKeys[index];
            }
            return std::string();
        }


        //checks if the node has a specific attribute
        bool HasAttribute(const std::string &key) const noexcept override {
            auto Search = DAttributes.find(key);
            return DAttributes.end() != Search;
        }


        //returns the value of a specific attribute of the node
        std::string GetAttribute(const std::string &key) const noexcept override{
            auto Search = DAttributes.find(key);
            if (DAttributes.end( != Search)){
                return Search->second;
            }
            return std::string();
        }

        void SetAttribute(const std::string)
    }

    SImplementation(std::shared_ptr<CXMLReader> src){
        // Node and Way count
        SXMLEntity TempEntity;

        while(src->ReadEntity(TempEntity,true)){
            if((TempEntity.DNameData == "osm") &&(SXMLEntity::EType::EndElement == TempEntity.DType)){
                //Reached end
                break;
            }
            else if ((TempEntity.DNameData == "node") &&(SXMLEntity::EType::StartElement == TempEntity.DType)) {
                // Parse node

            }
            else if(()) {
                // Parse Way
                // Do the same thing for Way? Add the nodes to Way and be able to look it up by reference (id #)
                // Similar structure as Node
            }

        }
    }


    //member functions of SImplementation outside of 'SNode' and 'SWay'
    std::size_t NodeCount() const {

    }

    std::size_t WayCount() const {

    }
    std::shared_ptr<CStreetMap::SNode> NodeByIndex(std::size_t index) const {
        if(index < DNodesByIndex.size()) {
            return DNodesByIndex[index]
        }
    }
}

//____________________________________________________________________________________________________________________________

//constructor for COpenStreetMap Class
COpenStreetMap::COpenStreetMap(std::shared_ptr<CXMLReader> src) {

}

class COpenStreetMap : public CStreetMap{
    private:
        struct SImplementation;
        std::unique_ptr<SImplementation> DImplementation;

    public:
        COpenStreetMap::COpenStreetMap(std::shared_ptr<CXMLReader> src) {

        };
        ~COpenStreetMap() {

        };
        //returns the number of nodes in the OpenStreetMap data
        std::size_t COpenStreetMap::NodeCount() const {
            return DImplementation->NodeCount();
        }
        //returns the number of ways in the OpenStreetMap data
        std::size_t COpenStreetMap::WayCount() const noexcept override {
            return DImplementation ->WayCount();
        };

        //returns a node given its index 
        std::shared_ptr<CStreetMap::SNode> COpenStreetMap::NodeByIndex(std::size_t index) const noexcept override {
            return DImplementation->NodeByIndex(index);
        };

        //returns a node given it's ID
        std::shared_ptr<CStreetMap::SNode> COpenStreetMap::NodeByID(TNodeID id) const noexcept override {
            return DImplementation-> NodeByID(id);
        };

        //returns a way given its index
        std::shared_ptr<CStreetMap::SWay> COpenStreetMap::WayByIndex(std::size_t index) const noexcept override {
            return DImplementation->WayByIndex(index);
        };

        //returns a way given its ID
        std::shared_ptr<CStreetMap::SWay> COpenStreetMap::WayByID(TWayID id) const noexcept override {
            return DImplementation->WayByID(id);
        };
};

#endif