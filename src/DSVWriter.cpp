#include "DSVReader.h"
#include "DSVWriter.h"
#include "StringDataSink.h"
#include <expat.h>
#include <queue>

struct CDSVWriter::SImplementation{
    std::shared_ptr<CDataSink> dataSink;
    char delim;
    bool quote;

    SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall) {
        //Details here
        dataSink = sink;
        delim = delimiter;
        quote = quoteall;
    }

    bool WriteRow(const std::vector<std::string> &row){
        // Returns true if the row is successfully written, one string per column
        // should be put in the row vector

        // TEST(DSVWriter, WriteRow) {
        // auto Sink = std::make_shared<CStringDataSink>();
        // CDSVWriter Writer(Sink,'&');
        // std::vector<std::string> input = {"Hello", "World!"};

        // EXPECT_TRUE(Writer.WriteRow(input));
        // EXPECT_EQ(Sink->String(),"Hello&World!");

        std::string temp;
        char character;

        if (row.size() == 0) {
            return false;
        }
        for (int index = 0; index < row.size(); index++) {
            for (int index_2 = 0; index_2 < row[index].length(); index_2++) {
                character = row[index][index_2];
                dataSink->Put(character);
            }
            if (!index == row.size()-1) {
                dataSink->Put(delim);
            }
        };

        return true;
    }
};

CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall) {
    DImplementation = std::make_unique<SImplementation> (sink,delimiter,quoteall);
}

CDSVWriter::~CDSVWriter(){

}

bool CDSVWriter::WriteRow(const std::vector<std::string> &row) {
    return DImplementation -> WriteRow(row);
}