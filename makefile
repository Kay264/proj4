CC=gcc
CXX=g++

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TEST_SRC_DIR = ./testsrc
TEST_TMP_DIR = ./testtmp

CXXFLAGS = -std=c++17 -I $(INC_DIR) -Wall -Werror
LDFLAGS = -lgtest -lgtest_main -lpthread -lexpat

all: directories runtests

runtests:	run_teststrutils \
			run_teststrdatasource \
			run_teststrdatasink \
			run_testfiledatass \
			run_testxml \
			run_testdsv \
			run_testcsvbs \
			run_testosm \
			run_testkml \
			run_testdpr \
			run_testcsvbsi \
			run_testtpcl \
			run_testtp \


run_teststrutils: $(BIN_DIR)/teststrutils
	$(BIN_DIR)/teststrutils --gtest_output=xml:$(TEST_TMP_DIR)/run_teststrutils
	mv $(TEST_TMP_DIR)/run_teststrutils run_teststrutils

run_teststrdatasource: $(BIN_DIR)/teststrdatasource
	$(BIN_DIR)/teststrdatasource --gtest_output=xml:$(TEST_TMP_DIR)/run_teststrdatasource
	mv $(TEST_TMP_DIR)/run_teststrdatasource run_teststrdatasource
	
run_teststrdatasink: $(BIN_DIR)/teststrdatasink
	$(BIN_DIR)/teststrdatasink --gtest_output=xml:$(TEST_TMP_DIR)/run_teststrdatasink
	mv $(TEST_TMP_DIR)/run_teststrdatasink run_teststrdatasink

run_testfiledatass: $(BIN_DIR)/testfiledatass
	$(BIN_DIR)/testfiledatass --gtest_output=xml:$(TEST_TMP_DIR)/run_testfiledatass
	mv $(TEST_TMP_DIR)/run_testfiledatass run_testfiledatass

run_testxml: $(BIN_DIR)/testxml
	$(BIN_DIR)/testxml --gtest_output=xml:$(TEST_TMP_DIR)/run_testxml
	mv $(TEST_TMP_DIR)/run_testxml run_testxml

run_testdsv: $(BIN_DIR)/testdsv
	$(BIN_DIR)/testdsv --gtest_output=xml:$(TEST_TMP_DIR)/run_testdsv
	mv $(TEST_TMP_DIR)/run_testdsv run_testdsv

run_testcsvbs: $(BIN_DIR)/testcsvbs
	$(BIN_DIR)/testcsvbs --gtest_output=xml:$(TEST_TMP_DIR)/run_testcsvbs
	mv $(TEST_TMP_DIR)/run_testcsvbs run_testcsvbs

run_testosm: $(BIN_DIR)/testosm
	$(BIN_DIR)/testosm --gtest_output=xml:$(TEST_TMP_DIR)/run_testosm
	mv $(TEST_TMP_DIR)/run_testosm run_testosm

run_testkml: $(BIN_DIR)/testkml
	$(BIN_DIR)/testkml --gtest_output=xml:$(TEST_TMP_DIR)/run_testkml
	mv $(TEST_TMP_DIR)/run_testkml run_testkml

run_testdpr: $(BIN_DIR)/testdpr
	$(BIN_DIR)/testdpr --gtest_output=xml:$(TEST_TMP_DIR)/run_testdpr
	mv $(TEST_TMP_DIR)/run_testdpr run_testdpr

run_testcsvbsi: $(BIN_DIR)/testcsvbsi
	$(BIN_DIR)/testcsvbsi --gtest_output=xml:$(TEST_TMP_DIR)/run_testcsvbsi
	mv $(TEST_TMP_DIR)/run_testcsvbsi run_testcsvbsi

run_testtpcl: $(BIN_DIR)/testtpcl
	$(BIN_DIR)/testtpcl --gtest_output=xml:$(TEST_TMP_DIR)/run_testtpcl
	mv $(TEST_TMP_DIR)/run_testtpcl run_testtpcl

