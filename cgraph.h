#ifndef CGRAPH_H
#define CGRAPH_H

#include <unordered_map>
#include <string>

#include "cvertex.h"
#include "DataTypes.h"

class CGraph
{
public:
    CGraph();
    bool addVertex(const std::string& name);
    void addVertices(std::vector<CVertex> vertices);
    inline UINT32 getVertexCount() const{return graph.size();}
private:
    std::unordered_map<std::string, CVertex> graph;
};

#endif // CGRAPH_H
