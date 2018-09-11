#include "cgraph.h"
#include <iostream>

CGraph::CGraph()
{

}

bool CGraph::addVertex(const std::string &name)
{
    if(auto i = graph.find(name) == graph.end())
    {
        graph.insert(std::make_pair(name, CVertex(name)));
        return true;
    }
    return false;
}

void CGraph::addVertices(std::vector<CVertex> vertices)
{
    for(auto i:vertices)
    {
        if(graph.find(i.getName()) == graph.end())
            graph.insert(std::make_pair(i.getName(), i));
        else
            std::cout<<"Skipped "<<i.getName()<<": Dupliate"<<std::endl;
    }
}
