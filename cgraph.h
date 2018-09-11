#ifndef CGRAPH_H
#define CGRAPH_H

#include <unordered_map>
#include <vector>
#include <string>

#include "cvertex.h"
#include "CEdge.h"
#include "DataTypes.h"

class CGraph
{
public:
    CGraph();
    bool addVertex(const std::string& name);
    void addVertices(std::vector<CVertex> vers);
    inline UINT32 getVertexCount() const{return vertices.size();}
    bool addEdge(const std::string& vertex1, const std::string& vertex2, EdgeType type, INT64 weight);
private:
    std::unordered_map<std::string, CVertex> vertices;
    std::vector<CEdge> edges;
};

#endif // CGRAPH_H
