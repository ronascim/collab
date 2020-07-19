#include "Point.h"
#include "VectorGraphic.h"
#include "Serialization.h"
#include "TestHarness.h"

int main(int argc, char * argv[])
{
	//Open XML file
    std::ifstream f;
    f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try 
    {  
        //Open file, passing file name at program execution:
        f.open(argv[1]);              
    }

    catch (std::ifstream::failure e)
    {
        std::cerr << "Exception opening/reading/closing file (XMLin)\n";
        return 1;
    }
    //Create Serialization object
    Serialization s;
    //Call method deserialize (read XML)
    VectorGraphic vg;
    s.deserialize(f, &vg);
    //Close XMLin

    f.close(); //< ****** Should I do a if (f.fail()) to handle this close operation?
   
	//Read the file(use regex to read value of x, y) from file. 

	//Create new XML file (open for writing)
    std::ofstream fnew;
    fnew.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try
    {
        fnew.open(argv[2]);
  
    }
      
    catch (std::ofstream::failure e)
    {
        std::cerr << "Exception opening/reading/closing file (XMLout)\n";
        return 1;
    }

    s.serialize(fnew, &vg);

    fnew.close(); //< ****** Should I do a if (f.fail()) to handle this close operation?

    // random number generator used in some tests
    srand(::time_t(NULL));

    TestResult tr;
    TestRegistry::runAllTests(tr);

    // force console screen to hold
    char ch;
    std::cin >> ch;

    return 0;
}
