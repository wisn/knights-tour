# Knight's Tour

The Knight's tour algorithms in C++.
Several algorithms implementation and its outputs included.
This repository created for educational purpose.

## Implementation

* [ ] Brute-force algorithm
* [x] Common backtracking algorithm
* [x] Warnsdorff's rule algorithm

## Outputs

There are several outputs available for each implementation.
The solution (output) is based on the Knight's legal `moves` sequence.
Each type of sequence will produces different solution.
The default moves is
`{(1, 2), (2, 1), (-1, 2), (1, -2), (-2, 1), (2, -1), (-2, -1), (-1, -2)}`
in the form of `(x, y)`.

As an example, from that sequence above, using the starting point at `(0, 0)`
on the 8x8 chessboard, the output will be:

```
 1  16  59  34   3  18  21  36
58  33   2  17  52  35   4  19
15  64  49  60  45  20  37  22
32  57  44  53  48  51  42   5
63  14  61  50  43  46  23  38
28  31  56  47  54  41   6   9
13  62  29  26  11   8  39  24
30  27  12  55  40  25  10   7
```

Then, if we change the sequence to
`{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}`
in the form of `(x, y)`, the output will be:

```
 1  34   3  18  49  32  13  16
 4  19  56  33  14  17  50  31
57   2  35  48  55  52  15  12
20   5  60  53  36  47  30  51
41  58  37  46  61  54  11  26
 6  21  42  59  38  27  64  29
43  40  23   8  45  62  25  10
22   7  44  39  24   9  28  63
```

#### How to generate the outputs?

First, edit the part of `n` variable which is denoting the chessboard.
As an example, edit it to this code below.

```c++
int n;
scanf("%d", &n);
```

Compile the source code into an executable file.
I assume that we using the \*NIX family operating system and `g++` compiler.

```bash
g++ implementation-name.cpp -std=c++11 -o exe
```

Then, using the command line (bash), write this command below.

```bash
for i in {1..100}
do
  ./exe <<< $i > output-path/algorithm-name-$i.out
  echo $1 " done."
done
```

Edit the `{1..100}` interval part as we needed.
Last, wait until its done.

### Brute-force Implementation

To be added.

### Common Backtracking Implementation

To be added.

### Warnsdorff's Rule Implementation

Since the file size is too huge, there are at least 50 outputs will be
included.

## Performance Comparison

Since 2x2, 3x3, and 4x4 doesn't have any solution, we skip them.

### Hardware Specifications

Tested on the ASUS A455L Notebook with the Intel Core i3-5005U 2GHz
and 4GB DDR3 RAM.

### Comparison Result

For each algorithm, the form of the result will be
`A (B, C)`
where
`A` is the first try success at the random starting point (seconds),
`B` is the number of success starting point(s),
and `C` is the number of fails starting point(s).
The fails starting point could be either timeout or no solution found.
The timeout limit is 20 seconds for each starting point.