run_testtp: $(BIN_DIR)/testtp
	$(BIN_DIR)/testtp --gtest_output=xml:$(TEST_TMP_DIR)/run_testtp
	mv $(TEST_TMP_DIR)/run_testtp run_testtp



 # STRINGUTILS

$(BIN_DIR)/teststrutils: $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTest.o
	$(CXX) -o $(BIN_DIR)/teststrutils $(CXXFLAGS) $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTest.o $(LDFLAGS)

$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $(OBJ_DIR)/StringUtils.o -c $(CXXFLAGS) $(SRC_DIR)/StringUtils.cpp

$(OBJ_DIR)/StringUtilsTest.o: $(TEST_SRC_DIR)/StringUtilsTest.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $(OBJ_DIR)/StringUtilsTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/StringUtilsTest.cpp



 # DATASOURCE

$(BIN_DIR)/teststrdatasource: $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSourceTest.o
	$(CXX) -o $(BIN_DIR)/teststrdatasource $(CXXFLAGS) $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSourceTest.o $(LDFLAGS)

$(OBJ_DIR)/StringDataSource.o: $(SRC_DIR)/StringDataSource.cpp $(INC_DIR)/StringDataSource.h $(INC_DIR)/DataSource.h
	$(CXX) -o $(OBJ_DIR)/StringDataSource.o -c $(CXXFLAGS) $(SRC_DIR)/StringDataSource.cpp

$(OBJ_DIR)/StringDataSourceTest.o: $(TEST_SRC_DIR)/StringDataSourceTest.cpp $(INC_DIR)/StringDataSource.h $(INC_DIR)/StringDataSource.h $(INC_DIR)/DataSource.h
	$(CXX) -o $(OBJ_DIR)/StringDataSourceTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/StringDataSourceTest.cpp



 # DATASINK

$(BIN_DIR)/teststrdatasink: $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringDataSinkTest.o
	$(CXX) -o $(BIN_DIR)/teststrdatasink $(CXXFLAGS) $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringDataSinkTest.o $(LDFLAGS)

$(OBJ_DIR)/StringDataSink.o: $(SRC_DIR)/StringDataSink.cpp $(INC_DIR)/StringDataSink.h $(INC_DIR)/DataSink.h
	$(CXX) -o $(OBJ_DIR)/StringDataSink.o -c $(CXXFLAGS) $(SRC_DIR)/StringDataSink.cpp

$(OBJ_DIR)/StringDataSinkTest.o: $(TEST_SRC_DIR)/StringDataSinkTest.cpp $(INC_DIR)/StringDataSink.h $(INC_DIR)/DataSink.h
	$(CXX) -o $(OBJ_DIR)/StringDataSinkTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/StringDataSinkTest.cpp



# FILE DATA

$(BIN_DIR)/testfiledatass: $(OBJ_DIR)/FileDataSource.o $(OBJ_DIR)/FileDataSink.o $(OBJ_DIR)/FileDataFactory.o $(OBJ_DIR)/FileDataSSTest.o
	$(CXX) -o $(BIN_DIR)/testfiledatass $(CXXFLAGS) $(OBJ_DIR)/FileDataSource.o $(OBJ_DIR)/FileDataSink.o $(OBJ_DIR)/FileDataFactory.o $(LDFLAGS)

$(OBJ_DIR)/FileDataSource.o: $(SRC_DIR)/FileDataSource.cpp $(INC_DIR)/FileDataSource.h $(INC_DIR)/DataSource.h
	$(CXX) -o $(OBJ_DIR)/FileDataSource.o -c $(CXXFLAGS) $(SRC_DIR)/FileDataSource.cpp

$(OBJ_DIR)/FileDataSink.o: $(SRC_DIR)/FileDataSink.cpp $(INC_DIR)/FileDataSink.h $(INC_DIR)/DataSink.h
	$(CXX) -o $(OBJ_DIR)/FileDataSink.o -c $(CXXFLAGS) $(SRC_DIR)/FileDataSink.cpp

