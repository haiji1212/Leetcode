#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 【1232】缀点成线
// 给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ， [x, y] 表示横坐标为 x、纵坐标为 y 的点。
// 请你来判断，这些点是否在该坐标系中属于同一条直线上。
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    if(coordinatesSize <= 2)    return true;
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];   
    for(int i = 2; i < coordinatesSize; i ++){
        int xi = coordinates[i][0];
        int yi = coordinates[i][1];
        if((yi - y0) * (x1 - x0) != (y1 - y0) * (xi - x0))
            return false;
    }
    return true;
}
