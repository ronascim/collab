#include "Serialization.h"
#include "VectorGraphic.h"
#include <regex>
#include <string>
#include <iostream>
#include <sstream>


Serialization::Serialization()
{
}

void Serialization::serialize(std::ostream& out, VectorGraphic * vg)
{
    //Check the doc 
    out << "<VectorGraphic closed=";
        if (vg->isOpen())
        {
            out << "false";
        } 
        else
        {
            out << "true";
        }
        
        for (int i = 0; i <= vg->getPointCount(); i++)
        {
            
            Point savep = vg->getPoint(i);
            out << "<Point x=" << savep.getX() << " y=" << savep.getY() << "/>\n";
        }
    out << "</VectorGraphic>";
}


void Serialization::deserialize(std::istream& in, VectorGraphic * vg )
{
    
    int x = 0;
    int y = 0;

    const std::regex re("[^0-9]*([0-9]+).*");
    
     // Use regex_search 
     std::smatch sm;

     while (!in.eof())
     {
         std::string line;
         getline(in, line);
         //If there is a match, it means both x and y variables will be existent
         if (std::regex_search(line, sm, re))
         {
             
            //match x and y
            // vg->addPoint(Point(x, y));
             std::cout << sm[0];
             std::cout << sm[1];
         }

     }
}