$(OBJ_DIR)/FileDataFactory.o: $(SRC_DIR)/FileDataFactory.cpp $(INC_DIR)/FileDataFactory.h $(INC_DIR)/DataFactory.h
	$(CXX) -o $(OBJ_DIR)/FileDataFactory.o -c $(CXXFLAGS) $(SRC_DIR)/FileDataFactory.cpp

$(OBJ_DIR)/FileDataSSTest.o: $(TEST_SRC_DIR)/FileDataSSTest.cpp $(INC_DIR)/FileDataSource.h $(INC_DIR)/FileDataSink.h $(INC_DIR)/FileDataFactory.h
	$(CXX) -o $(OBJ_DIR)/FileDataSSTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/FileDataSSTest.cpp


 # XML

$(BIN_DIR)/testxml: $(OBJ_DIR)/XMLWriter.o $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLTest.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o
	$(CXX) -o $(BIN_DIR)/testxml $(CXXFLAGS) $(OBJ_DIR)/XMLWriter.o $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLTest.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(LDFLAGS)

$(OBJ_DIR)/XMLWriter.o: $(SRC_DIR)/XMLWriter.cpp $(INC_DIR)/XMLWriter.h
	$(CXX) -o $(OBJ_DIR)/XMLWriter.o -c $(CXXFLAGS) $(SRC_DIR)/XMLWriter.cpp

$(OBJ_DIR)/XMLReader.o: $(SRC_DIR)/XMLReader.cpp $(INC_DIR)/XMLReader.h
	$(CXX) -o $(OBJ_DIR)/XMLReader.o -c $(CXXFLAGS) $(SRC_DIR)/XMLReader.cpp

$(OBJ_DIR)/XMLTest.o: $(TEST_SRC_DIR)/XMLTest.cpp $(INC_DIR)/XMLReader.h $(INC_DIR)/XMLWriter.h
	$(CXX) -o $(OBJ_DIR)/XMLTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/XMLTest.cpp



 # DSV

$(BIN_DIR)/testdsv: $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/DSVReader.o $(OBJ_DIR)/DSVTest.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o
	$(CXX) -o $(BIN_DIR)/testdsv $(CXXFLAGS) $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/DSVReader.o $(OBJ_DIR)/DSVTest.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(LDFLAGS)

$(OBJ_DIR)/DSVReader.o: $(SRC_DIR)/DSVReader.cpp $(INC_DIR)/DSVReader.h
	$(CXX) -o $(OBJ_DIR)/DSVReader.o -c $(CXXFLAGS) $(SRC_DIR)/DSVReader.cpp

$(OBJ_DIR)/DSVWriter.o: $(SRC_DIR)/DSVWriter.cpp $(INC_DIR)/DSVWriter.h
	$(CXX) -o $(OBJ_DIR)/DSVWriter.o -c $(CXXFLAGS) $(SRC_DIR)/DSVWriter.cpp

$(OBJ_DIR)/DSVTest.o: $(TEST_SRC_DIR)/DSVTest.cpp $(INC_DIR)/DSVReader.h $(INC_DIR)/DSVWriter.h
	$(CXX) -o $(OBJ_DIR)/DSVTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/DSVTest.cpp



 # CSVBS

$(BIN_DIR)/testcsvbs: $(OBJ_DIR)/CSVBusSystemTest.o $(OBJ_DIR)/CSVBusSystem.o
	$(CXX) $(OBJ_DIR)/CSVBusSystemTest.o $(OBJ_DIR)/CSVBusSystem.o  $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/DSVReader.o $(LDFLAGS) -lexpat -o $(BIN_DIR)/testcsvbs

$(OBJ_DIR)/CSVBusSystem.o: $(SRC_DIR)/CSVBusSystem.cpp $(INC_DIR)/CSVBusSystem.h $(INC_DIR)/BusSystem.h $(INC_DIR)/StreetMap.h $(INC_DIR)/DSVReader.h $(INC_DIR)/DataSource.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/CSVBusSystem.cpp  -o $(OBJ_DIR)/CSVBusSystem.o

