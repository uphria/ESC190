import numpy as np




class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

def dijkstra(start, end):
    start.distance_from_start = 0
    visited = set([start])
    current = start
    while current != end:
        
        cur_dist = np.inf
        cur_v = None
        for node in visited:
            for con in node.connections:
                if con.node in visited:
                    continue
                if cur_dist > node.distance_from_start + con.weight:
                    cur_dist = node.distance_from_start + con.weight
                    cur_v = con.node
    
        current = cur_v
        current.distance_from_start = cur_dist
        visited.add(current)
    return current.distance_from_start

A = Node('A')
B = Node('B')
C = Node('C')
D = Node('D')

A.connections.append(Con(B, 5))
A.connections.append(Con(C, 1))
A.connections.append(Con(D, 3))
B.connections.append(Con(D, 8))
C.connections.append(Con(D, 1))

print(dijkstra(A, D))

'''
 > 5 B
/    \> 8
A -> 3 D
\     /> 1
 > 1 C

'''