class Solution {
  public int[] closestNode(int n, int[][] edges, int[][] query) {
    int[] ans = new int[query.length];
    List<Integer>[] graph = new List[n];
    int[][] dist = new int[n][n];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, -1));

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = 0; i < n; ++i)
      fillDist(graph, i, i, 0, dist);

    for (int i = 0; i < query.length; ++i) {
      final int start = query[i][0];
      final int end = query[i][1];
      final int node = query[i][2];
      ans[i] = findClosest(graph, dist, start, end, node, start);
    }

    return ans;
  }

  private void fillDist(List<Integer>[] graph, int start, int u, int d, int[][] dist) {
    dist[start][u] = d;
    for (final int v : graph[u])
      if (dist[start][v] == -1)
        fillDist(graph, start, v, d + 1, dist);
  }

  private int findClosest(List<Integer>[] graph, int[][] dist, int u, int end, int node, int ans) {
    for (final int v : graph[u])
      if (dist[v][end] < dist[u][end])
        return findClosest(graph, dist, v, end, node, dist[ans][node] < dist[v][node] ? ans : v);
    return ans;
  }
}