$(OBJ_DIR)/CSVBusSystemTest.o: $(TEST_SRC_DIR)/CSVBusSystemTest.cpp $(INC_DIR)/CSVBusSystem.h $(INC_DIR)/BusSystem.h $(INC_DIR)/StreetMap.h $(INC_DIR)/DSVReader.h $(INC_DIR)/DataSource.h
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC_DIR)/CSVBusSystemTest.cpp -o $(OBJ_DIR)/CSVBusSystemTest.o




 # OSM

$(BIN_DIR)/testosm: $(OBJ_DIR)/OpenStreetMapTest.o $(OBJ_DIR)/OpenStreetMap.o $(OBJ_DIR)/XMLReader.o
	$(CXX) $(OBJ_DIR)/OpenStreetMapTest.o $(OBJ_DIR)/OpenStreetMap.o  $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/XMLReader.o $(LDFLAGS) -lexpat -o $(BIN_DIR)/testosm

$(OBJ_DIR)/OpenStreetMap.o: $(SRC_DIR)/OpenStreetMap.cpp $(INC_DIR)/OpenStreetMap.h $(INC_DIR)/StreetMap.h $(INC_DIR)/XMLReader.h $(INC_DIR)/XMLEntity.h $(INC_DIR)/DataSource.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/OpenStreetMap.cpp  -o $(OBJ_DIR)/OpenStreetMap.o

$(OBJ_DIR)/OpenStreetMapTest.o: $(TEST_SRC_DIR)/OpenStreetMapTest.cpp $(INC_DIR)/OpenStreetMap.h $(INC_DIR)/StreetMap.h $(INC_DIR)/XMLReader.h $(INC_DIR)/XMLEntity.h $(INC_DIR)/DataSource.h 
	$(CXX) $(CXXFLAGS) -c $(TEST_SRC_DIR)/OpenStreetMapTest.cpp -o $(OBJ_DIR)/OpenStreetMapTest.o




 # KML

$(BIN_DIR)/testkml: $(OBJ_DIR)/KMLWriter.o $(OBJ_DIR)/KMLTest.o
	$(CXX) -o $(BIN_DIR)/testkml $(CXXFLAGS) $(OBJ_DIR)/KMLWriter.o $(OBJ_DIR)/KMLTest.o $(LDFLAGS)

$(OBJ_DIR)/KMLWriter.o: $(SRC_DIR)/KMLWriter.cpp $(INC_DIR)/KMLWriter.h
	$(CXX) -o $(OBJ_DIR)/KMLWriter.o -c $(CXXFLAGS) $(SRC_DIR)/KMLWriter.cpp

$(OBJ_DIR)/KMLTest.o: $(TEST_SRC_DIR)/KMLTest.cpp $(INC_DIR)/KMLWriter.h
	$(CXX) -o $(OBJ_DIR)/KMLTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/KMLTest.cpp

 # did i include the right header...?



 # DIJKSTRA

$(BIN_DIR)/testdpr: $(OBJ_DIR)/DijkstraPathRouter.o $(OBJ_DIR)/DijkstraPathRouterTest.o
	$(CXX) -o $(BIN_DIR)/testdpr $(CXXFLAGS) $(OBJ_DIR)/DijkstraPathRouter.o $(OBJ_DIR)/DijkstraPathRouterTest.o $(LDFLAGS)

$(OBJ_DIR)/DijkstraPathRouter.o: $(SRC_DIR)/DijkstraPathRouter.cpp $(INC_DIR)/DijkstraPathRouter.h
	$(CXX) -o $(OBJ_DIR)/DijkstraPathRouter.o -c $(CXXFLAGS) $(SRC_DIR)/DijkstraPathRouter.cpp

