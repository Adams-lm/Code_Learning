#include <stdio.h>
#include <stdlib.h>
#define MaxVerTexNum 100
typedef char VertexType;
typedef int EdgeType;
using namespace std;

typedef struct MGraph {
    VertexType Vex[MaxVerTexNum];
    EdgeType Edge[MaxVerTexNum][MaxVerTexNum];
    int vexnum, arcnum;
} MGraph;
