# Path Router Doccumentation

## Included

- vector

- limits

- any

- chrono

## Members

- alias TVertexsID for the type std::size_t 

- InvalidVertexID is initialized with the maximum value of TVertexID -> used to indicate invalid vertex ID

- NoPathExists is initialized with the maximum value of 'double' -> used to indicate that no path exists between two vertices

- VertexCount() returns the number of vertices

- AddVertex(tag) adds a vertex with a given tag and returns its ID

- GetVertexTag(ID) returns the tag associated with its given vertex ID

- AddEdge(src, dest, weight, bidir) adds an edge between two vertices with an optional weight. The bidir parameter indicates whether the edge is bidirectional

- Precompute(deadline) performs any necessary precomputations before finding paths. the deadline parameter specifies a time limit

- FindShortestPath(src, dest, path) finds the shortest path between two vertices and stores it in the 'path' vector. returns the length of the shortest path.