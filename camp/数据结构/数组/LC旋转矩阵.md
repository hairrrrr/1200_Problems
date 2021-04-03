---
tags: 矩阵 数组
---



#### [面试题 01.07. 旋转矩阵](https://leetcode-cn.com/problems/rotate-matrix-lcci/)



给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 ```
示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 ```



```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& a) 
    {
        int n = a.size();

        // 按行翻转
        for(int i = 0; i < n / 2; ++i)
            for(int j = 0; j < n; ++j)
                swap(a[i][j], a[n - i - 1][j]);

        // 按主对角线翻转
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j)
                swap(a[i][j], a[j][i]);
    }
};
```



