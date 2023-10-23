import heapq

def dijkstra(graph, start_node):
    # Initialize distances to all nodes as infinity except the start node.
    distances = {node: float('infinity') for node in graph}
    distances[start_node] = 0

    # Priority queue to keep track of the nodes to visit next.
    priority_queue = [(0, start_node)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        # Skip if this node has already been visited.
        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # If a shorter path is found, update the distance.
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

start_node = 'A'
result = dijkstra(graph, start_node)

for node, distance in result.items():
    print(f"Shortest distance from {start_node} to {node} is {distance}")
