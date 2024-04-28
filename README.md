# Benchmark de Algoritmos de Ordenação
Benchmark da perfomance de diferentes tipos de algoritmos de ordenação implementado em C.

Serão analisados os seguintes algoritmos:

| Algoritmo | Complexidade Assintótica | Melhor Caso | Pior Caso |
| --------- | ------------------------ | ----------- | --------- |
| **Seleção** | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n<sup>2</sup>) |
| **Inserção** | O(n<sup>2</sup>) | O(n) | O(n<sup>2</sup>) |
| **MergeSort** | O(n log<sub>2</sub>(n)) | O(n log<sub>2</sub>(n)) | O(n log<sub>2</sub>(n)) |
| **QuickSort** | O(n log<sub>2</sub>(n)) | O(n log<sub>2</sub>(n)) | O(n<sup>2</sup>) |
| **Dual-Pivot QuickSort** | O(n log<sub>2</sub>(n)) | O(n log<sub>2</sub>(n)) | O(n<sup>2</sup>) |

Os testes foram feitos em um 3.7 GHz Ryzen 5.

## Selection Sort

**Tempo**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 0 ms | 0.2 ms | 0 ms | 1 ms |
| 10000 | 12.6 ms | 12.6 ms | 63 ms | 67 ms |
| 100000 | 1.28 s | 1.286 s | 6.461 s | 6.889 s |
| 500000 | | | | |
| 1000000 | | | | |
