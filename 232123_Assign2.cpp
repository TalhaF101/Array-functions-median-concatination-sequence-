
#include <iostream>

using namespace std;

double findMedian(int arr[], int length) {  //fuction to find median
    // Sort the array in ascending order
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    } // end fuction find_med

    if (length % 2 == 0) {
        int mid1 = length / 2;
        int mid2 = mid1 - 1;
        return (arr[mid1] + arr[mid2]) / 2;
    }
    else {
        return arr[length / 2];
    }
}

void concatenateArrays(int arr1[], int arr2[], int result[], int length) {  //function to concatenate arrays
    for (int i = 0; i < length; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < length; i++) {
        result[length + i] = arr2[i];
    }
}  // end function Conc_arr

bool searchConsecutiveSequence(int arr[], int length, int target1, int target2) { //function consec_seq
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] == target1 && arr[i + 1] == target2) {
            return true;
        }
    }
    return false;
} // end functioneconsec_seq

int main() {
    int arr[10];

    while (true) {
        cout << "Please choose a command:" << endl;
        cout << "m: Find the median number in an array" << endl;
        cout << "c: Concatenate two arrays" << endl;
        cout << "s: Search for a consecutive sequence of two numbers in an array" << endl;
        cout << "e: Exit" << endl;
        char choice;

        cin >> choice;

        if (choice == 'e')
        {
            break;

        } // to break the loop

        switch (choice) {

        case 'm': //start case m
        {
            for (int i = 0; i < 10; ++i) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> arr[i];
            }
            double median = findMedian(arr, 10);
            cout << "The median of the array is: " << median << endl;
        } //end case m
        break;

        case 'c': //start case c
        {
            int arr1[10];
            int arr2[10];
            int concatenatedArray[20];
            for (int i = 0; i < 10; ++i) {
                cout << "Enter element " << i + 1 << " for the first array: ";
                cin >> arr1[i];
            }
            for (int i = 0; i < 10; ++i) {
                cout << "Enter element " << i + 1 << " for the second array: ";
                cin >> arr2[i];
            }
            concatenateArrays(arr1, arr2, concatenatedArray, 10);
            cout << "The concatenated array is: ";
            for (int i = 0; i < 20; ++i) {
                cout << concatenatedArray[i] << " ";
            
            }
            cout << endl;
        } //end case c
        break;

        case 's':  // start case s
        {
            for (int i = 0; i < 10; ++i) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> arr[i];
            }
            int target1, target2;
            cout << "Enter the first number in the consecutive sequence: ";
            cin >> target1;
            cout << "Enter the second number in the consecutive sequence: ";
            cin >> target2;
            bool isFound = searchConsecutiveSequence(arr, 10, target1, target2);
            if (isFound) {
                cout << "Consecutive sequence found in the array." << endl;
            }
            else {
                cout << "Consecutive sequence not found in the array." << endl;
            }
        } //end case s
        break;

        default:
            cout << "Invalid choice. Please select a valid option." << endl;

        } // end switch

    } // end while

    return 0;
}
