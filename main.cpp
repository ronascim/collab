#include "Point.h"
#include "VectorGraphic.h"
#include "Serialization.h"

int main(int argc, char * argv[])
{
	//Open XML file
    std::ifstream f;
    if (argc != 3)
    {
        std::cout << "Please use: Assign1.exe in.xml out.xml" << std::endl;
        return 1;
    }
    f.open(argv[1]);
    //Error handling
    if (f.fail())
    {
        std::cout << "Error opening/loading the file" << std::endl;
        return 1;
    }
    //Create Serialization object
    Serialization s;
   
    //Call method deserialize (read XML)
        
    VectorGraphic vg;
    s.deserialize(f, &vg);
   
	
	//Read the file(use regex to read value of x, y) from file. 

	//Close XML file
    f.close();
	//Create new XML file (open for writing)
    std::fstream fnew;
    fnew.open(argv[2]);
    //Error handling
    if (f.fail())
    {
        std::cout << "Error opening/loading the file for xml output" << std::endl;
        return 1;
    }
    s.serialize(fnew, &vg);

	//Call method serialize on the vectorgraphic

    fnew.close();
	//Close XML file 
}