| N (NxN) | Brute-force | Common Backtracking | Warnsdorff's Rule  |
|---------|-------------|---------------------|--------------------|
| 1       | TBA         | 0.00s (1, 0)        | 0.00s (1, 0)       |
| 5       | TBA         | 34.31s (13, 12)     | 0.00s (10, 15)     |
| 6       | TBA         | 285.19s (24, 12)    | 0.00s (36, 0)      |
| 7       | TBA         | TBA                 | 0.00s (20, 29)     |
| 8       | TBA         | TBA                 | 0.00s (63, 1)      |
| 9       | TBA         | TBA                 | 0.00s (41, 40)     |
| 10      | TBA         | TBA                 | 0.00s (100, 0)     |
| 11      | TBA         | TBA                 | 0.00s (59, 62)     |
| 12      | TBA         | TBA                 | 0.00s (141, 3)     |
| 13      | TBA         | TBA                 | 0.00s (84, 85)     |
| 14      | TBA         | TBA                 | 0.00s (192, 4)     |
| 15      | TBA         | TBA                 | 0.00s (113, 112)   |
| 16      | TBA         | TBA                 | 0.00s (254, 2)     |
| 17      | TBA         | TBA                 | 0.00s (144, 145)   |
| 18      | TBA         | TBA                 | 0.00s (317, 7)     |
| 19      | TBA         | TBA                 | 0.00s (178, 183)   |
| 20      | TBA         | TBA                 | 0.00s (395, 5)     |
| 21      | TBA         | TBA                 | 0.00s (216, 225)   |
| 22      | TBA         | TBA                 | 0.00s (478, 6)     |
| 23      | TBA         | TBA                 | 0.00s (263, 266)   |
| 24      | TBA         | TBA                 | 0.00s (566, 10)    |
| 25      | TBA         | TBA                 | 0.00s (310, 315)   |
| 26      | TBA         | TBA                 | 0.00s (658, 18)    |
| 27      | TBA         | TBA                 | 0.01s (356, 373)   |
| 28      | TBA         | TBA                 | 0.01s (774, 10)    |
| 29      | TBA         | TBA                 | 0.01s (417, 424)   |
| 30      | TBA         | TBA                 | 0.01s (849, 51)    |
| 31      | TBA         | TBA                 | 0.01s (480, 481)   |
| 32      | TBA         | TBA                 | 0.01s (975, 49)    |
| 33      | TBA         | TBA                 | 0.01s (537, 552)   |
| 34      | TBA         | TBA                 | 0.01s (1045, 111)  |
| 35      | TBA         | TBA                 | 0.01s (607, 618)   |
| 36      | TBA         | TBA                 | 0.01s (1248, 48)   |
| 37      | TBA         | TBA                 | 0.01s (673, 696)   |
| 38      | TBA         | TBA                 | 0.01s (1268, 176)  |
| 39      | TBA         | TBA                 | 0.01s (746, 775)   |
| 40      | TBA         | TBA                 | 0.01s (1530, 70)   |
| 41      | TBA         | TBA                 | 0.01s (829, 852)   |
| 42      | TBA         | TBA                 | 0.01s (1543, 221)  |
| 43      | TBA         | TBA                 | 0.01s (914, 935)   |
| 44      | TBA         | TBA                 | 0.01s (1852, 84)   |
| 45      | TBA         | TBA                 | 0.01s (968, 1057)  |
| 46      | TBA         | TBA                 | 0.02s (1778, 338)  |
| 47      | TBA         | TBA                 | 0.02s (1082, 1127) |
| 48      | TBA         | TBA                 | 0.02s (2204, 100)  |
| 49      | TBA         | TBA                 | 0.02s (1148, 1253) |
| 50      | TBA         | TBA                 | 0.02s (2116, 384)  |
| 51      | TBA         | TBA                 | 0.02s (1274, 1327) |
| 52      | TBA         | TBA                 | 0.02s (2587, 117)  |
| 53      | TBA         | TBA                 | 0.02s (1352, 1457) |
| 54      | TBA         | TBA                 | 0.02s (2405, 511)  |
| 55      | TBA         | TBA                 | 0.02s (1476, 1549) |
| 56      | TBA         | TBA                 | 0.02s (2972, 164)  |
| 57      | TBA         | TBA                 | 0.02s (1548, 1701) |
| 58      | TBA         | TBA                 | 0.03s (2791, 573)  |
| 59      | TBA         | TBA                 | 0.03s (1697, 1784) |
| 60      | TBA         | TBA                 | 0.03s (3448, 152)  |
| 61      | TBA         | TBA                 | 0.03s (1770, 1951) |
| 62      | TBA         | TBA                 | 0.03s (3143, 701)  |
| 63      | TBA         | TBA                 | 0.03s (1918, 2051) |
| 64      | TBA         | TBA                 | 0.03s (3874, 222)  |
| 65      | TBA         | TBA                 | 0.03s (2011, 2214) |
| 66      | TBA         | TBA                 | 0.03s (3480, 876)  |
| 67      | TBA         | TBA                 | 0.03s (2181, 2308) |
| 68      | TBA         | TBA                 | 0.04s (4414, 210)  |
| 69      | TBA         | TBA                 | 0.04s (2225, 2536) |
| 70      | TBA         | TBA                 | 0.04s (3877, 1023) |
| 71      | TBA         | TBA                 | 0.04s (2440, 2601) |
| 72      | TBA         | TBA                 | 0.04s (4921, 263)  |
| 73      | TBA         | TBA                 | 0.04s (2474, 2855) |
| 74      | TBA         | TBA                 | 0.04s (4265, 1211) |
| 75      | TBA         | TBA                 | 0.04s (2699, 2926) |
| 76      | TBA         | TBA                 | 0.04s (5506, 270)  |
| 77      | TBA         | TBA                 | 0.05s (2768, 3161) |
| 78      | TBA         | TBA                 | 0.05s (4828, 1256) |
| 79      | TBA         | TBA                 | 0.05s (3006, 3235) |
| 80      | TBA         | TBA                 | 0.05s (6091, 309)  |
| 81      | TBA         | TBA                 | 0.05s (3027, 3524) |
| 82      | TBA         | TBA                 | 0.05s (5192, 1532) |
| 83      | TBA         | TBA                 | 0.05s (3333, 3556) |
| 84      | TBA         | TBA                 | 0.05s (6655, 401)  |
| 85      | TBA         | TBA                 | 0.05s (3307, 3918) |
| 86      | TBA         | TBA                 | 0.05s (5717, 1679) |
| 87      | TBA         | TBA                 | 0.06s (3581, 3988) |
| 88      | TBA         | TBA                 | 0.06s (7352, 392)  |
| 89      | TBA         | TBA                 | 0.06s (3600, 4321) |
| 90      | TBA         | TBA                 | 0.06s (6163, 1937) |
| 91      | TBA         | TBA                 | 0.06s (4006, 4275) |
| 92      | TBA         | TBA                 | 0.06s (7972, 492)  |
| 93      | TBA         | TBA                 | 0.06s (3925, 4724) |
| 94      | TBA         | TBA                 | 0.07s (6730, 2106) |
| 95      | TBA         | TBA                 | 0.07s (4309, 4716) |
| 96      | TBA         | TBA                 | 0.07s (8721, 495)  |
| 97      | TBA         | TBA                 | 0.07s (4267, 5142) |
| 98      | TBA         | TBA                 | 0.07s (7337, 2272) |
| 99      | TBA         | TBA                 | 0.07s (4727, 5074) |
| 100     | TBA         | TBA                 | 0.07s (9503, 492)  |

### Conclusion

The Warnsdorff's Rule just took about 0.07s for finding a random solution
(in the first try) on the 100x100 chessboard.

## License

### Source Code License

Licensed under [The MIT License](LICENSE).
You could use the source code for whatever you want as long as the
`LICENSE` file or the license header in the source code still there.

### Documentation License

All reading materials from this repository is licensed under
[CC BY 4.0](https://creativecommons.org/licenses/by/4.0/).
You could use this repository as your reference as long as you
give the attribution.
