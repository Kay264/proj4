# Dijkstra Path Router Doccumentation

SImplementation is a private struct that hides the implementation of the classes member functions.

## Included

- "PathRouter.h"

- memory

## Members

  - VertexCount() returns the number of vertices in the graph

  - AddVertex() adds a vertex to the graph and associates it with a givben tag

  - GetVertexTag() retries the tag associated witha vertex

  - AddEdge() adds an edge between two verticeseds witha given weight. The bidir parameter is for indicating if a edge is bidirectional

  - Precompute() preforms necessary prrprocessing steps before finding the shortest path

  - FindShortestPath() finds the shortest path between two vertices, returns length


