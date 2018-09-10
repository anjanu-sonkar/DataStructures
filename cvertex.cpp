#include "cvertex.h"

CVertex::CVertex(char id)   : id{id}, parent{nullptr}, visited{false}
{

}

const std::vector<CVertex *>& CVertex::getNeighbours() const
{
    return neighbours;
}

void CVertex::addNeighbour(CVertex *v)
{
    neighbours.push_back(v);
}

void CVertex::setNeighbours(std::initializer_list<CVertex *> vertices)
{
    for(auto v:vertices)
        neighbours.push_back(v);
}

void CVertex::setVisited(bool status)
{
    visited = status;
}

bool CVertex::isVisited() const
{
    return visited;
}

void CVertex::setParent(CVertex *v)
{
    parent = v;
}

const CVertex *CVertex::getParent()
{
    return parent;
}

char CVertex::getID() const
{
    return id;
}
