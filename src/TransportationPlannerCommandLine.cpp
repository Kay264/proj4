//includes





/*
___________________________notes________________________________________________________________________________________

                                  GIVEN CLASS DESCRIPTION

- the CTransportationPlannerCommandLine clas will implement the command line interface for the transplanner program

-The transplanner program is a command line program that will take in commands and execute what is requested
-
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 

                                      NOTES FOR WORK

-will need to rework for SImplementation!!!!!

________________________________________________________________________________________________________________________
*/


//Constructor for the Transportation Planner Command Line
CTransportationPlannerCommandLine(std::shared_ptr<CDataSource> cmdsrc, 
    std::shared_ptr<CDataSink> outsink, 
    std::shared_ptr<CDataSink> errsink, 
    std::shared_ptr<CDataFactory> results, 
    std::shared_ptr<CTransportationPlanner> planner);



//Destructor for the Transportation Planner Command Line 
~CTransportationPlannerCommandLine();


//Processes the commands input to the...(left blank in instructions)
bool ProcessCommands();
