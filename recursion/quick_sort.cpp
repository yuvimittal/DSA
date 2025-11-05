#include <bits/stdc++.h>
using namespace std;


int insert(vector<int> arr, int start, int end){

	int pivot= arr[start];
	int i = start;
	int j=end;

    while(i < j) {

        // Move i right until arr[i] > pivot (wrong side)
        while(i <= end && arr[i] <= pivot) i++;

        // Move j left until arr[j] <= pivot (wrong side)
        while(j >= start && arr[j] > pivot) j--;

        // Swap wrong side elements
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Swap pivot into its correct position
    swap(arr[start], arr[j]);

    return j; 


}

void quickSort(vector<int> arr, int start, int end){

	//choose a pivot and elements less than that should be pushes to left
	//greater than that to right
	if(start<end){
		int pivot = insert(arr,start,end);
		quickSort(arr,start,pivot-1);
		quickSort(arr,pivot+1, end);
	}
}


int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    quickSort(arr, 0, arr.size() - 1);

    for(int x : arr) cout << x << " ";
    return 0;
}