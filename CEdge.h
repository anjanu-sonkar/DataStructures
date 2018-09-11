#ifndef CEDGE_H
#define CEDGE_H

#include <string>

#include "cvertex.h"
#include "DataTypes.h"

enum class EdgeType{DIRECTED, UNDIRECTED};

class CEdge
{
public:
    CEdge(const std::string& vertex1, const std::string& vertex1, EdgeType type=EdgeType::UNDIRECTED, INT64 weight=0);

private:
    CVertex *vertex1, *vertex2;
    EdgeType type;
    INT64 weight;
};

#endif // CEDGE_H
