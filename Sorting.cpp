#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;


class Sorting{
    public:
        void BubbleSort(double arr[], int n);
        void SelectionSort(double arr[], int n);
        void InsertionSort(double arr[], int n);
        int partition(double a[],int start,int end);
        void Quicksort(double a[],int start,int end);

};

int main(int argc, char const *argv[]) {
    Sorting sorter;
    ifstream inFile;
    ofstream outFile;
    string line = " ";
    bool firstLine = true;
    int size;
    int countIndex = 0;
    // outFile.open("michaelkulinich.txt");
    // outFile << 10000 << endl;
    // for(int i = 0; i < 10000; i++){
    //     outFile << static_cast <float> (rand()) / static_cast <float> (RAND_MAX) << endl;
    // }
    // outFile.close();

    inFile.open(argv[1]);
    if (!inFile) {
        cout << "Unable to open file " << argv[1];
        exit(1);   // call system to stop
    }
     //read fileName in and grab the first line in order to set the array size
    while(inFile >> line)
    {
        if(firstLine == true)
        {
            //converts string to integer
            size = stoi(line);
            firstLine = false;
            break;
        }
    }


    double bubbleArray[size];
    double quickArray[size];
    double insertArray[size];
    double selectionArray[size];

    for(int i = 0; i < size; ++i){
        bubbleArray[i] = 0;
        quickArray[i] = 0;
        insertArray[i] = 0;
        selectionArray[i] = 0;
    }

    while(inFile >> line){
        bubbleArray[countIndex] = stod(line);
        quickArray[countIndex] = stod(line);
        insertArray[countIndex] = stod(line);
        selectionArray[countIndex] = stod(line);
        countIndex++;
    }

        inFile.close();


    clock_t bubbleBegin = clock();
    sorter.BubbleSort(bubbleArray, size);
    clock_t bubbleEnd = clock();
    double timeSec = double(bubbleEnd - bubbleBegin) / CLOCKS_PER_SEC;
    cout <<"bubble Time " << timeSec << " "<< endl;

    clock_t insertBegin = clock();
    sorter.InsertionSort(insertArray, size);
    clock_t insertEnd = clock();
    timeSec = double(insertEnd - insertBegin) / CLOCKS_PER_SEC;
    cout <<"insert Time " << timeSec << " "<< endl;

    clock_t selectBegin = clock();
    sorter.SelectionSort(selectionArray, size);
    clock_t selectEnd = clock();
    timeSec = double(selectEnd - selectBegin) / CLOCKS_PER_SEC;
    cout <<"select Time " << timeSec << " "<< endl;

    clock_t quickBegin = clock();
    sorter.Quicksort(quickArray, 0, size - 1);
    clock_t quickEnd = clock();

    timeSec = double(quickEnd - quickBegin) / CLOCKS_PER_SEC;
    cout <<"quick Time " << timeSec << " "<< endl;



    return 0;
}


void Sorting::BubbleSort(double arr[], int n){
    double temp;
    for(int i = 0; i < n; ++i){
        temp = 0.0;
        for (int j = 0; j < n-1; ++j) {
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Sorting::SelectionSort(double arr[], int n){
    int minIndex;
    double temp;
    for (int i = 0; i < n-1; i++)
    {
      // Find the minimum element in unsorted array
        minIndex = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if(minIndex != i){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

}

void Sorting::InsertionSort(double arr[], int n){
    double temp;
    int j;
    for (int i = 1; i < n; ++i)
    {
        temp = arr[i];
        j = i - 1;
            /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            --j;
        }
       arr[j + 1] = temp;
    }

}




int Sorting::partition(double a[],int start,int end)
{
    double pivot = a[end];
    //P-index indicates the pivot value index

    int P_index = start;
    int i;
    double t; //t is temporary variable

    //Here we will check if array value is
    //less than pivot
    //then we will place it at left side
    //by swapping

    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=a[end];
      a[end]=a[P_index];
      a[P_index]=t;

     //at last returning the pivot value index
     return P_index;
 }
 void Sorting::Quicksort(double a[],int start,int end)
 {
    if(start<end)
    {
         int P_index=partition(a,start,end);
             Quicksort(a,start,P_index-1);
             Quicksort(a,P_index+1,end);
    }
}
//https://appdividend.com/2019/05/02/quick-sort-in-c-tutorial-with-example-c-quick-sort-program/
