# NATlibc (n-ary trees)

A tiny standalone library for trees in C.

- Zero-dependency
- Extensively documented
- < 1000 SLOC


|Progress   |Module                 |Header file                    |
|-----------|-----------------------|-------------------------------|
|✅         |Records                | [record.h](./record.h)        |
|🚧         |Binary trees           | [bt.h](./bt/bt.h)             |
|🚧         |Binary search trees    | [bst.h](./bt/bst/bst.h)       |
|❌         |AVL trees              | [avl.h](./bt/bst/avl/avl.h)   |
|❌         |N-ary trees            | -                             |
|❌         |Common binary tree algorithms      | -                             |


## Install

```bash
# clone repo
git clone https://github.com/Infinitifall/n-ary-trees
cd n-ary-trees

# make
cd build
make
```

## Use

Run the code in [example.c](./example.c), which defines a small tree and prints it

```bash
# run example
cd build
./example
```

```
Note: node 0 at 0x55bb67ced4b0 has no parents, setting as root node.

|      |      |______3,33
|      |______2,7
|______1,5
0,2
|      |______5,8
|______4,19
|      |      |______7,11
|      |______6,9
|      |      |______8,14

3: 33
2: 7
1: 5
0: 2
5: 8
4: 19
7: 11
6: 9
8: 14
```
