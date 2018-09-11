#include "CEdge.h"

CEdge::CEdge(const CVertex &vertex1, const CVertex &vertex2, EdgeType type, INT64 weight)   : vertex1{&vertex2}, vertex2{&vertex2}, type{type}, weight{weight}
{

}
