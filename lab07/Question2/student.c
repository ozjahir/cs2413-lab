/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/
void merge(int a[], int l, int mid, int h){
    int i ,j,k;
    i=l;
    j=mid +1;
    k=l;
    int B[100];

    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            B[k++] = a[i++];
        } else {
            B[k++]= a[j++];
        }
    }
    for(;i<=mid; i++){
        B[k++]=a[i];
    }

    for(;j<=h; j++){
        B[k++] = a[j];
    }

    for(int i=l; i<=h;i++){
        a[i]=B[i];
    }
}

void mergeSortHelper(int arr[], int left, int right) {
    if(left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void mergeSort(int arr[], int size) {
    // TODO: implement merge sort
    (void)arr;
    (void)size;

    if(size <=1){
        return;
    }
    mergeSortHelper(arr, 0, size-1);
}

