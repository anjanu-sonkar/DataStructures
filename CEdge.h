#ifndef CEDGE_H
#define CEDGE_H

#include <string>

#include "cvertex.h"
#include "DataTypes.h"

enum class EdgeType{DIRECTED, UNDIRECTED};

class CEdge
{
public:
    CEdge(const CVertex& vertex1, const CVertex& vertex2, EdgeType type=EdgeType::UNDIRECTED, INT64 weight=0);
    inline void setWeight(INT64 weight) {this->weight=weight;}
    inline INT64 getWeight() const{return weight;}
    inline EdgeType getType() const{return type;}

private:
    CVertex *vertex1, *vertex2;
    EdgeType type;
    INT64 weight;
};

#endif // CEDGE_H
