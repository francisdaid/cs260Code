#include <iomanip>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

#include "Searches.h"


//low and high represent the
//returns location of value or -1 if not present
int recursiveBinarySearchHelper(int value, int arr[], int low, int high) {
    if(low >= 1) {
        int mid = (low + high) / 2;
        if(arr[mid] == value)
            return mid;
        if(arr[mid] > high)
            return recursiveBinarySearchHelper(value, arr, mid - 1, high);
        else
            return recursiveBinarySearchHelper(value, arr, mid + 1, high);
    }
    return -1; //TODO - fixme
}

//returns location of value or -1 if not present
int recursiveBinarySearch(int value, int arr[], int arrSize) {
    //pass off work to recursive helper function
    return recursiveBinarySearchHelper(value, arr, 0, arrSize - 1);
}

//returns location of value or -1 if not present
int binarySearch(int value, int arr[], int arrSize) {
    int low = 0, high = arrSize - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] > value) {
            high = mid - 1;
        }
        else if (arr[mid] < value) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

//pick number 1-1,000,000
int randomValue() {
    int thousands = rand() % 1000;
    int ones = rand() % 1000;
    return thousands * 1000 + ones;
}

//fill array with random values 0-999,999
void genNums(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++)
        arr[i] = randomValue();

    //Sort using std:: algorithm
    sort(arr,arr+arrSize);
}


