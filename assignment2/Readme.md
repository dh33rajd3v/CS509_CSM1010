# Assignment 2

| Algorithm | Test File | Vertices | Edges | Source | Negative Cycle | Expected Output | Actual Output | Time | Status |
|---|---|---:|---:|---:|---|---|---|---:|---|
| Bellman-Ford | `bf_10.txt` | 5 | 10 | 0 | No | Distances | Distances: `0, 2, 4, 7, -2`<br>Negative cycle: none | `1 × 10⁻³ ms` | Pass |
| Bellman-Ford | `bf_100.txt` | 100 | 1,923 | 3 | No | Distances | — | `31 × 10⁻³ ms` | Pass |
| Bellman-Ford | `bf_10000.txt` | 10,000 | 20,000 | 808 | Yes | Distances | — | `2361.317 ms` | Pass |
| Bellman-Ford | `bf_50000.txt` | 50,000 | 250,000 | 0 | Yes | Distances | — | `109164.991 ms` | Pass |
| Bellman-Ford | `bf_100000.txt` | 100,000 | 500,000 | 0 | Yes | Distances | — | `610757.283 ms` | Pass |
| Floyd-Warshall | `fw_5.txt` | 5 | N/A | N/A | No | Distance matrix | Distance matrix computed<br>Negative cycle: none | `1 × 10⁻³ ms` | Pass |
| Floyd-Warshall | `fw_5.txt` | 5 | N/A | N/A | Yes | Distance matrix | — | `2 × 10⁻³ ms` | Pass |
| Floyd-Warshall | `fw_500.txt` | 500 | N/A | N/A | No | Distance matrix | — | `124.664 ms` | Pass |
| Floyd-Warshall | `fw_1000.txt` | 1,000 | N/A | N/A | No | Distance matrix | — | `927.971 ms` | Pass |
| Floyd-Warshall | `fw_2000.txt` | 2,000 | N/A | N/A | Yes | Distance matrix | — | `6750.685 ms` | Pass |