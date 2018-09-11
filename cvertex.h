#ifndef CVERTEX_H
#define CVERTEX_H
#include <vector>
#include <string>

class CVertex
{
public:
    CVertex(char id);
    CVertex(std::string name);
    const std::vector<CVertex*>& getNeighbours() const;
    void addNeighbour(CVertex* v);
    void setNeighbours(std::initializer_list<CVertex*> vertices);
    void setVisited(bool status);
    bool isVisited() const;
    void setParent(CVertex *v);
    const CVertex* getParent();
    char getID() const;
    inline const std::string& getName() const{return name;}
private:
    char id;
    std::string name;
    std::vector<CVertex*> neighbours;
    CVertex *parent;
    bool visited;
};

#endif // CVERTEX_H
