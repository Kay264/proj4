#include "DSVReader.h"
#include <expat.h>
#include <queue>
#include <vector>

struct CDSVReader::SImplementation{
    std::shared_ptr<CDataSource> dataSource;
    char delim;

    SImplementation(std::shared_ptr<CDataSource> src, char delimiter) {
        dataSource = src;
        delim = delimiter;
    }

    bool End() const {
        // Returns true if all rows have been read from the DSV
        if (dataSource->End()) {
            return true;
        };
        return false;
    };

    bool ReadRow(std::vector<std::string>&row) {
        // Returns true if the row is successfully read, one string will be put in
        // the row per column

        // TEST(DSVReader, ReadRow) {
        // auto Source = std::make_shared<CStringDataSource>("Hello&World!");
        // CDSVReader Reader(Source,'&');
        // std::vector<std::string> output;

        // EXPECT_TRUE(Reader.ReadRow(output));
        // ASSERT_EQ(output.size(),2);
        // EXPECT_EQ(output[0],"Hello");
        // EXPECT_EQ(output[1],"World!");
      
    };
    };

CDSVReader::CDSVReader(std::shared_ptr< CDataSource > src, char delimiter){
    DImplementation = std::make_unique<SImplementation> (src,delimiter);
};

CDSVReader::~CDSVReader(){

};

bool CDSVReader::ReadRow(std::vector<std::string> &row) {
    return DImplementation -> ReadRow(row);
};

bool CDSVReader::End() const {
    return DImplementation->End();
}