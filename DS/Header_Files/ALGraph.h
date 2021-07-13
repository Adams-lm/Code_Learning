#include <stdio.h>
#include <stdlib.h>
#define MaxVerTexNum 100
typedef char VertexType;
typedef int EdgeType;
using namespace std;

typedef struct ArcNode {
    int adjvex;
    ArcNode *next;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MaxVerTexNum];

typedef struct ALGraph {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;
