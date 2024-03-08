#include "XMLWriter.h"
#include <expat.h>
#include <queue>


//most recent edits: 3/5/24 @ 1:00

//constructor
CXMLWriter::CXMLWriter(std::shared_ptr<CDataSink> sink) {
    DImplementation = std::make_unique<SImplementation>(sink); 
}


//______________________________________________SImplemmentation_______________________________________________________________________

//implementation of SImplementation specifically for CXMLWriter class
struct CXMLWriter::SImplementation{
    std::shared_ptr<CDataSink> DSink;  //shared ptr to data sink
    std::queue<SXMLEntity> DEndElementQueue;  //queue to store elements that have been started

    //constructor
    SImplementation(std::shared_ptr<CDataSink> sink) : DSink(sink) {}



    //Outputs all end elements that have been started
    bool Flush() {
        while(!DEndElementQueue.empty()){     //if the queue is not empty...
            auto entity = DEndElementQueue.front(); //entity is now the front element of the queue, which is then removed from the queue
            DEndElementQueue.pop();

            if (entity.DType == SXMLEntity::EType::EndElement) {  //checks if the SXMLEntity is an end element
                std::vector<char> buf; //a vector of characters is made and characters '<' and '/' are pushed into it
                buf.push_back('<');
                buf.push_back('/');

                for (auto it = entity.DNameData.begin(); it != entity.DNameData.end(); ++it){ //iterates over the characters in the name data of the entity
                    buf.push_back(*it);                                                       //each character is pushed into the buf, this represents the tag name
                }
                buf.push_back('>'); //pushes the closing bracket

                if(!DSink->WriteRow(buf)){ //writes the contents of the buf vector to the DSink, returns false if it fails
                    return false; 
                }
            
            }
        }
        return true; 
    }
        /*work in progress...
        
        //Write all end elements to the data sink
        while (!DEndElementQueue.empty()){                    //if the queue has elements...
            SXMLEntity entity = DEndElementQueue.front();     //the first element of the queue is assigned to entity
            if (!DSink->WriteRow(entity.DAttributes)){
                return false; //couldn't write to data sink
            }
            DEndElementQueue.pop();
        }
        return true;
        */
       //return false;
    




    //writes given XML Entity to the output stream
    bool WriteEntity(const SXMLEntity &entity) {
        if (entity.DType == SXMLEntity::EType::StartElement) {
            DEndElementQueue.push(entity);
        } else if (entity.DType == SXMLEntity::EType::EndElement) {
            if (!DEndElementQueue.empty() && DEndElementQueue.back().DNameData == entity.DNameData) {
                DEndElementQueue.pop();
            } else {
                // Trying to end a non-existing element -> ERROR
                return false;
            }
        }

        //write entity directly
        std::vector<char> buf;
        buf.push_back('<');
        for (auto it = entity.DNameData.begin(); it != entity.DNameData.end(); ++it) {
            buf.push_back(*it);
        }
        for (auto it = entity.DAttributes.begin(); it != entity.DAttributes.end(); ++it) {
            buf.push_back(' ');
            for (auto attr_it = it->first.begin(); attr_it != it->first.end(); ++attr_it) {
                buf.push_back(*attr_it);
            }
            buf.push_back('=');
            buf.push_back('"');
            for(auto attr_it = it->second.begin(); attr_it != it->second.end(); ++attr_it) {
                buf.push_back(*attr_it);
            }
            buf.push_back('"');
        }
        if (entity.DType == SXMLEntity::EType::CompleteElement) {
            buf.push_back('/');
        }
        buf.push_back('>');
        if (!DSink->WriteRow(buf)) {
            return false;  //Failed to write 
        }
        return true;
    }

        /* work in progress...

        //writes the entity to the data sink
        if (!DSink->WriteRow(entity)) {
            return false; //unable to write to the data sink

        }

        //if start element, push to the end element queue
        if (entity.DType == SXMLEntity::EType::StartElement) {
            DEndElementQueue.push(entity);
        }
        //if end element, pop corresponding end element from queue
        else if (entity.DType == SXMLEntity::EType::EndElement) {
            if (!DEndElementQueue.empty()) {
                DEndElementQueue.pop();
            }
            else{
                //no corresponding start element in the queue
                return false;
            }
        }

        return true;
        */
    };

  




//________________________________________End_of_SImplmentation______________________________________________________________________________

//destructor
CXMLWriter::~CXMLWriter(){

}


//outputs all end elements for those that have been started
bool CXMLWriter::Flush(){
    return DImplementation->Flush();
}


//writes out the entity to the output stream
bool CXMLWriter::WriteEntity(const SXMLEntity &entity){
    return DImplementation->WriteEntity(entity);
}


