#ifndef CVERTEX_H
#define CVERTEX_H
#include <vector>

class CVertex
{
public:
    CVertex(char id);
    const std::vector<CVertex*>& getNeighbours() const;
    void addNeighbour(CVertex* v);
    void setNeighbours(std::initializer_list<CVertex*> vertices);
    void setVisited(bool status);
    bool isVisited() const;
    void setParent(CVertex *v);
    const CVertex* getParent();
    char getID() const;
private:
    char id;
    std::vector<CVertex*> neighbours;
    CVertex *parent;
    bool visited;
};

#endif // CVERTEX_H
