/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){

    int i, j, AddSize;
    int a[4] = {0}; // K 只有 5 位且 A 数组大小至少为 1
    int* newArr;

    i = ASize - 1;
    while(K != 0 && i >= 0){
        K = A[i] + K;
        A[i] = K % 10;
        K /= 10;
        i--;
    }
	
    // 如果 K == 0，说明没有进位问题且A数组大小够用
    if(K == 0){
        *returnSize = ASize;
        return A;
    }
	
    // A数组大小不够用，需要扩容
    // 我的思路是：先将多余的位从低位到高位存储在数组a中；然后malloc一个合适大小的数组，将a中的位按从高到低存储在新数组中，然后再将A中的位复制到新数组中
    i = 0;
    while(K != 0){
        a[i++] = K % 10;
        K /= 10;
    }

    AddSize = i;

    newArr = (int*)malloc(sizeof(int) * (AddSize + ASize));

    for(i = AddSize - 1, j = 0; i >= 0; i--, j++)
        newArr[j] = a[i];

    for(i = 0; i < ASize; i++, j++)
        newArr[j] = A[i];

    *returnSize = AddSize + ASize;

    return newArr;
}
