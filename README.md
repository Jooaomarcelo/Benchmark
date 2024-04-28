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
| 1000 | 0 ms | 0,2 ms | 0 ms | 1 ms |
| 10000 | 12,6 ms | 12,6 ms | 63 ms | 67 ms |
| 100000 | 1,28 s | 1,286 s | 6,461 s | 6,889 s |
| 500000 | | | | |
| 1000000 | | | | |

**Comparações**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 499.500 | 499.500 | 499.500 | 499.500 |
| 10000 | 49.995.000 | 49.995.000 | 49.995.000 | 49.995.000 |
| 100000 | 4.999.950.000 | 4.999.950.000 | 4.999.950.000 | 4.999.950.000 |
| 500000 | | | | |
| 1000000 | | | | |

**Trocas**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 992 | 995 | 0 | 500 |
| 10000 | 9.990,8 | 9.992 | 0 | 5.000 |
| 100000 | 99.983,4 | 99.990,8 | 0 | 50.000 |
| 500000 | | | | |
| 1000000 | | | | |

## Insertion Sort

**Tempo**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 0,2 ms | 0,2 ms | 0 ms | 1 ms |
| 10000 | 9,8 ms | 3,6 ms | 0 ms | 97 ms |
| 100000 | 990 ms | 367 ms | 0 ms | 9,930 s |
| 500000 | | | | |
| 1000000 | | | | |

**Comparações**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 247.450 | 93.458 | 999 | 500.499 |
| 10000 | 25.074.017,2 | 9.256.450 | 9.999 | 50.004.999 |
| 100000 | 2.500.283.236,4 | 925.164.017,2 | 99.999 | 5.000.049.999 |
| 500000 | | | | |
| 1000000 | | | | |

**Trocas**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 247.442 | 93.452,8 | 0 | 500.499 |
| 10000 | 25.074.006,8 | 9.256.442 | 0 | 50.004.999 |
| 100000 | 2.500.283.221 | 925.164.006,8 | 0 | 5.000.049.999 |
| 500000 | | | | |
| 1000000 | | | | |

## Merge Sort

**Tempo**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 0 ms | 0 ms | 0 ms | 0 ms |
| 10000 | 0,4 ms | 0,2 ms | 1 ms | 0 ms |
| 100000 | 3 ms | 2 ms | 11 ms | 10 ms |
| 500000 | | | | |
| 1000000 | | | | |

**Comparações**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 8.702,6 | 5.863,2 | 5.044 | 4.932 |
| 10000 | 120.465 | 78.709,2 | 69.008 | 64.608 |
| 100000 | 1.536.274,2 | 967.811,4 | 853.904 | 815.024 |
| 500000 | | | | |
| 1000000 | | | | |

**Trocas**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 9.976 | 9.976 | 9.976 | 9.976 |
| 10000 | 133.616 | 133.616 | 133.616 | 133.616 |
| 100000 | 1.668.928 | 1.668.928 | 1.668.928 | 1.668.928 |
| 500000 | | | | |
| 1000000 | | | | |

## Quick Sort

**Tempo**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 0 ms | 0 ms | 1 ms | 1 ms |
| 10000 | 0,2 ms | 12 ms | 58 ms | 68 ms |
| 100000 | 1,8 ms | 1,2122 s | 5,735 s | 6,574 s |
| 500000 | | | | |
| 1000000 | | | | |

**Comparações**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 12.380,6 | 406.230,8 | 499.500 | 499.500 |
| 10000 | 178.392,2 | 40.516.043,6 | 49.995.000 | 49.995.000 |
| 100000 | 2.153.783,6 | 4.050.210.949,8 | 4.999.950.000 | 4.999.950.000 |
| 500000 | | | | |
| 1000000 | | | | |

**Trocas**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 5.032,8 | 2.215,4 | 0 | 500 |
| 10000 | 74.558,2 | 29.734,8 | 0 | 5.000 |
| 100000 | 911.051,4 | 342.300,2 | 0 | 50.000 |
| 500000 | | | | |
| 1000000 | | | | |

## Dual-Pivot Quick Sort

**Tempo**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 0 ms | 0 ms | 1 ms | 0 ms |
| 10000 | 0,2 ms | 0,6 ms | 37 ms | 36 ms |
| 100000 | 1,6 ms | 50,4 ms | 3,697 s | 3,690 s |
| 500000 | | | | |
| 1000000 | | | | |

**Comparações**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 8.303,4 | 28.961,6 | 250.000 | 250.000 |
| 10000 | 114.901 | 2.316.967,4 | 25.000.000 | 25.000.000 |
| 100000 | 1.510.502,4 | 224.189.630,8 | 2.500.000.000 | 2.500.000.000 |
| 500000 | | | | |
| 1000000 | | | | |

**Trocas**
| Entrada | Aleatório | Quase Ordenado | Crescente | Decrescente |
| ------- | --------- | -------------- | --------- | ----------- |
| 1000 | 3.101,6 | 3.406,2 | 0 | 500 |
| 10000 | 46.038,2 | 40.412,4 | 0 | 5.000 |
| 100000 | 617.557 | 436.367,6 | 0 | 50.000 |
| 500000 | | | | |
| 1000000 | | | | |
