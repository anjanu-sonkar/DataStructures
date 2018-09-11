#include "cgraph.h"
#include <iostream>

CGraph::CGraph()
{

}

bool CGraph::addVertex(const std::string &name)
{
    if(auto i = vertices.find(name) == vertices.end())
    {
        vertices.insert(std::make_pair(name, CVertex(name)));
        return true;
    }
    return false;
}

void CGraph::addVertices(std::vector<CVertex> verts)
{
    for(auto i:verts)
    {
        if(vertices.find(i.getName()) == vertices.end())
            vertices.insert(std::make_pair(i.getName(), i));
        else
            std::cout<<"Skipped "<<i.getName()<<": Dupliate"<<std::endl;
    }
}

bool CGraph::addEdge(const std::string &vertex1, const std::string &vertex2, EdgeType type, INT64 weight)
{
    auto i=vertices.find(vertex1);
    if(i != vertices.end())
    {
        CVertex *v1 = &i->second;
        auto i2=vertices.find(vertex2);
        if(i2 != vertices.end())
        {
            CVertex *v2 = &i2->second;
            v1->addNeighbour(v2);
            if(type==EdgeType::UNDIRECTED)
                v2->addNeighbour(v1);
            edges.push_back(CEdge(v1, v2, type, weight));
        }
    }
    return false;
}
