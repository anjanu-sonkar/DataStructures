#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "cvertex.h"
#include "cgraph.h"

using namespace std;

CVertex r('r');
CVertex s('s');
CVertex t('t');
CVertex u('u');
CVertex v('v');
CVertex w('w');
CVertex x('x');
CVertex y('y');
CVertex z('z');
unordered_set<CVertex*> callStack;
void dfs(unordered_map<char, CVertex*>& graph, CVertex *start, CVertex *parent);
void dfsVisit(unordered_map<char, CVertex*>& graph, CVertex *vertex, CVertex *parent);

CGraph g;
int main()
{
    g.addVertex("A");
    g.addVertices({CVertex("H"), CVertex("E"), CVertex("L"), CVertex("L"), CVertex("O")});

    cout<<g.getVertexCount()<<endl;
    unordered_map<char, CVertex*> graph;
    graph.insert(make_pair('r', &r));
    graph.insert(make_pair('s', &s));
    graph.insert(make_pair('t', &t));
    graph.insert(make_pair('u', &u));
    graph.insert(make_pair('v', &v));
    graph.insert(make_pair('w', &w));
    graph.insert(make_pair('x', &x));
    graph.insert(make_pair('y', &y));
    graph.insert(make_pair('z', &z));
    r.setNeighbours({&s, &v});
    s.setNeighbours({&r, &w});
    t.setNeighbours({&w, &x, &u});
    u.setNeighbours({&t, &x, &y});
    v.setNeighbours({&r, &w});
    w.setNeighbours({&s, &t, &x, &v});
    x.setNeighbours({&w, &t, &u, &y});
    y.setNeighbours({&x, &u});
    dfs(graph, &s, nullptr);
    callStack.clear();
    cout << "Exiting!" << endl;
    return 0;
}

void dfsVisit(unordered_map<char, CVertex*>& graph, CVertex *vertex, CVertex *parent=nullptr)
{
    auto i = callStack.find(vertex);
    if(i == callStack.end())
    {
        cout<<"processing "<<vertex->getID()<<endl;
        callStack.insert(vertex);
        vertex->setParent(parent);
        for(auto adjVertex:vertex->getNeighbours())
            dfsVisit(graph, adjVertex, vertex);
        vertex->setVisited(true);
        cout<<vertex->getID()<<" Processed"<<endl;
    }
}

void dfs(unordered_map<char, CVertex*>& graph, CVertex *start, CVertex *parent)
{
    if(start)
        dfsVisit(graph, start, nullptr);
    for(auto vertex: graph)
    {
        dfsVisit(graph, vertex.second, nullptr);
    }
}
