#ifndef _SERIALIZATION_H_
#define _SERIALIZATION_H_
#include "iostream"
#include "ostream"
#include "istream"
#include <exception>
#include <regex>

class VectorGraphic;


class Serialization
{

public:
	Serialization();
	void serialize(std::ostream& out, VectorGraphic * vg);
	void deserialize(std::istream& in,  VectorGraphic * vg) ;
private:
};
#endif 