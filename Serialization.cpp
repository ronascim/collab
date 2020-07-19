#include "Serialization.h"
#include "VectorGraphic.h"
#include <regex>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

Serialization::Serialization()
{
}

void Serialization::serialize(std::ostream& out, VectorGraphic * vg)
{ 
    //Build XMLout.xml:
    try
    {
        out << "<VectorGraphic closed=\"";
        if (vg->isClosed())
        {
            out << "true";
        }
        else
        {
            out << "false";
        }
        out << "\">\n";

        //Retrieve number of points in vector 'vg'
        for (int i = 0; i < vg->getPointCount(); i++)
        {
            //Create object savep which will represent coordinates (x,y)
            Point savep = vg->getPoint(i);
            out << "  <Point x=\"" << savep.getX() << "\" y=\"" << savep.getY() << "\"/>\n";
        }
        //Finally, provide XML closure
        out << "</VectorGraphic>";
    }

    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}


void Serialization::deserialize(std::istream& in, VectorGraphic * vg )
{
 
     // Use regex search represented by variabme 'sm', a string:
     std::smatch sm;

     //This will be a match if digits are found on each line, no iterator required.
     const std::regex re("[^\\d]*([\\d]+)[a-z\\s\\=\"]*([\\d]*[\\d])");

     //Keep reading XML file until end of file

     try
     {
         while (!in.eof())
         {
             //Create local string varliable line
             std::string line;
             //Call get line; variable 'in' represents the stream
             getline(in, line);
             //If there is a match, it means both x and y variables will be existent
             if (std::regex_search(line, sm, re))
             {
                 //match x and y. Then convert string sm captures to intger using 'stoi'
                 Point p = Point(stoi(sm[1]), stoi(sm[2]));

                 //Add point (x,y) to vector
                 vg->addPoint(p);
             }

         }
     }

     catch (std::exception& e)
     {
         std::cout << e.what() << '\n';
     }
     
}