$(OBJ_DIR)/DijkstraPathRouterTest.o: $(TEST_SRC_DIR)/DijkstraPathRouterTest.cpp $(INC_DIR)/DijkstraPathRouter.h
	$(CXX) -o $(OBJ_DIR)/DijkstraPathRouterTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/DijkstraPathRouterTest.cpp



 # BUS_SYSTEM_INDEXER

$(BIN_DIR)/testcsvbsi: $(OBJ_DIR)/BusSystemIndexer.o $(OBJ_DIR)/CSVBusSystemIndexerTest.o
	$(CXX) -o $(BIN_DIR)/testcsvbsi $(CXXFLAGS) $(OBJ_DIR)/BusSystemIndexer.o $(OBJ_DIR)/CSVBusSystemIndexerTest.o $(LDFLAGS)

$(OBJ_DIR)/BusSystemIndexer.o: $(SRC_DIR)/BusSystemIndexer.cpp $(INC_DIR)/BusSystemIndexer.h
	$(CXX) -o $(OBJ_DIR)/BusSystemIndexer.o -c $(CXXFLAGS) $(SRC_DIR)/BusSystemIndexer.cpp

$(OBJ_DIR)/CSVBusSystemIndexerTest.o: $(TEST_SRC_DIR)/CSVBusSystemIndexerTest.cpp $(INC_DIR)/BusSystemIndexer.h
	$(CXX) -o $(OBJ_DIR)/CSVBusSystemIndexerTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/CSVBusSystemIndexerTest.cpp


 # TPCL

$(BIN_DIR)/testtpcl: $(OBJ_DIR)/TransportationPlannerCommandLine.o $(OBJ_DIR)/TPCommandLineTest.o
	$(CXX) -o $(BIN_DIR)/testtpcl $(CXXFLAGS) $(OBJ_DIR)/TransportationPlannerCommandLine.o $(OBJ_DIR)/TPCommandLineTest.o $(LDFLAGS)

$(OBJ_DIR)/TransportationPlannerCommandLine.o: $(SRC_DIR)/TransportationPlannerCommandLine.cpp $(INC_DIR)/TransportationPlannerCommandLine.h
	$(CXX) -o $(OBJ_DIR)/TransportationPlannerCommandLine.o -c $(CXXFLAGS) $(SRC_DIR)/TransportationPlannerCommandLine.cpp

$(OBJ_DIR)/TPCommandLineTest.o: $(TEST_SRC_DIR)/TPCommandLineTest.cpp $(INC_DIR)/TransportationPlannerCommandLine.h
	$(CXX) -o $(OBJ_DIR)/TPCommandLineTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/TPCommandLineTest.cpp



 # TRANSPORTATION_PLANNER

$(BIN_DIR)/testtp: $(OBJ_DIR)/DijkstraTransportationPlanner.o $(OBJ_DIR)/CSVOSMTransportationPlannerTest.o
	$(CXX) -o $(BIN_DIR)/testtp $(CXXFLAGS) $(OBJ_DIR)/DijkstraTransportationPlanner.o $(OBJ_DIR)/CSVOSMTransportationPlannerTest.o $(LDFLAGS)

$(OBJ_DIR)/DijkstraTransportationPlanner.o: $(SRC_DIR)/DijkstraTransportationPlanner.cpp $(INC_DIR)/DijkstraTransportationPlanner.h
	$(CXX) -o $(OBJ_DIR)/DijkstraTransportationPlanner.o -c $(CXXFLAGS) $(SRC_DIR)/DijkstraTransportationPlanner.cpp

$(OBJ_DIR)/CSVOSMTransportationPlannerTest.o: $(TEST_SRC_DIR)/CSVOSMTransportationPlannerTest.cpp $(INC_DIR)/DijkstraTransportationPlanner.h
	$(CXX) -o $(OBJ_DIR)/CSVOSMTransportationPlannerTest.o -c $(CXXFLAGS) $(TEST_SRC_DIR)/CSVOSMTransportationPlannerTest.cpp






clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(TEST_TMP_DIR)
	rm -f run_* 

directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(TEST_TMP_DIR)